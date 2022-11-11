#!/bin/bash

# Loop through _i_ number of attacks
numguess=10

for ((i=0; i < numguess; i++))
do
    python3 generateInputs.py
done;

# Parse data
# python3 parseTrace.py

# # Analyze data
# python3 analyze.py