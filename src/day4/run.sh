#! /bin/bash

echo "Day 4: Camp Cleanup"
echo

basePath="../../input/day4/"
testInputFilePath="${basePath}input_test.txt"

if test -f $testInputFilePath; then
    echo "Results for test input data:"
    lein run $testInputFilePath
else
    echo "The test input file count not be found."
fi

echo

inputFilePath="${basePath}input.txt"

if test -f $inputFilePath; then
    echo "Results for input data:"
    lein run $inputFilePath
else
    echo "The input file could not be found."
fi