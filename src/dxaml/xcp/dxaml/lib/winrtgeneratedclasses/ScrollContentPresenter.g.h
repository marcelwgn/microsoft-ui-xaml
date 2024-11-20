// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.
//------------------------------------------------------------------------
//
//  Abstract:
//
//      XAML types.
//      NOTE: This file was generated by a tool.
//
//------------------------------------------------------------------------

#pragma once

#include "ContentPresenter.g.h"
#include "IScrollInfo.g.h"

#define __ScrollContentPresenter_GUID "0d51bece-96e7-4469-bdfe-6fbe071c3d7c"

namespace DirectUI
{
    class ScrollContentPresenter;
    class UIElement;

    class __declspec(novtable) ScrollContentPresenterGenerated:
        public DirectUI::ContentPresenter
        , public ABI::Microsoft::UI::Xaml::Controls::IScrollContentPresenter
        , public DirectUI::IScrollInfo
    {
        friend class DirectUI::ScrollContentPresenter;

        INSPECTABLE_CLASS(L"Microsoft.UI.Xaml.Controls.ScrollContentPresenter");

        BEGIN_INTERFACE_MAP(ScrollContentPresenterGenerated, DirectUI::ContentPresenter)
            INTERFACE_ENTRY(ScrollContentPresenterGenerated, ABI::Microsoft::UI::Xaml::Controls::IScrollContentPresenter)
            INTERFACE_ENTRY(ScrollContentPresenterGenerated, DirectUI::IScrollInfo)
        END_INTERFACE_MAP(ScrollContentPresenterGenerated, DirectUI::ContentPresenter)

    public:
        ScrollContentPresenterGenerated();
        ~ScrollContentPresenterGenerated() override;

        // Event source typedefs.

        KnownTypeIndex GetTypeIndex() const override
        {
            return KnownTypeIndex::ScrollContentPresenter;
        }

        static XCP_FORCEINLINE KnownTypeIndex GetTypeIndexStatic()
        {
            return KnownTypeIndex::ScrollContentPresenter;
        }

        // Properties.
        IFACEMETHOD(get_CanContentRenderOutsideBounds)(_Out_ BOOLEAN* pValue) override;
        IFACEMETHOD(put_CanContentRenderOutsideBounds)(_In_ BOOLEAN value) override;
        IFACEMETHOD(get_CanHorizontallyScroll)(_Out_ BOOLEAN* pValue) override;
        IFACEMETHOD(put_CanHorizontallyScroll)(_In_ BOOLEAN value) override;
        IFACEMETHOD(get_CanVerticallyScroll)(_Out_ BOOLEAN* pValue) override;
        IFACEMETHOD(put_CanVerticallyScroll)(_In_ BOOLEAN value) override;
        IFACEMETHOD(get_ExtentHeight)(_Out_ DOUBLE* pValue) override;
        IFACEMETHOD(get_ExtentWidth)(_Out_ DOUBLE* pValue) override;
        IFACEMETHOD(get_HorizontalOffset)(_Out_ DOUBLE* pValue) override;
        IFACEMETHOD(get_MinHorizontalOffset)(_Out_ DOUBLE* pValue) override;
        IFACEMETHOD(get_MinVerticalOffset)(_Out_ DOUBLE* pValue) override;
        IFACEMETHOD(get_ScrollOwner)(_Outptr_result_maybenull_ IInspectable** ppValue) override;
        IFACEMETHOD(put_ScrollOwner)(_In_opt_ IInspectable* pValue) override;
        IFACEMETHOD(get_SizesContentToTemplatedParent)(_Out_ BOOLEAN* pValue) override;
        IFACEMETHOD(put_SizesContentToTemplatedParent)(_In_ BOOLEAN value) override;
        IFACEMETHOD(get_VerticalOffset)(_Out_ DOUBLE* pValue) override;
        IFACEMETHOD(get_ViewportHeight)(_Out_ DOUBLE* pValue) override;
        IFACEMETHOD(get_ViewportWidth)(_Out_ DOUBLE* pValue) override;

        // Events.

        // Methods.
        IFACEMETHOD(LineDown)() override;
        IFACEMETHOD(LineLeft)() override;
        IFACEMETHOD(LineRight)() override;
        IFACEMETHOD(LineUp)() override;
        IFACEMETHOD(MakeVisible)(_In_ ABI::Microsoft::UI::Xaml::IUIElement* pVisual, _In_ ABI::Windows::Foundation::Rect rectangle, _Out_ ABI::Windows::Foundation::Rect* pReturnValue) override;
        IFACEMETHOD(MakeVisible)(_In_ ABI::Microsoft::UI::Xaml::IUIElement* pVisual, _In_ ABI::Windows::Foundation::Rect rectangle, _In_ BOOLEAN useAnimation, _In_ DOUBLE horizontalAlignmentRatio, _In_ DOUBLE verticalAlignmentRatio, _In_ DOUBLE offsetX, _In_ DOUBLE offsetY, _Out_ ABI::Windows::Foundation::Rect* pResultRectangle, _Out_ DOUBLE* pAppliedOffsetX, _Out_ DOUBLE* pAppliedOffsetY) override;
        IFACEMETHOD(MouseWheelDown)() override;
        IFACEMETHOD(MouseWheelDown)(_In_ UINT mouseWheelDelta) = 0;
        IFACEMETHOD(MouseWheelLeft)() override;
        IFACEMETHOD(MouseWheelLeft)(_In_ UINT mouseWheelDelta) = 0;
        IFACEMETHOD(MouseWheelRight)() override;
        IFACEMETHOD(MouseWheelRight)(_In_ UINT mouseWheelDelta) = 0;
        IFACEMETHOD(MouseWheelUp)() override;
        IFACEMETHOD(MouseWheelUp)(_In_ UINT mouseWheelDelta) = 0;
        IFACEMETHOD(PageDown)() override;
        IFACEMETHOD(PageLeft)() override;
        IFACEMETHOD(PageRight)() override;
        IFACEMETHOD(PageUp)() override;
        IFACEMETHOD(SetHorizontalOffset)(_In_ DOUBLE offset) override;
        IFACEMETHOD(SetVerticalOffset)(_In_ DOUBLE offset) override;


    protected:
        HRESULT QueryInterfaceImpl(_In_ REFIID iid, _Outptr_ void** ppObject) override;

    private:

        // Fields.
    };
}

#include "ScrollContentPresenter_Partial.h"

namespace DirectUI
{
    // Note that the ordering of the base types here is important - the base factory comes first, followed by all the
    // interfaces specific to this type.  By doing this, we allow every Factory's CreateInstance method to be more
    // COMDAT-folding-friendly.  Because this ensures that the first vfptr contains GetTypeIndex, it means that all
    // CreateInstance functions with the same base factory generate the same assembly instructions and thus will
    // fold together.  This is significant for binary size in Microsoft.UI.Xaml.dll so change this only with great
    // care.
    class __declspec(novtable) ScrollContentPresenterFactory:
       public ctl::BetterCoreObjectActivationFactory
        , public ABI::Microsoft::UI::Xaml::Controls::IScrollContentPresenterStatics
    {
        BEGIN_INTERFACE_MAP(ScrollContentPresenterFactory, ctl::BetterCoreObjectActivationFactory)
            INTERFACE_ENTRY(ScrollContentPresenterFactory, ABI::Microsoft::UI::Xaml::Controls::IScrollContentPresenterStatics)
        END_INTERFACE_MAP(ScrollContentPresenterFactory, ctl::BetterCoreObjectActivationFactory)

    public:
        // Factory methods.

        // Static properties.

        // Dependency properties.
        IFACEMETHOD(get_CanContentRenderOutsideBoundsProperty)(_Out_ ABI::Microsoft::UI::Xaml::IDependencyProperty** ppValue) override;
        IFACEMETHOD(get_SizesContentToTemplatedParentProperty)(_Out_ ABI::Microsoft::UI::Xaml::IDependencyProperty** ppValue) override;

        // Attached properties.

        // Static methods.

        // Static events.

    protected:
        HRESULT QueryInterfaceImpl(_In_ REFIID iid, _Outptr_ void** ppObject) override;

        KnownTypeIndex GetTypeIndex() const override
        {
            return KnownTypeIndex::ScrollContentPresenter;
        }


    private:

        // Customized static properties.

        // Customized static  methods.
    };
}