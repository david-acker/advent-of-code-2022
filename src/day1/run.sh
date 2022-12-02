#! /bin/bash

inputFileName=$1

inputFilePath="../../input/day1/"$inputFileName

if test -f $inputFilePath; then
    make && ./main $inputFilePath
else
    echo "The specified input file was not found."
fi