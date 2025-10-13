#!/bin/sh

cd "$(dirname "$0")"

mkdir -p build
cd build

#-G generator 指定生成器, （或用Unix Makefils）
cmake -G "Ninja" -DCMAKE_BUILD_TYPE=Debug ..


cmake --build .