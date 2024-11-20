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

#include "ListViewBaseItemTemplateSettings.g.h"

#define __ListViewItemTemplateSettings_GUID "92dfa119-7bcd-4e38-be2d-b5da7d207a76"

namespace DirectUI
{
    class ListViewItemTemplateSettings;

    class __declspec(novtable) __declspec(uuid(__ListViewItemTemplateSettings_GUID)) ListViewItemTemplateSettings:
        public DirectUI::ListViewBaseItemTemplateSettings
        , public ABI::Microsoft::UI::Xaml::Controls::Primitives::IListViewItemTemplateSettings
    {

        INSPECTABLE_CLASS(L"Microsoft.UI.Xaml.Controls.Primitives.ListViewItemTemplateSettings");

        BEGIN_INTERFACE_MAP(ListViewItemTemplateSettings, DirectUI::ListViewBaseItemTemplateSettings)
            INTERFACE_ENTRY(ListViewItemTemplateSettings, ABI::Microsoft::UI::Xaml::Controls::Primitives::IListViewItemTemplateSettings)
        END_INTERFACE_MAP(ListViewItemTemplateSettings, DirectUI::ListViewBaseItemTemplateSettings)

    public:
        ListViewItemTemplateSettings();
        ~ListViewItemTemplateSettings() override;

        // Event source typedefs.

        KnownTypeIndex GetTypeIndex() const override
        {
            return KnownTypeIndex::ListViewItemTemplateSettings;
        }

        static XCP_FORCEINLINE KnownTypeIndex GetTypeIndexStatic()
        {
            return KnownTypeIndex::ListViewItemTemplateSettings;
        }

        // Properties.
        IFACEMETHOD(get_DragItemsCount)(_Out_ INT* pValue) override;
        _Check_return_ HRESULT put_DragItemsCount(_In_ INT value);

        // Events.

        // Methods.


    protected:
        HRESULT QueryInterfaceImpl(_In_ REFIID iid, _Outptr_ void** ppObject) override;

    private:
        // Customized properties.

        // Customized methods.

        // Fields.
    };
}


namespace DirectUI
{
    // Note that the ordering of the base types here is important - the base factory comes first, followed by all the
    // interfaces specific to this type.  By doing this, we allow every Factory's CreateInstance method to be more
    // COMDAT-folding-friendly.  Because this ensures that the first vfptr contains GetTypeIndex, it means that all
    // CreateInstance functions with the same base factory generate the same assembly instructions and thus will
    // fold together.  This is significant for binary size in Microsoft.UI.Xaml.dll so change this only with great
    // care.
    class __declspec(novtable) ListViewItemTemplateSettingsFactory:
       public ctl::AbstractActivationFactory
    {

    public:
        // Factory methods.

        // Static properties.

        // Dependency properties.
        

        // Attached properties.

        // Static methods.

        // Static events.

    protected:

        KnownTypeIndex GetTypeIndex() const override
        {
            return KnownTypeIndex::ListViewItemTemplateSettings;
        }


    private:

        // Customized static properties.

        // Customized static  methods.
    };
}