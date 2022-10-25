#!/bin/bash
NAME=aes
SIMPATH=../../savrasca/simulavr/src/simulavr
ARCH=atmega128

# filename of the binary for the simulation
file=src/$NAME.elf
# if [ ! -f $file ]
# then
	# echo "Binary file is missing!";
	# echo "Trying to compile it in the src folder";
	cd src/ ;
	make clean ;
	make ;
	cd .. ;
# fi

# remove old file with plaintexts
if [ -f inputs.csv ]
then
	rm inputs.csv
fi

# create directories for simulated traces
if [ ! -d traces ]
then
	mkdir traces
fi
if [ ! -d traces_exe ]
then
	mkdir traces_exe
fi


# repeat simulation by calling python script
# for (( i=0; i<10; i++ ))
# do
#     # python3 generateInputs.py $i | $SIMPATH -t traces_exe/trace_exe_`printf "%05d" $i` -P traces/trace`printf "%05d" $i` -d $ARCH -f $file -W 0x20,- -R 0x22,- -T exit
    # $SIMPATH -t traces_exe/trace_exe_`printf "%05d" $i` -P traces/trace`printf "%05d" $i` -d $ARCH -f $file -W 0x20,- -R 0x22,- -T exit
    $SIMPATH -g -t traces_exe/trace_exe_`printf "%05d" $i` -P traces/trace`printf "%05d" $i` -d $ARCH -f $file -W 0x20,- -R 0x22,- -T exit
    
# done;

