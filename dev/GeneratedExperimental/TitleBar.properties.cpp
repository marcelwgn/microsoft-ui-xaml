// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

// DO NOT EDIT! This file was generated by CustomTasks.DependencyPropertyCodeGen
#include "pch.h"
#include "common.h"
#include "TitleBar.h"

namespace winrt::Microsoft::Experimental::UI::Xaml::Controls
{
    CppWinRTActivatableClassWithDPFactory(TitleBar)
}

#include "TitleBar.g.cpp"

GlobalDependencyProperty TitleBarProperties::s_CustomContentProperty{ nullptr };
GlobalDependencyProperty TitleBarProperties::s_IconSourceProperty{ nullptr };
GlobalDependencyProperty TitleBarProperties::s_IsBackButtonVisibleProperty{ nullptr };
GlobalDependencyProperty TitleBarProperties::s_IsBackEnabledProperty{ nullptr };
GlobalDependencyProperty TitleBarProperties::s_TemplateSettingsProperty{ nullptr };
GlobalDependencyProperty TitleBarProperties::s_TitleProperty{ nullptr };

TitleBarProperties::TitleBarProperties()
    : m_backRequestedEventSource{static_cast<TitleBar*>(this)}
{
    EnsureProperties();
}

void TitleBarProperties::EnsureProperties()
{
    if (!s_CustomContentProperty)
    {
        s_CustomContentProperty =
            InitializeDependencyProperty(
                L"CustomContent",
                winrt::name_of<winrt::IInspectable>(),
                winrt::name_of<winrt::TitleBar>(),
                false /* isAttached */,
                ValueHelper<winrt::IInspectable>::BoxedDefaultValue(),
                winrt::PropertyChangedCallback(&OnCustomContentPropertyChanged));
    }
    if (!s_IconSourceProperty)
    {
        s_IconSourceProperty =
            InitializeDependencyProperty(
                L"IconSource",
                winrt::name_of<winrt::IconSource>(),
                winrt::name_of<winrt::TitleBar>(),
                false /* isAttached */,
                ValueHelper<winrt::IconSource>::BoxedDefaultValue(),
                winrt::PropertyChangedCallback(&OnIconSourcePropertyChanged));
    }
    if (!s_IsBackButtonVisibleProperty)
    {
        s_IsBackButtonVisibleProperty =
            InitializeDependencyProperty(
                L"IsBackButtonVisible",
                winrt::name_of<bool>(),
                winrt::name_of<winrt::TitleBar>(),
                false /* isAttached */,
                ValueHelper<bool>::BoxedDefaultValue(),
                winrt::PropertyChangedCallback(&OnIsBackButtonVisiblePropertyChanged));
    }
    if (!s_IsBackEnabledProperty)
    {
        s_IsBackEnabledProperty =
            InitializeDependencyProperty(
                L"IsBackEnabled",
                winrt::name_of<bool>(),
                winrt::name_of<winrt::TitleBar>(),
                false /* isAttached */,
                ValueHelper<bool>::BoxedDefaultValue(),
                nullptr);
    }
    if (!s_TemplateSettingsProperty)
    {
        s_TemplateSettingsProperty =
            InitializeDependencyProperty(
                L"TemplateSettings",
                winrt::name_of<winrt::TitleBarTemplateSettings>(),
                winrt::name_of<winrt::TitleBar>(),
                false /* isAttached */,
                ValueHelper<winrt::TitleBarTemplateSettings>::BoxedDefaultValue(),
                nullptr);
    }
    if (!s_TitleProperty)
    {
        s_TitleProperty =
            InitializeDependencyProperty(
                L"Title",
                winrt::name_of<winrt::hstring>(),
                winrt::name_of<winrt::TitleBar>(),
                false /* isAttached */,
                ValueHelper<winrt::hstring>::BoxedDefaultValue(),
                winrt::PropertyChangedCallback(&OnTitlePropertyChanged));
    }
}

void TitleBarProperties::ClearProperties()
{
    s_CustomContentProperty = nullptr;
    s_IconSourceProperty = nullptr;
    s_IsBackButtonVisibleProperty = nullptr;
    s_IsBackEnabledProperty = nullptr;
    s_TemplateSettingsProperty = nullptr;
    s_TitleProperty = nullptr;
}

void TitleBarProperties::OnCustomContentPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::TitleBar>();
    winrt::get_self<TitleBar>(owner)->OnCustomContentPropertyChanged(args);
}

void TitleBarProperties::OnIconSourcePropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::TitleBar>();
    winrt::get_self<TitleBar>(owner)->OnIconSourcePropertyChanged(args);
}

void TitleBarProperties::OnIsBackButtonVisiblePropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::TitleBar>();
    winrt::get_self<TitleBar>(owner)->OnIsBackButtonVisiblePropertyChanged(args);
}

void TitleBarProperties::OnTitlePropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::TitleBar>();
    winrt::get_self<TitleBar>(owner)->OnTitlePropertyChanged(args);
}

void TitleBarProperties::CustomContent(winrt::IInspectable const& value)
{
    [[gsl::suppress(con)]]
    {
    static_cast<TitleBar*>(this)->SetValue(s_CustomContentProperty, ValueHelper<winrt::IInspectable>::BoxValueIfNecessary(value));
    }
}

winrt::IInspectable TitleBarProperties::CustomContent()
{
    return ValueHelper<winrt::IInspectable>::CastOrUnbox(static_cast<TitleBar*>(this)->GetValue(s_CustomContentProperty));
}

void TitleBarProperties::IconSource(winrt::IconSource const& value)
{
    [[gsl::suppress(con)]]
    {
    static_cast<TitleBar*>(this)->SetValue(s_IconSourceProperty, ValueHelper<winrt::IconSource>::BoxValueIfNecessary(value));
    }
}

winrt::IconSource TitleBarProperties::IconSource()
{
    return ValueHelper<winrt::IconSource>::CastOrUnbox(static_cast<TitleBar*>(this)->GetValue(s_IconSourceProperty));
}

void TitleBarProperties::IsBackButtonVisible(bool value)
{
    [[gsl::suppress(con)]]
    {
    static_cast<TitleBar*>(this)->SetValue(s_IsBackButtonVisibleProperty, ValueHelper<bool>::BoxValueIfNecessary(value));
    }
}

bool TitleBarProperties::IsBackButtonVisible()
{
    return ValueHelper<bool>::CastOrUnbox(static_cast<TitleBar*>(this)->GetValue(s_IsBackButtonVisibleProperty));
}

void TitleBarProperties::IsBackEnabled(bool value)
{
    [[gsl::suppress(con)]]
    {
    static_cast<TitleBar*>(this)->SetValue(s_IsBackEnabledProperty, ValueHelper<bool>::BoxValueIfNecessary(value));
    }
}

bool TitleBarProperties::IsBackEnabled()
{
    return ValueHelper<bool>::CastOrUnbox(static_cast<TitleBar*>(this)->GetValue(s_IsBackEnabledProperty));
}

void TitleBarProperties::TemplateSettings(winrt::TitleBarTemplateSettings const& value)
{
    [[gsl::suppress(con)]]
    {
    static_cast<TitleBar*>(this)->SetValue(s_TemplateSettingsProperty, ValueHelper<winrt::TitleBarTemplateSettings>::BoxValueIfNecessary(value));
    }
}

winrt::TitleBarTemplateSettings TitleBarProperties::TemplateSettings()
{
    return ValueHelper<winrt::TitleBarTemplateSettings>::CastOrUnbox(static_cast<TitleBar*>(this)->GetValue(s_TemplateSettingsProperty));
}

void TitleBarProperties::Title(winrt::hstring const& value)
{
    [[gsl::suppress(con)]]
    {
    static_cast<TitleBar*>(this)->SetValue(s_TitleProperty, ValueHelper<winrt::hstring>::BoxValueIfNecessary(value));
    }
}

winrt::hstring TitleBarProperties::Title()
{
    return ValueHelper<winrt::hstring>::CastOrUnbox(static_cast<TitleBar*>(this)->GetValue(s_TitleProperty));
}

winrt::event_token TitleBarProperties::BackRequested(winrt::TypedEventHandler<winrt::TitleBar, winrt::IInspectable> const& value)
{
    return m_backRequestedEventSource.add(value);
}

void TitleBarProperties::BackRequested(winrt::event_token const& token)
{
    m_backRequestedEventSource.remove(token);
}
