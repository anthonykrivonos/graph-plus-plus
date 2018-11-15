#!/bin/bash
#Run this in terminal
#+ Command to compile c++ program. here i used common one
g++ test-graph.cpp graph.cpp -o main
# ./main "test-graph-file-1"
./main "test-graph-file-2"
exit 0