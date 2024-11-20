// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

// DO NOT EDIT! This file was generated by CustomTasks.DependencyPropertyCodeGen
#pragma once

class PersonPictureTemplateSettingsProperties
{
public:
    PersonPictureTemplateSettingsProperties();

    void ActualImageBrush(winrt::ImageBrush const& value);
    winrt::ImageBrush ActualImageBrush();

    void ActualInitials(winrt::hstring const& value);
    winrt::hstring ActualInitials();

    static winrt::DependencyProperty ActualImageBrushProperty() { return s_ActualImageBrushProperty; }
    static winrt::DependencyProperty ActualInitialsProperty() { return s_ActualInitialsProperty; }

    static GlobalDependencyProperty s_ActualImageBrushProperty;
    static GlobalDependencyProperty s_ActualInitialsProperty;

    static void EnsureProperties();
    static void ClearProperties();
};