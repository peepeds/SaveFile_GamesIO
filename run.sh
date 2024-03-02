#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <source_file.cpp>"
    exit 1
fi

source_file=$1
executable_name="${source_file%.*}"  

g++ -std=c++11 "$source_file" -o "$executable_name"


if [ $? -eq 0 ]; then
    "./$executable_name"
else
    echo "Compilation failed."
fi

rm main 
rm main.exe