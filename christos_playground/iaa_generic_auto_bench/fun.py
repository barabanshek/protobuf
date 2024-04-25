import subprocess
import re
import matplotlib.pyplot as plt
from proto_generator import *

#
# Usage
#
# * export PROTO_PATH
# * (first time run): mkdir build; cd build; cmake ..
# * python3 fun.py 
#

# Env.
protobuf_path = "/data/sanchez/users/shab/iaa/nikita/protobuf/"
benchmark_tmpl_path = "main.cc"
benchmark_source_path = "main_src.cc"

#
# Run fun.
#
W = 1
D = 1
N = 40
STEP = 10

results_cnt = []
results_ser_time = []
results_deser_time = []
for i in range(1, N + 1):
    n_fields = i * STEP

    # Generate .proto
    with open(f'exp/person.proto', 'w') as f:
        f.write(NestedMessageGenerator.generate_message(n_fields, D, W))

    # Compile proto
    res = subprocess.run(f'{protobuf_path}/protoc exp/person.proto --cpp_out=exp/stubs', shell=True, text=True, capture_output=True)
    if res.returncode != 0:
        print("Failed to compile proto: ", res.stderr)

    # Generate setters.
    setters = NestedMessageGenerator.generate_setters(n_fields, D, W)
    with open(benchmark_tmpl_path, 'r') as f:
         lines = f.readlines()

    for j, line in enumerate(lines):
         if "<------------ SETTERS ------>" in line:
             lines.insert(j + 1, setters + '\n')
             break

    with open(benchmark_source_path, 'w') as f:
        f.writelines(lines)

    # Build benchmark
    res = subprocess.run(f'make -j', cwd='build', shell=True, text=True, capture_output=True)
    if res.returncode != 0:
        print("Failed to build benchmark: ", res.stderr)

    # Run benchmark
    res = subprocess.run(f'./fun', cwd='build', shell=True, text=True, capture_output=True)
    if res.returncode != 0:
        print("Failed to run benchmark: ", res.stderr)
    else:
        result = res.stdout
        print(f'iteration #{i}: {n_fields} int32 fields, {result}')

    # Parse results
    if "ERROR" in result:
        print("Error found, stop here!")
        exit(-1)
    results_cnt.append((int)(n_fields))
    match = re.search(r'serialize took = ([0-9]*) \[ns\], size.*', result)
    results_ser_time.append((int)(match.group(1)))
    match = re.search(r'deserialize took = ([0-9]*) \[ns\], size.*', result)
    results_deser_time.append((int)(match.group(1)))

# Plot
plt.figure(figsize=(16, 12))
fig, ax = plt.subplots(2)
ax[0].plot(results_cnt, results_ser_time, marker='o', label='compression')
ax[0].legend()
ax[0].grid()
ax[0].set_xlabel('Number of int32 fields')
ax[0].set_ylabel('Average time, ns')

ax[1].plot(results_cnt, results_deser_time, marker='o', label='decompression')
ax[1].legend()
ax[1].grid()
ax[1].set_xlabel('Number of int32 fields')
ax[1].set_ylabel('Average time, ns')

plt.subplots_adjust(hspace=0.5)

plt.savefig("iaa_res.pdf", format='pdf', bbox_inches='tight')
