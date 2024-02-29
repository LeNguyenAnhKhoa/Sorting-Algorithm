import numpy as np
import time
for t in range(10):
    filename = "TEST/test" + str(t+1) + ".inp"
    with open(filename, "r") as file:
        x = file.read().splitlines()
        a = np.array(x).astype(float)
        start = time.time()
        a.sort()
        end = time.time()
        for i in range(len(a)-1):
            assert a[i] <= a[i+1]
        print(f"Test{t+1}: {int((end - start)*1000)}ms")