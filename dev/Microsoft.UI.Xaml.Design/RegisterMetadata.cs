﻿// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

using Microsoft.UI.Xaml.Design;
using Microsoft.UI.Xaml.Design.ControlProvider;
using Microsoft.VisualStudio.DesignTools.Extensibility.Metadata;

[assembly: ProvideMetadata(typeof(RegisterMetadata))]
namespace Microsoft.UI.Xaml.Design
{
    public class RegisterMetadata : IProvideAttributeTable
    {

        public AttributeTable AttributeTable
        {
            get
            {
                AttributeTableBuilder builder = new AttributeTableBuilder();
                ControlPropertyProvider.SetGlobalTableBuilder(builder);

                new NumberBoxPropertyProvider().AddProperties();

                return builder.CreateTable();
            }
        }
    }
}
