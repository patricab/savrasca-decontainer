#!/usr/bin/env python
# %%
from copyreg import pickle
import random
import os
import numpy as np

trace = []
log = []

# Open logfile
with open("trace.npy", "wb") as logfile:
    # Open plaintext file
    with open("inputs.csv", "rb") as inputfile:

        # Get number of trace files
        _, _, files = next(os.walk("traces"))
        # log = np.zeros([len(files), 1])
        input = np.lead
        
        # Loop through files in traces/
        for i in range(len(files)):
            with open("traces/" + files[i], "rb") as tracefile:

                # Read tracefile into trace array
                while tracefile.read(1):
                    trace.append(int.from_bytes(tracefile.read(1), "little"))
                    i = i + 1

                # Add plaintext + trace into log
                # log.append([np.load(input, allow_pickle=True), np.array(trace)])
                log.append([np.load(input), np.array(trace)])
                tracefile.close()
                
            # Reset trace array
            trace = []
            
        inputfile.close()

    log = np.array(log, dtype=object)
    np.save(logfile, log)
    logfile.close()