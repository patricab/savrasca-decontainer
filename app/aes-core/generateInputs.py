#!/usr/bin/env python

"""
* Send 16 bytes of random plaintext as input to AES function (main.c)
* Save plaintext to csv file
"""
#%%
# Configure serial
import serial
ser = serial.Serial("/dev/ttyACM1")

#%% Generate random plaintext
import sys
import random
import numpy as np
rndSeed = 0 # default random seed

# if (len(sys.argv) > 1):
# 	rndSeed = int(sys.argv[1]) # choose random seed from command line

plaintext = np.zeros([16])
# output = np.zeros([16])
output = []

with open("inputs.csv", "wb") as file:
	random.seed(rndSeed) # set random seed

	# Generate and save plaintext
	for j in range(16):
		byte = random.randint(0,255)
		plaintext[j] = byte
		ser.write(byte)

	ser.write(b'\n')	
	np.savetxt(file, plaintext)

file.close()

#%%
# Store outputs
with open("outputs.csv", "wb") as file:
	while True:
		c = ser.read()
		if c == "\n":
			break
		output.append = ser.read()

	output = np.array(output)
	np.savetxt(file, output)

ser.close()
file.close()
