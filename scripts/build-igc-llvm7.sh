#!/bin/bash
#
# Copyright (C) 2018-2019 Intel Corporation
#
# SPDX-License-Identifier: MIT
#

mkdir /root/build-igc
cd /root/build-igc

export cclang_commit_id=6257ffe137a2c8df95a3f3b39fa477aa8ed15837
export spirv_id=8ce6443ec1020183eafaeb3410c7d1edc2355dc3
export igc_commit_id=7c89d200bf9c5b5900d961bc6f7df5373f3d0ab6

wget --no-check-certificate https://github.com/intel/opencl-clang/archive/${cclang_commit_id}/opencl-clang.tar.gz
wget --no-check-certificate https://github.com/intel/intel-graphics-compiler/archive/${igc_commit_id}/igc.tar.gz
wget --no-check-certificate https://github.com/KhronosGroup/SPIRV-LLVM-Translator/archive/${spirv_id}/spirv-llvm-translator.tar.gz

mkdir igc common_clang llvm-spirv

tar xzf opencl-clang.tar.gz -C common_clang --strip-components=1
tar xzf igc.tar.gz -C igc --strip-components=1
patch -p1 < /root/llvm7.patch

tar xzf spirv-llvm-translator.tar.gz -C llvm-spirv --strip-components=1

mkdir build_spirv
cd build_spirv
cmake ../llvm-spirv -DCMAKE_INSTALL_PREFIX=install -DCMAKE_POSITION_INDEPENDENT_CODE=ON -DCMAKE_BUILD_TYPE=Release
make llvm-spirv -j`nproc`
make install
cd ..

mkdir build_opencl_clang
cd build_opencl_clang
cmake -DCOMMON_CLANG_LIBRARY_NAME=opencl_clang -DLLVMSPIRV_INCLUDED_IN_LLVM=OFF -DSPIRV_TRANSLATOR_DIR=../build_spirv/install -DLLVM_NO_DEAD_STRIP=ON  -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX='/usr' ../common_clang
make -j`nproc` all
make install
cd ..

mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release -DIGC_OPTION__OUTPUT_DIR=../igc-install/Release -DCOMMON_CLANG_LIBRARY_NAME=opencl_clang -DVME_TYPES_DEFINED=FALSE -DCMAKE_INSTALL_PREFIX='/usr' -Wno-dev ../igc
make -j 1
make install
cd ..

