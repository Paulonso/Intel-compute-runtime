/*
 * Copyright (C) 2019 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#pragma once
#include "core/memory_manager/memory_constants.h"
#include "runtime/helpers/csr_deps.h"
#include "runtime/helpers/properties_helper.h"

#include <cstdint>

namespace NEO {
struct BuiltinOpParams;
class Context;
class CommandStreamReceiver;
class GraphicsAllocation;
class LinearStream;
class TimestampPacketContainer;

struct BlitProperties {
    static BlitProperties constructPropertiesForReadWriteBuffer(BlitterConstants::BlitDirection blitDirection,
                                                                CommandStreamReceiver &commandStreamReceiver,
                                                                GraphicsAllocation *memObjAllocation, size_t memObjOFfset,
                                                                GraphicsAllocation *mapAllocation,
                                                                void *hostPtr, size_t hostPtrOffset,
                                                                bool blocking, size_t copyOffset, uint64_t copySize);

    static BlitProperties constructPropertiesForReadWriteBuffer(BlitterConstants::BlitDirection blitDirection,
                                                                CommandStreamReceiver &commandStreamReceiver,
                                                                const BuiltinOpParams &builtinOpParams,
                                                                bool blocking);

    static BlitProperties constructPropertiesForCopyBuffer(GraphicsAllocation *dstAllocation, GraphicsAllocation *srcAllocation,
                                                           bool blocking, size_t dstOffset, size_t srcOffset, uint64_t copySize);

    static BlitProperties constructPropertiesForAuxTranslation(AuxTranslationDirection auxTranslationDirection,
                                                               GraphicsAllocation *allocation);

    static BlitterConstants::BlitDirection obtainBlitDirection(uint32_t commandType);

    TimestampPacketContainer *outputTimestampPacket = nullptr;
    BlitterConstants::BlitDirection blitDirection;
    CsrDependencies csrDependencies;
    AuxTranslationDirection auxTranslationDirection = AuxTranslationDirection::None;

    GraphicsAllocation *dstAllocation = nullptr;
    GraphicsAllocation *srcAllocation = nullptr;
    bool blocking = false;
    size_t dstOffset = 0;
    size_t srcOffset = 0;
    uint64_t copySize = 0;
};

template <typename GfxFamily>
struct BlitCommandsHelper {
    static size_t estimateBlitCommandsSize(uint64_t copySize, const CsrDependencies &csrDependencies, bool updateTimestampPacket);
    static void dispatchBlitCommandsForBuffer(const BlitProperties &blitProperites, LinearStream &linearStream);
    static void appendBlitCommandsForBuffer(const BlitProperties &blitProperites, typename GfxFamily::XY_COPY_BLT &blitCmd);
};
} // namespace NEO
