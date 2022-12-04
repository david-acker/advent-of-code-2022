#! /bin/bash

echo "Running tests for Day 3:"

make test 1> /dev/null

if [ $? -ne 0 ]; then
    echo "An error occurred during compilation."
    exit 1
fi

./test
