#!/bin/bash

# Build the project
echo "Building the project..."
pushd ./build
    cmake ..;
    cmake --build .;
popd 