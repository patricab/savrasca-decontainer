#%%
import chipwhisperer.analyzer as cwa
# print("Hello world")

with open("../aes-example/traces/trace00000", "rb") as f:

    # lines = f.readlines()
    # for line in lines:
    #     print(line.rstrip())
    
    while f.read(1):
        print(f.read(1))
