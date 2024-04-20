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
protobuf_path = "/home/christos/protobuf"
benchmark_tmpl_path = "main.cc"
benchmark_source_path = "main_src.cc"

#
# Run fun.
#
W = 2
D = 4
START = 2
N = 2
STEP = 10

print("Width : ", W)
print("Depth : ", D)
print("Varint range : ", "[", START*STEP, ",", N*STEP, "]")
print("******************************************************")

for i in range(START, N + 1):
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
    schema = NestedMessageGenerator.generate_schema(n_fields, D, W)
    out_schema = NestedMessageGenerator.generate_out_schema(n_fields, D, W)
    with open(benchmark_tmpl_path, 'r') as f:
            lines = f.readlines()

    for j, line in enumerate(lines):
        if "<------------ SETTERS ------>" in line:
            lines.insert(j + 1, setters)
            break
    for j, line in enumerate(lines):
        if "<------------ SCHEMA ------>" in line:
            lines.insert(j + 1, schema)
            break
    for j, line in enumerate(lines):
        if "<------------ SCATTER SCHEMA ------>" in line:
            lines.insert(j + 1, out_schema)
            break

    with open(benchmark_source_path, 'w') as f:
        f.writelines(lines)

    # Build benchmark
    res = subprocess.run(f'make -j', cwd='build', shell=True, text=True, capture_output=True)
    if res.returncode != 0:
        print("Failed to build benchmark: ", res.stderr)

    # Run benchmark
    res = subprocess.run(f'sudo ./test', cwd='build', shell=True, text=True, capture_output=True)
    result = res.stdout
    print(f'iteration #{i}: {n_fields} int32 fields')
    print(result)
    if res.returncode != 0:
        print("Problem running benchmark: ", res.stderr)
