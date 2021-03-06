/*
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once
#include "core/memory_properties/memory_properties_flags_common.inl"

namespace NEO {

struct MemoryPropertiesFlags {
    union {
        MemoryFlags flags;
        uint32_t allFlags = 0;
    };
    static_assert(sizeof(MemoryPropertiesFlags::flags) == sizeof(MemoryPropertiesFlags::allFlags), "");
};
} // namespace NEO
