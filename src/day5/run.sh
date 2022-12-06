#! /bin/bash

echo "Day 5: Supply Stacks"
echo

make 1> /dev/null

if [ $? -ne 0 ]; then
    echo "An error occurred during compilation."
    exit 1
fi

basePath="../../input/day5/"

testInputFilePath="${basePath}input_test.txt"

if test -f $testInputFilePath; then
    echo "Results for test input data:"
    ./main $testInputFilePath
else
    echo "The test input file count not be found."
fi

echo

inputFilePath="${basePath}input.txt"

if test -f $inputFilePath; then
    echo "Results for input data:"
    ./main $inputFilePath
else
    echo "The input file could not be found."
fi