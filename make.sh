#!/bin/bash

clear
cd bin
rm libgui_test
cmake -DCMAKE_BUILD_TYPE=Debug ../
make -j 9
cd ..

