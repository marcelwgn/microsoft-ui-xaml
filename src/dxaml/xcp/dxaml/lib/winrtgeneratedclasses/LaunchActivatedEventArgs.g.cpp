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

#include "LaunchActivatedEventArgs.g.h"
#include "XamlTelemetry.h"

// Constructors/destructors.
DirectUI::LaunchActivatedEventArgs::LaunchActivatedEventArgs()
{
}

DirectUI::LaunchActivatedEventArgs::~LaunchActivatedEventArgs()
{
}

HRESULT DirectUI::LaunchActivatedEventArgs::QueryInterfaceImpl(_In_ REFIID iid, _Outptr_ void** ppObject)
{
    if (InlineIsEqualGUID(iid, __uuidof(DirectUI::LaunchActivatedEventArgs)))
    {
        *ppObject = static_cast<DirectUI::LaunchActivatedEventArgs*>(this);
    }
    else if (InlineIsEqualGUID(iid, __uuidof(ABI::Microsoft::UI::Xaml::ILaunchActivatedEventArgs)))
    {
        *ppObject = static_cast<ABI::Microsoft::UI::Xaml::ILaunchActivatedEventArgs*>(this);
    }
    else
    {
        RRETURN(ctl::WeakReferenceSource::QueryInterfaceImpl(iid, ppObject));
    }

    AddRefOuter();
    RRETURN(S_OK);
}

// Properties.
IFACEMETHODIMP DirectUI::LaunchActivatedEventArgs::get_Arguments(_Out_ HSTRING* pValue)
{
    HRESULT hr = S_OK;
    ARG_VALIDRETURNPOINTER(pValue);
    IFC(CheckThread());
    IFC(m_arguments.CopyTo(pValue));
Cleanup:
    RRETURN(hr);
}
_Check_return_ HRESULT DirectUI::LaunchActivatedEventArgs::put_Arguments(_In_opt_ HSTRING value)
{
    HRESULT hr = S_OK;
    IFC(CheckThread());
    IFC(m_arguments.Set(value));
Cleanup:
    RRETURN(hr);
}
IFACEMETHODIMP DirectUI::LaunchActivatedEventArgs::get_UWPLaunchActivatedEventArgs(_Outptr_result_maybenull_ ABI::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs** ppValue)
{
    HRESULT hr = S_OK;
    ARG_VALIDRETURNPOINTER(ppValue);
    IFC(CheckThread());
    IFC(m_pUWPLaunchActivatedEventArgs.CopyTo(ppValue));
Cleanup:
    RRETURN(hr);
}
_Check_return_ HRESULT DirectUI::LaunchActivatedEventArgs::put_UWPLaunchActivatedEventArgs(_In_opt_ ABI::Windows::ApplicationModel::Activation::ILaunchActivatedEventArgs* pValue)
{
    HRESULT hr = S_OK;
    IFC(CheckThread());
    SetPtrValue(m_pUWPLaunchActivatedEventArgs, pValue);
Cleanup:
    RRETURN(hr);
}

// Events.

// Methods.


namespace DirectUI
{
    _Check_return_ IActivationFactory* CreateActivationFactory_LaunchActivatedEventArgs()
    {
        RRETURN(ctl::ActivationFactoryCreator<ctl::AbstractActivationFactory>::CreateActivationFactory());
    }
}