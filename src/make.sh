#!/bin/bash

premake5 gmake2
cd build
make
cd ..
echo "Running Full_build"
echo ""
./build/Full_build
