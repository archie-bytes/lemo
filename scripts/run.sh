#!/bin/bash

set -e

# 1. 编译阶段
echo -e "🍋\033[32m [LEMO] 开始编译... \033[0m"

rm -rf build && mkdir build
cd build || exit

cmake \
  -DCMAKE_TOOLCHAIN_FILE=/Users/archie/development/vcpkg/scripts/buildsystems/vcpkg.cmake \
  -DVCPKG_MANIFEST_MODE=ON \
  ..
cmake --build .


# 2. 执行阶段
echo -e "🍋\033[32m [LEMO] 开始执行... \033[0m"
./sfml01
