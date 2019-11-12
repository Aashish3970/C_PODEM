#!/bin/bash

clear
echo "-----------c17-----------------"
./project c17.isc c17.pattern c17.out
echo "-------------c880-----------"
./project c880.isc c880.pattern c880.out
echo "--------------c1908--------"
./project c1908.isc c1908.pattern c1908.out
echo "---------c1355----------"
./project c1355.isc c1355.pattern c1355.out
echo "---------c5315----------"
./project c5315.isc c5315.pattern c5315.out
echo "---------c3540----------"
./project c3540.isc c3540.pattern c3540.out
echo "---------c7552----------"
./project c7552.isc c7552.pattern c7552.out

echo "Run completed"
