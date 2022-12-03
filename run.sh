#! /bin/bash

BASE_SOLUTION_PATH="src/day"
SCRIPT_NAME="run.sh"

SEPARATOR=`printf "=%.0s" {1..35}`

runSolutionForDay() {
    day_number=$1

    solution_dir="${BASE_SOLUTION_PATH}${day_number}"

    if [ -d $solution_dir ] && [ -f "${solution_dir}/${SCRIPT_NAME}" ]; then
        cd $solution_dir
        "./${SCRIPT_NAME}"
        cd - 1> /dev/null

        echo $SEPARATOR
    fi
}

echo $SEPARATOR

for day_number in {1..25}; do
    runSolutionForDay $day_number
done