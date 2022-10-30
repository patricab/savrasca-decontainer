#!/usr/bin/env python

"""
* Send random plaintext as input to AES function (main.c)
* Save plaintext + tracedata in numpy file
"""

"""
this file generates one input of 16 plaintexts and one input of 4 random bits (for the mask)
for the DPA Contest v4 input
"""

#%% Generate random plaintext
import sys
import random
import numpy as np
rndSeed = 0 # default random seed
num = 1

if (len(sys.argv) > 1):
	randsSeed = num = int(sys.argv[1]) # choose random seed from command line

# file = open("inputs.csv", 'a')	# the file that will contain plaintexts and rnd inputs
plaintext = np.zeros([16])
# with open("inputs.csv", "wb") as file:
with open("inputs.csv", "wb") as file:
	random.seed(rndSeed) # set random seed

	# plaintext
	for i in range(num):
		for j in range(16):
			byte = random.randint(0,255)
			print(chr(byte))
			plaintext[j] = byte

		np.savetxt(file, plaintext)

	print() # endline
	# np.savetxt(file, plaintext, fmt="%x")

	file.close()

# with open("inputs.csv", "rb") as file:
# 	n = [np.load(file), np.load(file)]
# 	print(n)
# 	file.close()