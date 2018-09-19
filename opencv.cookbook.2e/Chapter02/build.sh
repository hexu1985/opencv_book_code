#!/usr/bin/env bash

debug=0

this_sh_path=$(dirname $0)

test $debug -gt 0 && echo "this_sh_path: $this_sh_path"

cd $this_sh_path
this_sh_path=$PWD

sys_name=$(uname -a)

rm -rf ./build
mkdir build
cd build

if [[ "$sys_name" =~ "MINGW" ]]
then
    cmake -G"Unix Makefiles" ..
else
    cmake ..
fi
make

