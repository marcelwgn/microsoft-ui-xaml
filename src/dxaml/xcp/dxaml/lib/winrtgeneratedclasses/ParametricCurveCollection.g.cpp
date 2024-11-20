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

#include "ParametricCurveCollection.g.h"
#include "XamlTelemetry.h"

// Constructors/destructors.
DirectUI::ParametricCurveCollection::ParametricCurveCollection()
{
}

DirectUI::ParametricCurveCollection::~ParametricCurveCollection()
{
}

HRESULT DirectUI::ParametricCurveCollection::QueryInterfaceImpl(_In_ REFIID iid, _Outptr_ void** ppObject)
{
    if (InlineIsEqualGUID(iid, __uuidof(DirectUI::ParametricCurveCollection)))
    {
        *ppObject = static_cast<DirectUI::ParametricCurveCollection*>(this);
    }
    else if (InlineIsEqualGUID(iid, __uuidof(ABI::Windows::Foundation::Collections::IVector<DirectUI::ParametricCurve*>)))
    {
        *ppObject = static_cast<ABI::Windows::Foundation::Collections::IVector<DirectUI::ParametricCurve*>*>(this);
    }
    else
    {
        RRETURN(DirectUI::PresentationFrameworkCollection<DirectUI::ParametricCurve*>::QueryInterfaceImpl(iid, ppObject));
    }

    AddRefOuter();
    RRETURN(S_OK);
}

// Properties.

// Events.

// Methods.


namespace DirectUI
{
}