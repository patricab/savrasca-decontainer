#!/bin/bash

# rm -rf traces
# rm -rf traces_exe
rm inputs.csv outputs.csv trace.npy

# create directories for simulated traces
# if [ ! -d traces ]
# then
# 	mkdir traces
# fi
# if [ ! -d traces_exe ]
# then
# 	mkdir traces_exe
# fi

# Loop through _i_ number of attacks
numguess=10

for ((i=0; i < numguess; i++))
do
    python3 generateInputs.py $i
done;

# Parse data
python3 parseTrace.py

# # Analyze data
# python3 analyze.py