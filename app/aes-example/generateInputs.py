#!/usr/bin/env python

"""
* Send 16 bytes of random plaintext as input to AES function (main.c)
* Save plaintext to csv file
"""

#%% Generate random plaintext
import sys
import random
import numpy as np
rndSeed = 0 # default random seed

if (len(sys.argv) > 1):
	rndSeed = int(sys.argv[1]) # choose random seed from command line

plaintext = np.zeros([16])
with open("inputs.csv", "ab") as file:
	random.seed(rndSeed) # set random seed

	# Generate and save plaintext
	for j in range(16):
		byte = random.randint(0,255)
		print(chr(byte))
		plaintext[j] = byte

	# Save to inputfile
	np.savetxt(file, plaintext)

	print() # endline

	file.close()