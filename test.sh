#!/bin/bash

TEST_DIR=tests/

if [ -d "tests/" ]; then
    cd "$TEST_DIR"

    # Compile
    echo "Compile tests..."
    make

    # Testing
    echo "FCFS test..."
    ./fcfs_test

    # Clean
    echo "Clean ..."
    make clean
    cd ..
fi