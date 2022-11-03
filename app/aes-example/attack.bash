#!/bin/bash
NAME=aes
SIMPATH=../../savrasca/simulavr/src/simulavr
ARCH=atmega128

# filename of the binary for the simulation
file=src/$NAME.elf

cd src/ ;
make clean ;
make ;
cd .. ;

# create directories for simulated traces
if [ ! -d traces ]
then
	mkdir traces
fi
if [ ! -d traces_exe ]
then
	mkdir traces_exe
fi

# Loop through _i_ number of attacks
numguess=10

for ((i=0; i < numguess; i++))
do
    python3 generateInputs.py $i | $SIMPATH -t traces_exe/trace_exe_`printf "%05d" $i` -P traces/trace`printf "%05d" $i` -d $ARCH -f $file -W 0x20,- -R 0x22,- -T exit
    # $SIMPATH -t traces_exe/trace_exe_`printf "%05d" $i` -P traces/trace`printf "%05d" $i` -d $ARCH -f $file -W 0x20,- -R 0x22,- -T exit
    # $SIMPATH -g -t traces_exe/trace_exe_`printf "%05d" $i` -P traces/trace`printf "%05d" $i` -d $ARCH -f $file -W 0x20,- -R 0x22,- -T exit
done;

# Parse data
python3 parseTrace.py

# Analyze data
python3 analyze.py