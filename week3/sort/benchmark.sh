// This script benchmarks the sorting programs against various input files alwoing to mesure their performance
// kowning the time taken to sort the files allows to compare the efficiency of the algorithms
// and know this can let us know wich algorithm is wich one
// Selection sort, bubble sort or merge sort

#!/bin/bash

programs=("sort1" "sort2" "sort3")
inputs=(random5000.txt random10000.txt random50000.txt \
        reversed5000.txt reversed10000.txt reversed50000.txt \
        sorted5000.txt sorted10000.txt sorted50000.txt)

for program in "${programs[@]}"
do
    echo "Testing $program"
    for input in "${inputs[@]}"
    do
        echo -n "$program with $input: "
        { time ./$program $input > /dev/null; } 2>&1 | grep real
    done
    echo ""
done