// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See LICENSE in the project root for license information.

// DO NOT EDIT! This file was generated by CustomTasks.DependencyPropertyCodeGen
#include "pch.h"
#include "common.h"
#include "RatingControl.h"

namespace winrt::Microsoft::UI::Xaml::Controls
{
    CppWinRTActivatableClassWithDPFactory(RatingControl)
}

#include "RatingControl.g.cpp"

GlobalDependencyProperty RatingControlProperties::s_CaptionProperty{ nullptr };
GlobalDependencyProperty RatingControlProperties::s_InitialSetValueProperty{ nullptr };
GlobalDependencyProperty RatingControlProperties::s_IsClearEnabledProperty{ nullptr };
GlobalDependencyProperty RatingControlProperties::s_IsReadOnlyProperty{ nullptr };
GlobalDependencyProperty RatingControlProperties::s_ItemInfoProperty{ nullptr };
GlobalDependencyProperty RatingControlProperties::s_MaxRatingProperty{ nullptr };
GlobalDependencyProperty RatingControlProperties::s_PlaceholderValueProperty{ nullptr };
GlobalDependencyProperty RatingControlProperties::s_ValueProperty{ nullptr };

RatingControlProperties::RatingControlProperties()
    : m_valueChangedEventSource{static_cast<RatingControl*>(this)}
{
    EnsureProperties();
}

void RatingControlProperties::EnsureProperties()
{
    if (!s_CaptionProperty)
    {
        s_CaptionProperty =
            InitializeDependencyProperty(
                L"Caption",
                winrt::name_of<winrt::hstring>(),
                winrt::name_of<winrt::RatingControl>(),
                false /* isAttached */,
                ValueHelper<winrt::hstring>::BoxedDefaultValue(),
                winrt::PropertyChangedCallback(&OnCaptionPropertyChanged));
    }
    if (!s_InitialSetValueProperty)
    {
        s_InitialSetValueProperty =
            InitializeDependencyProperty(
                L"InitialSetValue",
                winrt::name_of<int>(),
                winrt::name_of<winrt::RatingControl>(),
                false /* isAttached */,
                ValueHelper<int>::BoxValueIfNecessary(1),
                winrt::PropertyChangedCallback(&OnInitialSetValuePropertyChanged));
    }
    if (!s_IsClearEnabledProperty)
    {
        s_IsClearEnabledProperty =
            InitializeDependencyProperty(
                L"IsClearEnabled",
                winrt::name_of<bool>(),
                winrt::name_of<winrt::RatingControl>(),
                false /* isAttached */,
                ValueHelper<bool>::BoxValueIfNecessary(true),
                winrt::PropertyChangedCallback(&OnIsClearEnabledPropertyChanged));
    }
    if (!s_IsReadOnlyProperty)
    {
        s_IsReadOnlyProperty =
            InitializeDependencyProperty(
                L"IsReadOnly",
                winrt::name_of<bool>(),
                winrt::name_of<winrt::RatingControl>(),
                false /* isAttached */,
                ValueHelper<bool>::BoxedDefaultValue(),
                winrt::PropertyChangedCallback(&OnIsReadOnlyPropertyChanged));
    }
    if (!s_ItemInfoProperty)
    {
        s_ItemInfoProperty =
            InitializeDependencyProperty(
                L"ItemInfo",
                winrt::name_of<winrt::RatingItemInfo>(),
                winrt::name_of<winrt::RatingControl>(),
                false /* isAttached */,
                ValueHelper<winrt::RatingItemInfo>::BoxedDefaultValue(),
                winrt::PropertyChangedCallback(&OnItemInfoPropertyChanged));
    }
    if (!s_MaxRatingProperty)
    {
        s_MaxRatingProperty =
            InitializeDependencyProperty(
                L"MaxRating",
                winrt::name_of<int>(),
                winrt::name_of<winrt::RatingControl>(),
                false /* isAttached */,
                ValueHelper<int>::BoxValueIfNecessary(5),
                winrt::PropertyChangedCallback(&OnMaxRatingPropertyChanged));
    }
    if (!s_PlaceholderValueProperty)
    {
        s_PlaceholderValueProperty =
            InitializeDependencyProperty(
                L"PlaceholderValue",
                winrt::name_of<double>(),
                winrt::name_of<winrt::RatingControl>(),
                false /* isAttached */,
                ValueHelper<double>::BoxValueIfNecessary(-1),
                winrt::PropertyChangedCallback(&OnPlaceholderValuePropertyChanged));
    }
    if (!s_ValueProperty)
    {
        s_ValueProperty =
            InitializeDependencyProperty(
                L"Value",
                winrt::name_of<double>(),
                winrt::name_of<winrt::RatingControl>(),
                false /* isAttached */,
                ValueHelper<double>::BoxValueIfNecessary(-1),
                winrt::PropertyChangedCallback(&OnValuePropertyChanged));
    }
}

void RatingControlProperties::ClearProperties()
{
    s_CaptionProperty = nullptr;
    s_InitialSetValueProperty = nullptr;
    s_IsClearEnabledProperty = nullptr;
    s_IsReadOnlyProperty = nullptr;
    s_ItemInfoProperty = nullptr;
    s_MaxRatingProperty = nullptr;
    s_PlaceholderValueProperty = nullptr;
    s_ValueProperty = nullptr;
}

void RatingControlProperties::OnCaptionPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::RatingControl>();
    winrt::get_self<RatingControl>(owner)->OnPropertyChanged(args);
}

void RatingControlProperties::OnInitialSetValuePropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::RatingControl>();
    winrt::get_self<RatingControl>(owner)->OnPropertyChanged(args);
}

void RatingControlProperties::OnIsClearEnabledPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::RatingControl>();
    winrt::get_self<RatingControl>(owner)->OnPropertyChanged(args);
}

void RatingControlProperties::OnIsReadOnlyPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::RatingControl>();
    winrt::get_self<RatingControl>(owner)->OnPropertyChanged(args);
}

void RatingControlProperties::OnItemInfoPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::RatingControl>();
    winrt::get_self<RatingControl>(owner)->OnPropertyChanged(args);
}

void RatingControlProperties::OnMaxRatingPropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::RatingControl>();
    winrt::get_self<RatingControl>(owner)->OnPropertyChanged(args);
}

void RatingControlProperties::OnPlaceholderValuePropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::RatingControl>();
    winrt::get_self<RatingControl>(owner)->OnPropertyChanged(args);
}

void RatingControlProperties::OnValuePropertyChanged(
    winrt::DependencyObject const& sender,
    winrt::DependencyPropertyChangedEventArgs const& args)
{
    auto owner = sender.as<winrt::RatingControl>();
    winrt::get_self<RatingControl>(owner)->OnPropertyChanged(args);
}

void RatingControlProperties::Caption(winrt::hstring const& value)
{
    [[gsl::suppress(con)]]
    {
    static_cast<RatingControl*>(this)->SetValue(s_CaptionProperty, ValueHelper<winrt::hstring>::BoxValueIfNecessary(value));
    }
}

winrt::hstring RatingControlProperties::Caption()
{
    return ValueHelper<winrt::hstring>::CastOrUnbox(static_cast<RatingControl*>(this)->GetValue(s_CaptionProperty));
}

void RatingControlProperties::InitialSetValue(int value)
{
    [[gsl::suppress(con)]]
    {
    static_cast<RatingControl*>(this)->SetValue(s_InitialSetValueProperty, ValueHelper<int>::BoxValueIfNecessary(value));
    }
}

int RatingControlProperties::InitialSetValue()
{
    return ValueHelper<int>::CastOrUnbox(static_cast<RatingControl*>(this)->GetValue(s_InitialSetValueProperty));
}

void RatingControlProperties::IsClearEnabled(bool value)
{
    [[gsl::suppress(con)]]
    {
    static_cast<RatingControl*>(this)->SetValue(s_IsClearEnabledProperty, ValueHelper<bool>::BoxValueIfNecessary(value));
    }
}

bool RatingControlProperties::IsClearEnabled()
{
    return ValueHelper<bool>::CastOrUnbox(static_cast<RatingControl*>(this)->GetValue(s_IsClearEnabledProperty));
}

void RatingControlProperties::IsReadOnly(bool value)
{
    [[gsl::suppress(con)]]
    {
    static_cast<RatingControl*>(this)->SetValue(s_IsReadOnlyProperty, ValueHelper<bool>::BoxValueIfNecessary(value));
    }
}

bool RatingControlProperties::IsReadOnly()
{
    return ValueHelper<bool>::CastOrUnbox(static_cast<RatingControl*>(this)->GetValue(s_IsReadOnlyProperty));
}

void RatingControlProperties::ItemInfo(winrt::RatingItemInfo const& value)
{
    [[gsl::suppress(con)]]
    {
    static_cast<RatingControl*>(this)->SetValue(s_ItemInfoProperty, ValueHelper<winrt::RatingItemInfo>::BoxValueIfNecessary(value));
    }
}

winrt::RatingItemInfo RatingControlProperties::ItemInfo()
{
    return ValueHelper<winrt::RatingItemInfo>::CastOrUnbox(static_cast<RatingControl*>(this)->GetValue(s_ItemInfoProperty));
}

void RatingControlProperties::MaxRating(int value)
{
    [[gsl::suppress(con)]]
    {
    static_cast<RatingControl*>(this)->SetValue(s_MaxRatingProperty, ValueHelper<int>::BoxValueIfNecessary(value));
    }
}

int RatingControlProperties::MaxRating()
{
    return ValueHelper<int>::CastOrUnbox(static_cast<RatingControl*>(this)->GetValue(s_MaxRatingProperty));
}

void RatingControlProperties::PlaceholderValue(double value)
{
    [[gsl::suppress(con)]]
    {
    static_cast<RatingControl*>(this)->SetValue(s_PlaceholderValueProperty, ValueHelper<double>::BoxValueIfNecessary(value));
    }
}

double RatingControlProperties::PlaceholderValue()
{
    return ValueHelper<double>::CastOrUnbox(static_cast<RatingControl*>(this)->GetValue(s_PlaceholderValueProperty));
}

void RatingControlProperties::Value(double value)
{
    [[gsl::suppress(con)]]
    {
    static_cast<RatingControl*>(this)->SetValue(s_ValueProperty, ValueHelper<double>::BoxValueIfNecessary(value));
    }
}

double RatingControlProperties::Value()
{
    return ValueHelper<double>::CastOrUnbox(static_cast<RatingControl*>(this)->GetValue(s_ValueProperty));
}

winrt::event_token RatingControlProperties::ValueChanged(winrt::TypedEventHandler<winrt::RatingControl, winrt::IInspectable> const& value)
{
    return m_valueChangedEventSource.add(value);
}

void RatingControlProperties::ValueChanged(winrt::event_token const& token)
{
    m_valueChangedEventSource.remove(token);
}
