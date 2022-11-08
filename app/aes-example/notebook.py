#%% Read from trace file, append to array
import numpy as np

key = np.array([0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c])

with open("trace.npy", "rb") as f:
    trace = np.load(f, allow_pickle=True)

f.close()

#%% Parse output
out = []
for line in  open("output.txt", "r"):
    if "Key" in line:
        out.append(line.split(" "))

out = [out[k][1][0:32] for k in range(len(out))]
ciph = [[int(out[k][i:i+2], base=16) for i in range(0, len(out[0]), 2)] for k in range(len(out))]

#%% setup CW project
import chipwhisperer as cw

prj = cw.create_project("project")

for i in range(len(trace)):
    tr = cw.Trace(trace[i][1], trace[i][0], ciph[i], key)
    prj.traces.append(tr)
prj.save()

#%% setup/execute CW attack 
import chipwhisperer as cw
import chipwhisperer.analyzer as cwa

# prj = cw.open_project("project")
attack = cwa.cpa(prj, cwa.leakage_models.sbox_output)
res = attack.run()
print(res)