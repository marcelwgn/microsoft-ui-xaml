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

#include "precomp.h"
#include "DragStartingEventArgs.g.h"
#include "CoreEventArgsGroup.h"

using namespace DirectUI;

// Constructors/destructors.
DirectUI::DragStartingEventArgsGenerated::DragStartingEventArgsGenerated(): m_cancel(), m_allowedOperations()
{
}

DirectUI::DragStartingEventArgsGenerated::~DragStartingEventArgsGenerated()
{
}

HRESULT DirectUI::DragStartingEventArgsGenerated::QueryInterfaceImpl(_In_ REFIID iid, _Outptr_ void** ppObject)
{
    if (InlineIsEqualGUID(iid, __uuidof(DirectUI::DragStartingEventArgs)))
    {
        *ppObject = static_cast<DirectUI::DragStartingEventArgs*>(this);
    }
    else if (InlineIsEqualGUID(iid, __uuidof(ABI::Microsoft::UI::Xaml::IDragStartingEventArgs)))
    {
        *ppObject = static_cast<ABI::Microsoft::UI::Xaml::IDragStartingEventArgs*>(this);
    }
    else if (InlineIsEqualGUID(iid, __uuidof(DirectUI::IDragOperationDeferralTarget)))
    {
        *ppObject = static_cast<DirectUI::IDragOperationDeferralTarget*>(this);
    }
    else
    {
        RRETURN(DirectUI::RoutedEventArgs::QueryInterfaceImpl(iid, ppObject));
    }

    AddRefOuter();
    RRETURN(S_OK);
}


// Properties.
IFACEMETHODIMP DirectUI::DragStartingEventArgsGenerated::get_Cancel(_Out_ BOOLEAN* pValue)
{
    HRESULT hr = S_OK;
    ARG_VALIDRETURNPOINTER(pValue);
    IFC(CheckThread());
    IFC(CValueBoxer::CopyValue(m_cancel, pValue));
Cleanup:
    RRETURN(hr);
}
IFACEMETHODIMP DirectUI::DragStartingEventArgsGenerated::put_Cancel(_In_ BOOLEAN value)
{
    HRESULT hr = S_OK;
    IFC(CheckThread());
    IFC(CValueBoxer::CopyValue(value, &m_cancel));
Cleanup:
    RRETURN(hr);
}
IFACEMETHODIMP DirectUI::DragStartingEventArgsGenerated::get_Data(_Outptr_result_maybenull_ ABI::Windows::ApplicationModel::DataTransfer::IDataPackage** ppValue)
{
    HRESULT hr = S_OK;
    ARG_VALIDRETURNPOINTER(ppValue);
    IFC(CheckThread());
    IFC(m_pData.CopyTo(ppValue));
Cleanup:
    RRETURN(hr);
}
_Check_return_ HRESULT DirectUI::DragStartingEventArgsGenerated::put_Data(_In_opt_ ABI::Windows::ApplicationModel::DataTransfer::IDataPackage* pValue)
{
    HRESULT hr = S_OK;
    IFC(CheckThread());
    SetPtrValue(m_pData, pValue);
Cleanup:
    RRETURN(hr);
}
IFACEMETHODIMP DirectUI::DragStartingEventArgsGenerated::get_DragUI(_Outptr_result_maybenull_ ABI::Microsoft::UI::Xaml::IDragUI** ppValue)
{
    HRESULT hr = S_OK;
    ARG_VALIDRETURNPOINTER(ppValue);
    *ppValue={};
    IFC(CheckThread());
    IFC(static_cast<DragStartingEventArgs*>(this)->get_DragUIImpl(ppValue));
Cleanup:
    RRETURN(hr);
}
IFACEMETHODIMP DirectUI::DragStartingEventArgsGenerated::get_AllowedOperations(_Out_ ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation* pValue)
{
    HRESULT hr = S_OK;
    ARG_VALIDRETURNPOINTER(pValue);
    IFC(CheckThread());
    IFC(CValueBoxer::CopyValue(m_allowedOperations, pValue));
Cleanup:
    RRETURN(hr);
}
IFACEMETHODIMP DirectUI::DragStartingEventArgsGenerated::put_AllowedOperations(_In_ ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation value)
{
    HRESULT hr = S_OK;
    IFC(CheckThread());
    IFC(CValueBoxer::CopyValue(value, &m_allowedOperations));
Cleanup:
    RRETURN(hr);
}

// Methods.
IFACEMETHODIMP DirectUI::DragStartingEventArgsGenerated::GetDeferral(_Outptr_ ABI::Microsoft::UI::Xaml::IDragOperationDeferral** ppReturnValue)
{
    HRESULT hr = S_OK;
    if (EventEnabledApiFunctionCallStart())
    {
        XamlTelemetry::PublicApiCall(true, reinterpret_cast<uint64_t>(this), "DragStartingEventArgs_GetDeferral", 0);
    }
    ARG_VALIDRETURNPOINTER(ppReturnValue);
    *ppReturnValue={};
    IFC(CheckThread());
    IFC(static_cast<DragStartingEventArgs*>(this)->GetDeferralImpl(ppReturnValue));
Cleanup:
    if (EventEnabledApiFunctionCallStop())
    {
        XamlTelemetry::PublicApiCall(false, reinterpret_cast<uint64_t>(this), "DragStartingEventArgs_GetDeferral", hr);
    }
    RRETURN(hr);
}
IFACEMETHODIMP DirectUI::DragStartingEventArgsGenerated::GetPosition(_In_opt_ ABI::Microsoft::UI::Xaml::IUIElement* pRelativeTo, _Out_ ABI::Windows::Foundation::Point* pReturnValue)
{
    HRESULT hr = S_OK;
    if (EventEnabledApiFunctionCallStart())
    {
        XamlTelemetry::PublicApiCall(true, reinterpret_cast<uint64_t>(this), "DragStartingEventArgs_GetPosition", 0);
    }
    ARG_VALIDRETURNPOINTER(pReturnValue);
    *pReturnValue={};
    IFC(CheckThread());
    IFC(static_cast<DragStartingEventArgs*>(this)->GetPositionImpl(pRelativeTo, pReturnValue));
Cleanup:
    if (EventEnabledApiFunctionCallStop())
    {
        XamlTelemetry::PublicApiCall(false, reinterpret_cast<uint64_t>(this), "DragStartingEventArgs_GetPosition", hr);
    }
    RRETURN(hr);
}
IFACEMETHODIMP DirectUI::DragStartingEventArgsGenerated::DeferralAdded()
{
    HRESULT hr = S_OK;
    if (EventEnabledApiFunctionCallStart())
    {
        XamlTelemetry::PublicApiCall(true, reinterpret_cast<uint64_t>(this), "DragStartingEventArgs_DeferralAdded", 0);
    }
    
    IFC(CheckThread());
    IFC(static_cast<DragStartingEventArgs*>(this)->DeferralAddedImpl());
Cleanup:
    if (EventEnabledApiFunctionCallStop())
    {
        XamlTelemetry::PublicApiCall(false, reinterpret_cast<uint64_t>(this), "DragStartingEventArgs_DeferralAdded", hr);
    }
    RRETURN(hr);
}
IFACEMETHODIMP DirectUI::DragStartingEventArgsGenerated::DeferralCompleted()
{
    HRESULT hr = S_OK;
    if (EventEnabledApiFunctionCallStart())
    {
        XamlTelemetry::PublicApiCall(true, reinterpret_cast<uint64_t>(this), "DragStartingEventArgs_DeferralCompleted", 0);
    }
    
    IFC(CheckThread());
    IFC(static_cast<DragStartingEventArgs*>(this)->DeferralCompletedImpl());
Cleanup:
    if (EventEnabledApiFunctionCallStop())
    {
        XamlTelemetry::PublicApiCall(false, reinterpret_cast<uint64_t>(this), "DragStartingEventArgs_DeferralCompleted", hr);
    }
    RRETURN(hr);
}
IFACEMETHODIMP DirectUI::DragStartingEventArgsGenerated::SetAcceptedOperation(_In_ IInspectable* pSource, _In_ ABI::Windows::ApplicationModel::DataTransfer::DataPackageOperation acceptedOperation)
{
    HRESULT hr = S_OK;
    if (EventEnabledApiFunctionCallStart())
    {
        XamlTelemetry::PublicApiCall(true, reinterpret_cast<uint64_t>(this), "DragStartingEventArgs_SetAcceptedOperation", 0);
    }
    ARG_NOTNULL(pSource, "source");
    IFC(CheckThread());
    IFC(static_cast<DragStartingEventArgs*>(this)->SetAcceptedOperationImpl(pSource, acceptedOperation));
Cleanup:
    if (EventEnabledApiFunctionCallStop())
    {
        XamlTelemetry::PublicApiCall(false, reinterpret_cast<uint64_t>(this), "DragStartingEventArgs_SetAcceptedOperation", hr);
    }
    RRETURN(hr);
}


namespace DirectUI
{
    _Check_return_ HRESULT OnFrameworkCreateDragStartingEventArgs(_In_ CEventArgs* pCoreObject, _Out_ IInspectable** ppNewInstance)
    {
        HRESULT hr = S_OK;
        ctl::ComPtr<DirectUI::DragStartingEventArgs> spInstance;
        *ppNewInstance = nullptr;
        IFC(ctl::make(pCoreObject, &spInstance));
        *ppNewInstance = ctl::iinspectable_cast(spInstance.Detach());
    Cleanup:
        RRETURN(hr);
    }
    _Check_return_ IActivationFactory* CreateActivationFactory_DragStartingEventArgs()
    {
        RRETURN(ctl::ActivationFactoryCreator<ctl::AbstractActivationFactory>::CreateActivationFactory());
    }
}