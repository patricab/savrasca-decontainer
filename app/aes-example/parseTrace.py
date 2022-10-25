#!/usr/bin/env python
# %%
import random
import os
import numpy as np

trace = []

# Open logfile
with open("trace.npy", "wb") as logfile:
    # Open plaintext file
    with open("inputs.csv", "rb") as inputfile:

        # Get number of trace files
        _, _, files = next(os.walk("traces"))
        log = np.zeros([len(files), 16])
        
        # Loop through files in traces/
        for i in range(len(files)):
            with open("traces/" + files[i]) as tracefile:

                # Read tracefile into trace array
                while tracefile.read(1):
                    trace.append(int(tracefile.read(1), "little"))

                # Add plaintext + trace into log
                log[i] = [np.loadtxt(inputfile), np.array(trace)]
                tracefile.close()
                
            # Reset trace array
            trace = []
            
        inputfile.close()

    np.save(logfile, log)
    logfile.close()