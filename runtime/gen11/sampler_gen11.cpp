/*
 * Copyright (C) 2018-2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "runtime/gen11/hw_cmds.h"
#include "runtime/sampler/sampler.h"
#include "runtime/sampler/sampler.inl"

namespace NEO {

typedef ICLFamily Family;
static auto gfxCore = IGFX_GEN11_CORE;

#include "runtime/sampler/sampler_factory_init.inl"
} // namespace NEO
