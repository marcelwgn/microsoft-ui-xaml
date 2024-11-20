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

#include "ContentDialogButtonClickDeferral.g.h"

#define __ContentDialogButtonClickEventArgs_GUID "2285d599-0188-4d91-8a57-a1fdd488219c"

namespace DirectUI
{
    class ContentDialogButtonClickEventArgs;

    class __declspec(novtable) ContentDialogButtonClickEventArgsGenerated :
        public ABI::Microsoft::UI::Xaml::Controls::IContentDialogButtonClickEventArgs,
        public DirectUI::EventArgs
    {
        friend class DirectUI::ContentDialogButtonClickEventArgs;

        INSPECTABLE_CLASS(L"Microsoft.UI.Xaml.Controls.ContentDialogButtonClickEventArgs");

        BEGIN_INTERFACE_MAP(ContentDialogButtonClickEventArgsGenerated, DirectUI::EventArgs)
            INTERFACE_ENTRY(ContentDialogButtonClickEventArgsGenerated, ABI::Microsoft::UI::Xaml::Controls::IContentDialogButtonClickEventArgs)
        END_INTERFACE_MAP(ContentDialogButtonClickEventArgsGenerated, DirectUI::EventArgs)

    public:
        ContentDialogButtonClickEventArgsGenerated();
        ~ContentDialogButtonClickEventArgsGenerated() override;

        // Properties.
        IFACEMETHOD(get_Cancel)(_Out_ BOOLEAN* pValue) override;
        IFACEMETHOD(put_Cancel)(_In_ BOOLEAN value) override;

        // Methods.
        IFACEMETHOD(GetDeferral)(_Outptr_ ABI::Microsoft::UI::Xaml::Controls::IContentDialogButtonClickDeferral** ppReturnValue) override;

    protected:
        HRESULT QueryInterfaceImpl(_In_ REFIID iid, _Outptr_ void** ppObject) override;

    private:

        // Fields.
        BOOLEAN m_cancel;
    };
}

#include "ContentDialogButtonClickEventArgs_Partial.h"
