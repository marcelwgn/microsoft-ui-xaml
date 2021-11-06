﻿// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

#include "pch.h"
#include "common.h"
#include "TabView.h"
#include "TabViewItem.h"
#include "RuntimeProfiler.h"
#include "ResourceAccessor.h"
#include "XamlControlsResources.h"
#include "SharedHelpers.h"

static constexpr auto c_overlayCornerRadiusKey = L"OverlayCornerRadius"sv;

TabViewItem::TabViewItem()
{
    __RP_Marker_ClassById(RuntimeProfiler::ProfId_TabViewItem);

    SetDefaultStyleKey(this);

    SetValue(s_TabViewTemplateSettingsProperty, winrt::make<TabViewItemTemplateSettings>());

    Loaded({ this, &TabViewItem::OnLoaded });

    RegisterPropertyChangedCallback(winrt::SelectorItem::IsSelectedProperty(), { this, &TabViewItem::OnIsSelectedPropertyChanged });
    RegisterPropertyChangedCallback(winrt::Control::ForegroundProperty(), { this, &TabViewItem::OnForegroundPropertyChanged });
}

void TabViewItem::OnApplyTemplate()
{
    auto popupRadius = unbox_value<winrt::CornerRadius>(ResourceAccessor::ResourceLookup(*this, box_value(c_overlayCornerRadiusKey)));

    winrt::IControlProtected controlProtected{ *this };

    m_headerContentPresenter.set(GetTemplateChildT<winrt::ContentPresenter>(L"ContentPresenter", controlProtected));

    auto tabView = SharedHelpers::GetAncestorOfType<winrt::TabView>(winrt::VisualTreeHelper::GetParent(*this));
    auto internalTabView = tabView
        ? winrt::get_self<TabView>(tabView)
        : nullptr;

    m_closeButton.set([this, controlProtected, internalTabView]() {
        auto closeButton = GetTemplateChildT<winrt::Button>(L"CloseButton", controlProtected);
        if (closeButton)
        {
            // Do localization for the close button automation name
            if (winrt::AutomationProperties::GetName(closeButton).empty())
            {
                auto const closeButtonName = ResourceAccessor::GetLocalizedStringResource(SR_TabViewCloseButtonName);
                winrt::AutomationProperties::SetName(closeButton, closeButtonName);
            }

            if (internalTabView)
            {
                // Setup the tooltip for the close button
                auto tooltip = winrt::ToolTip();
                tooltip.Content(box_value(internalTabView->GetTabCloseButtonTooltipText()));
                winrt::ToolTipService::SetToolTip(closeButton, tooltip);
            }

            m_closeButtonClickRevoker = closeButton.Click(winrt::auto_revoke, { this, &TabViewItem::OnCloseButtonClick });
        }
        return closeButton;
        }());

    OnHeaderChanged();
    OnIconSourceChanged();

    if (tabView)
    {
        if (SharedHelpers::IsThemeShadowAvailable())
        {
            if (internalTabView)
            {
                winrt::ThemeShadow shadow;
                if (!SharedHelpers::Is21H1OrHigher())
                {
                    if (auto shadowReceiver = internalTabView->GetShadowReceiver())
                    {
                        shadow.Receivers().Append(shadowReceiver);
                    }
                }
                m_shadow = shadow;

                double shadowDepth = unbox_value<double>(SharedHelpers::FindInApplicationResources(c_tabViewShadowDepthName, box_value(c_tabShadowDepth)));

                const auto currentTranslation = Translation();
                const auto translation = winrt::float3{ currentTranslation.x, currentTranslation.y, (float)shadowDepth };
                Translation(translation);

                UpdateShadow();
            }
        }
        m_tabDragStartingRevoker = tabView.TabDragStarting(winrt::auto_revoke, { this, &TabViewItem::OnTabDragStarting });
        m_tabDragCompletedRevoker = tabView.TabDragCompleted(winrt::auto_revoke, { this, &TabViewItem::OnTabDragCompleted });
    }

    UpdateCloseButton();
    UpdateForeground();
    UpdateWidthModeVisualState();    
}

void TabViewItem::OnLoaded(const winrt::IInspectable& sender, const winrt::RoutedEventArgs& args)
{
    if (const auto tabView = GetParentTabView())
    {
        const auto internalTabView = winrt::get_self<TabView>(tabView);
        const auto index = internalTabView->IndexFromContainer(*this);
        internalTabView->SetTabSeparatorOpacity(index);
    }
}

void TabViewItem::OnIsSelectedPropertyChanged(const winrt::DependencyObject& sender, const winrt::DependencyProperty& args)
{
    
    if (const auto peer = winrt::FrameworkElementAutomationPeer::CreatePeerForElement(*this))
    {
        peer.RaiseAutomationEvent(winrt::AutomationEvents::SelectionItemPatternOnElementSelected);
    }

    if (IsSelected())
    {
        SetValue(winrt::Canvas::ZIndexProperty(), box_value(20));
        StartBringIntoView();
    }
    else
    {
        SetValue(winrt::Canvas::ZIndexProperty(), box_value(0));
    }

    UpdateShadow();
    UpdateWidthModeVisualState();

    UpdateCloseButton();
    UpdateForeground();
}

void TabViewItem::OnForegroundPropertyChanged(const winrt::DependencyObject&, const winrt::DependencyProperty&)
{
    UpdateForeground();
}

void TabViewItem::UpdateForeground()
{
    // We only need to set the foreground state when the TabViewItem is in rest state and not selected.
    if (!IsSelected() && !m_isPointerOver)
    {
        // If Foreground is set, then change icon and header foreground to match.
        winrt::VisualStateManager::GoToState(
            *this,
            ReadLocalValue(winrt::Control::ForegroundProperty()) == winrt::DependencyProperty::UnsetValue() ? L"ForegroundNotSet" : L"ForegroundSet",
            false /*useTransitions*/);
    }
}

void TabViewItem::UpdateShadow()
{
    
    if (SharedHelpers::IsThemeShadowAvailable() && !XamlControlsResources::IsUsingControlsResourcesVersion2())
    {
        if (IsSelected() && !m_isDragging )
        {
            Shadow(m_shadow.as<winrt::ThemeShadow>());
        }
        else
        {
            Shadow(nullptr);
        }
    }
}


void TabViewItem::OnTabDragStarting(const winrt::IInspectable& sender, const winrt::TabViewTabDragStartingEventArgs& args)
{
    m_isDragging = true;
    UpdateShadow();
}

void TabViewItem::OnTabDragCompleted(const winrt::IInspectable& sender, const winrt::TabViewTabDragCompletedEventArgs& args)
{
    m_isDragging = false;
    UpdateShadow();
    UpdateForeground();
}

winrt::AutomationPeer TabViewItem::OnCreateAutomationPeer()
{
    return winrt::make<TabViewItemAutomationPeer>(*this);
}

void TabViewItem::OnCloseButtonOverlayModeChanged(winrt::TabViewCloseButtonOverlayMode const& mode)
{
    m_closeButtonOverlayMode = mode;
    UpdateCloseButton();
}

winrt::TabView TabViewItem::GetParentTabView()
{
    return m_parentTabView.get();
}

void TabViewItem::SetParentTabView(winrt::TabView const& tabView)
{
    m_parentTabView = winrt::make_weak(tabView);
}

void TabViewItem::OnTabViewWidthModeChanged(winrt::TabViewWidthMode const& mode)
{
    m_tabViewWidthMode = mode;
    UpdateWidthModeVisualState();
}

void TabViewItem::UpdateCloseButton()
{
    if (!IsClosable())
    {
        winrt::VisualStateManager::GoToState(*this, L"CloseButtonCollapsed", false);
    }
    else
    {
        switch (m_closeButtonOverlayMode)
        {
        case winrt::TabViewCloseButtonOverlayMode::OnPointerOver:
        {
            // If we only want to show the button on hover, we also show it when we are selected, otherwise hide it
            if (IsSelected() || m_isPointerOver)
            {
                winrt::VisualStateManager::GoToState(*this, L"CloseButtonVisible", false);
            }
            else
            {
                winrt::VisualStateManager::GoToState(*this, L"CloseButtonCollapsed", false);
            }
            break;
        }
        default:
        {
            // Default, use "Auto"
            winrt::VisualStateManager::GoToState(*this, L"CloseButtonVisible", false);
            break;
        }
        }
    }
}

void TabViewItem::UpdateWidthModeVisualState()
{
    // Handling compact/non compact width mode
    if (!IsSelected() && m_tabViewWidthMode == winrt::TabViewWidthMode::Compact)
    {
        winrt::VisualStateManager::GoToState(*this, L"Compact", false);
    }
    else
    {
        winrt::VisualStateManager::GoToState(*this, L"StandardWidth", false);
    }
}

void TabViewItem::RequestClose()
{
    if (auto tabView = SharedHelpers::GetAncestorOfType<winrt::TabView>(winrt::VisualTreeHelper::GetParent(*this)))
    {
        if (auto internalTabView = winrt::get_self<TabView>(tabView))
        {
            internalTabView->RequestCloseTab(*this, false);
        }
    }
}

void TabViewItem::RaiseRequestClose(TabViewTabCloseRequestedEventArgs const& args)
{
    // This should only be called from TabView, to ensure that both this event and the TabView TabRequestedClose event are raised
    m_closeRequestedEventSource(*this, args);
}

void TabViewItem::OnCloseButtonClick(const winrt::IInspectable&, const winrt::RoutedEventArgs&)
{
    RequestClose();
}

void TabViewItem::OnIsClosablePropertyChanged(const winrt::DependencyPropertyChangedEventArgs&)
{
    UpdateCloseButton();
}

void TabViewItem::OnHeaderPropertyChanged(const winrt::DependencyPropertyChangedEventArgs& args)
{
    OnHeaderChanged();
}

void TabViewItem::OnHeaderChanged()
{
    if (const auto headerContentPresenter = m_headerContentPresenter.get())
    {
        headerContentPresenter.Content(Header());
    }

    if (m_firstTimeSettingToolTip)
    {
        m_firstTimeSettingToolTip = false;

        if (!winrt::ToolTipService::GetToolTip(*this))
        {
            // App author has not specified a tooltip; use our own
            m_toolTip.set([this]() {
                auto toolTip = winrt::ToolTip();
                toolTip.Placement(winrt::Controls::Primitives::PlacementMode::Mouse);
                winrt::ToolTipService::SetToolTip(*this, toolTip);
                return toolTip;
                }());
        }
    }

    if (auto&& toolTip = m_toolTip.get())
    {
        // Update tooltip text to new header text
        auto headerContent = Header();
        auto potentialString = headerContent.try_as<winrt::IPropertyValue>();

        // Only show tooltip if header is a non-empty string.
        if (potentialString && potentialString.Type() == winrt::PropertyType::String && !potentialString.GetString().empty())
        {
            toolTip.Content(headerContent);
            toolTip.IsEnabled(true);
        }
        else
        {
            toolTip.Content(nullptr);
            toolTip.IsEnabled(false);
        }
    }
}

void TabViewItem::OnPointerPressed(winrt::PointerRoutedEventArgs const& args)
{
    if (IsSelected() && args.Pointer().PointerDeviceType() == winrt::PointerDeviceType::Mouse)
    {
        auto pointerPoint = args.GetCurrentPoint(*this);
        if (pointerPoint.Properties().IsLeftButtonPressed())
        {
            auto isCtrlDown = (winrt::Window::Current().CoreWindow().GetKeyState(winrt::VirtualKey::Control) & winrt::CoreVirtualKeyStates::Down) == winrt::CoreVirtualKeyStates::Down;
            if (isCtrlDown)
            {
                // Return here so the base class will not pick it up, but let it remain unhandled so someone else could handle it.
                return;
            }
        }
    }

    __super::OnPointerPressed(args);

    if (args.GetCurrentPoint(nullptr).Properties().PointerUpdateKind() == winrt::PointerUpdateKind::MiddleButtonPressed)
    {
        if (CapturePointer(args.Pointer()))
        {
            m_hasPointerCapture = true;
            m_isMiddlePointerButtonPressed = true;
        }
    }
}

void TabViewItem::OnPointerReleased(winrt::PointerRoutedEventArgs const& args)
{
    __super::OnPointerReleased(args);

    if (m_hasPointerCapture)
    {
        if (args.GetCurrentPoint(nullptr).Properties().PointerUpdateKind() == winrt::PointerUpdateKind::MiddleButtonReleased)
        {
            const bool wasPressed = m_isMiddlePointerButtonPressed;
            m_isMiddlePointerButtonPressed = false;
            ReleasePointerCapture(args.Pointer());

            if (wasPressed)
            {
                if (IsClosable())
                {
                    RequestClose();
                }
            }
        }
    }
}

void TabViewItem::HideLeftAdjacentTabSeparator()
{
    if (const auto tabView = GetParentTabView())
    {
        const auto internalTabView = winrt::get_self<TabView>(tabView);
        const auto index = internalTabView->IndexFromContainer(*this);
        internalTabView->SetTabSeparatorOpacity(index - 1, 0);
    }

}

void TabViewItem::RestoreLeftAdjacentTabSeparatorVisibility()
{
    if (const auto tabView = GetParentTabView())
    {
        const auto internalTabView = winrt::get_self<TabView>(tabView);
        const auto index = internalTabView->IndexFromContainer(*this);
        internalTabView->SetTabSeparatorOpacity(index - 1);
    }
}

void TabViewItem::OnPointerEntered(winrt::PointerRoutedEventArgs const& args)
{
    __super::OnPointerEntered(args);

    m_isPointerOver = true;

    if (m_hasPointerCapture)
    {
        m_isMiddlePointerButtonPressed = true;
    }

    UpdateCloseButton();
    HideLeftAdjacentTabSeparator();
}

void TabViewItem::OnPointerExited(winrt::PointerRoutedEventArgs const& args)
{
    __super::OnPointerExited(args);

    m_isPointerOver = false;
    m_isMiddlePointerButtonPressed = false;

    UpdateCloseButton();
    UpdateForeground();
    RestoreLeftAdjacentTabSeparatorVisibility();
}

void TabViewItem::OnPointerCanceled(winrt::PointerRoutedEventArgs const& args)
{
    __super::OnPointerCanceled(args);

    if (m_hasPointerCapture)
    {
        ReleasePointerCapture(args.Pointer());
        m_isMiddlePointerButtonPressed = false;
    }
    RestoreLeftAdjacentTabSeparatorVisibility();

}

void TabViewItem::OnPointerCaptureLost(winrt::PointerRoutedEventArgs const& args)
{
    __super::OnPointerCaptureLost(args);

    m_hasPointerCapture = false;
    m_isMiddlePointerButtonPressed = false;
    RestoreLeftAdjacentTabSeparatorVisibility();
}

void TabViewItem::OnIconSourcePropertyChanged(const winrt::DependencyPropertyChangedEventArgs& args)
{
    OnIconSourceChanged();
}

void TabViewItem::OnIconSourceChanged()
{
    auto const templateSettings = winrt::get_self<TabViewItemTemplateSettings>(TabViewTemplateSettings());
    if (auto const source = IconSource())
    {
        templateSettings->IconElement(SharedHelpers::MakeIconElementFrom(source));
        winrt::VisualStateManager::GoToState(*this, L"Icon"sv, false);
    }
    else
    {
        templateSettings->IconElement(nullptr);
        winrt::VisualStateManager::GoToState(*this, L"NoIcon"sv, false);
    }
}
