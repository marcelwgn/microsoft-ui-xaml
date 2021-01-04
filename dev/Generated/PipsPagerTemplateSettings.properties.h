// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

// DO NOT EDIT! This file was generated by CustomTasks.DependencyPropertyCodeGen
#pragma once

class PipsPagerTemplateSettingsProperties
{
public:
    PipsPagerTemplateSettingsProperties();

    void Dispatcher(winrt::CoreDispatcher const& value);
    winrt::CoreDispatcher Dispatcher();

    void PipsPagerItems(winrt::IVector<winrt::IInspectable> const& value);
    winrt::IVector<winrt::IInspectable> PipsPagerItems();

    static winrt::DependencyProperty DispatcherProperty() { return s_DispatcherProperty; }
    static winrt::DependencyProperty PipsPagerItemsProperty() { return s_PipsPagerItemsProperty; }

    static GlobalDependencyProperty s_DispatcherProperty;
    static GlobalDependencyProperty s_PipsPagerItemsProperty;

    static void EnsureProperties();
    static void ClearProperties();
};
