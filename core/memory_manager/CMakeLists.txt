#
# Copyright (C) 2019 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

set(NEO_CORE_MEMORY_MANAGER
  ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
  ${CMAKE_CURRENT_SOURCE_DIR}/definitions${BRANCH_DIR_SUFFIX}/engine_limits.h
  ${CMAKE_CURRENT_SOURCE_DIR}/eviction_status.h
  ${CMAKE_CURRENT_SOURCE_DIR}/gfx_partition.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/${BRANCH_DIR_SUFFIX}/gfx_partition_init_additional_range.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/gfx_partition.h
  ${CMAKE_CURRENT_SOURCE_DIR}/graphics_allocation.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/graphics_allocation.h
  ${CMAKE_CURRENT_SOURCE_DIR}${BRANCH_DIR_SUFFIX}/graphics_allocation_extra.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/host_ptr_defines.h
  ${CMAKE_CURRENT_SOURCE_DIR}/local_memory_usage.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/local_memory_usage.h
  ${CMAKE_CURRENT_SOURCE_DIR}/memory_constants.h
  ${CMAKE_CURRENT_SOURCE_DIR}/memory_operations_handler.h
  ${CMAKE_CURRENT_SOURCE_DIR}/memory_operations_status.h
  ${CMAKE_CURRENT_SOURCE_DIR}/memory_pool.h
  ${CMAKE_CURRENT_SOURCE_DIR}/residency.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/residency.h
)

set_property(GLOBAL PROPERTY NEO_CORE_MEMORY_MANAGER ${NEO_CORE_MEMORY_MANAGER})
