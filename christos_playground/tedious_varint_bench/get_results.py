import subprocess
import csv
import numpy as np
import matplotlib.pyplot as plt


res = subprocess.run(f'sudo ./test', shell=True, text=True, capture_output=True)
if res.returncode != 0:
    print("Failed to run benchmark: ", res.stderr)

filename = 'results.csv'

numVarints = []
serTimes = []
deserTimes = []
compTimes = []
decompTimes = []
protoRatio = []
compRatio = []

with open(filename, mode='r') as file:
    csvFile = csv.reader(file)

    for lines in csvFile:
        numVarints.append(lines[0])
        serTimes.append(lines[2])
        deserTimes.append(lines[3])
        compTimes.append(lines[4])
        decompTimes.append(lines[5])
        protoRatio.append(lines[6])
        compRatio.append(lines[7])
    
    numVarints = numVarints[1:]
    serTimes = list(map(float, serTimes[1:]))
    deserTimes = list(map(float, deserTimes[1:]))
    compTimes = list(map(float, compTimes[1:]))
    decompTimes = list(map(float, decompTimes[1:]))


# Plot
plt.figure(figsize=(16, 12))
fig, ax = plt.subplots(2)
#x_ticks = np.linspace(float(min(serTimes)), float(max(serTimes)), 3)
#plt.xticks(x_ticks)
# ax[0].plot(numVarints, serTimes, marker='o', label='serialize')
ax[0].scatter(numVarints, serTimes, color='blue', marker='o', label='serialize')
ax[0].scatter(numVarints, compTimes, color='red', marker='o', label='compress')
ax[0].legend()
ax[0].grid()
ax[0].set_xlabel('Number of int32 fields')
ax[0].set_ylabel('Average time, ns')

#ax[1].plot(numVarints, deserTimes, marker='o', label='deserialize')
ax[1].scatter(numVarints, deserTimes, color='blue', marker='o', label='deserialize')
ax[1].scatter(numVarints, decompTimes, color='red', marker='o', label='decompress')
ax[1].legend()
ax[1].grid()
ax[1].set_xlabel('Number of int32 fields')
ax[1].set_ylabel('Average time, ns')

plt.subplots_adjust(hspace=0.5)

plt.savefig("res.pdf", format='pdf', bbox_inches='tight')
