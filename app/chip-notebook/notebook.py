#%%
import chipwhisperer.analyzer as cwa
# print("Hello world")

trace = []
with open("../aes-example/traces/trace00000", "rb") as f:

    # lines = f.readlines()
    # for line in lines:
    #     print(line.rstrip())
    
    while f.read(1):
        trace.append(int.from_bytes(f.read(1), "little"))
        # print(f.read(1))

trace = np.array(trace)
# %%
import matplotlib.pyplot as plt
import numpy as np
import scipy.signal as sig
q = 3

# n = np.linspace(0, len(trace), len(trace))
n = np.linspace(0, len(trace), len(trace))
n = sig.decimate(n, q)
trace = sig.decimate(trace, q)
plt.plot(n, trace)
plt.show()

# %%