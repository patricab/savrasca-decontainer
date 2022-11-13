#!/usr/bin/env python
# %%
from copyreg import pickle
import random
import os
import numpy as np

trace = []
log = []
output = []

#%% Split input/output array
with open("inputs.csv", "rb") as inputfile:
    input = np.loadtxt(inputfile)
    input = [input[i:i + 16] for i in range(0, len(input), 16)]

    inputfile.close()

with open("outputs.csv", "rb") as outputfile:
    output = np.loadtxt(outputfile)
    output = [output[i:i + 16] for i in range(0, len(output), 16)]

    outputfile.close()

#%% Read and append trace files
# Open logfile
with open("trace.npy", "wb") as logfile:
    # Get number of trace files
    # _, _, files = next(os.walk("traces"))

    # Loop through files in traces/
    # for i in range(len(files)):
    #     with open("traces/" + files[i], "rb") as tracefile:

            # Read tracefile into trace array
            # while tracefile.read(1):
            #     trace.append(int.from_bytes(tracefile.read(1), "little"))

            # Add plaintext + trace into log
            # log.append([np.load(input, allow_pickle=True), np.array(trace)])
            # log.append([input[i], np.array(trace)])
            # tracefile.close()
            
        # Reset trace array
        # trace = []

    for i in range(len(input)):
        log.append([input[i], output[i]])

    log = np.array(log, dtype=object)
    np.save(logfile, log)
    logfile.close()