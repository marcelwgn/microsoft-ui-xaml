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

#include "CSelectorItemAutomationPeer.g.h"
#include <DeclareMacros.h>
#include <Indexes.g.h>
#include <minxcptypes.h>

class CListViewBaseItemDataAutomationPeer : public CSelectorItemAutomationPeer
{
protected:
    CListViewBaseItemDataAutomationPeer(_In_ CCoreServices *pCore, _In_ CValue &value)
        : CSelectorItemAutomationPeer(pCore, value)
    {
        SetIsCustomType();
    }

    ~CListViewBaseItemDataAutomationPeer() override = default;

public:

    KnownTypeIndex GetTypeIndex() const override
    {
        return KnownTypeIndex::ListViewBaseItemDataAutomationPeer;
    }

    XUINT32 ParticipatesInManagedTreeInternal() override
    {
        return PARTICIPATES_IN_MANAGED_TREE;
    }
};