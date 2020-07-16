#! /bin/bash

rm -rf *.o
if [[ ! -d bin ]]; then
mkdir bin
fi
gcc -c binary_search_tree.c
gcc -o bin/out *.o
rm -rf *.o
./bin/out
rm -rf bin