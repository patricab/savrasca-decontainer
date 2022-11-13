#!/usr/bin/env python

"""
* Send 16 bytes of random plaintext as input to AES function (main.c)
* Save plaintext to csv file
"""
#%%
import sys
if (len(sys.argv) > 1):
	rndSeed = int(sys.argv[1]) # choose random seed from command line
else:
	rndSeed = 0 # default random seed

#%% Generate random plaintext
import random
import serial
import numpy as np
ser = serial.Serial("/dev/ttyACM0")

# ciphertext = b'7649ABAC8119B246CEE98E9B12E9197D'
# plaintext = [0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a]

plaintext = np.zeros([16])

with open("inputs.csv", "ab") as file:
	random.seed(rndSeed) # set random seed

	# Generate and save plaintext
	for j in range(16):
		byte = random.randint(0,255)
		plaintext[j] = byte

	np.savetxt(file, plaintext)

file.close()

#%%
# Send and recieve from cryoto device
ser.write(plaintext)
output = ser.read(32)
ser.close()

print(output)
# Parse return string into hex array
output = [output[i:i+2] for i in range(0, len(output), 2)]
output = [int(output[i], 16) for i in range(len(output))]

#%%
# Store outputs
with open("outputs.csv", "ab") as file:
	output = np.array(output)
	np.savetxt(file, output)

file.close()
