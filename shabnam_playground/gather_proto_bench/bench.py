import subprocess
import re
import matplotlib.pyplot as plt
from proto_generator import *

import argparse

#
# Usage
#
# * export PROTO_PATH
# * (first time run): mkdir build; cd build; cmake ..
# * python3 fun.py 
#

# Env.
protobuf_path = "/home/christos/shab_vers/protobuf/bazel-bin/"
benchmark_tmpl_path = "main.cc"
benchmark_source_path = "main_src.cc"

parser = argparse.ArgumentParser()
parser.add_argument("-p", "--proto", action="store_true", help="Build with protoc")
parser.add_argument("-ha", "--hacky", action="store_true", help="Generate setters/getters/schemas with hacky script")
parser.add_argument("-b", "--build", action="store_true", help="Build protoc output with make")
parser.add_argument("-r", "--run", action="store_true", help="Run tests")
parser.add_argument("-s", "--string", action="store_true", help="Include strings in .proto")
args = parser.parse_args()

#
# Run fun.
#
W = 3
D = 4
START = 1
N = 3
STEP = 1

# how many varints to generate in the proto message
NUM_VARINTS = 4
# how many strings to generate in the proto message
NUM_STRINGS = 1 

print("Width : ", W)
print("Depth : ", D)
print("Varint range : ", "[", START*STEP, ",", N*STEP, "]")
print("******************************************************")

for i in range(START, N + 1):
    #n_fields = i * STEP
    n_fields = i * NUM_VARINTS
    n_strings = i * NUM_STRINGS

    if args.proto:
        # Generate .proto
        with open(f'exp/person.proto', 'w') as f:
            #f.write(NestedMessageGenerator.generate_message(n_fields, NUM_STRINGS, D, W, args.string))
            f.write(NestedMessageGenerator.generate_message(n_fields, n_strings, D, W, args.string))

        # Compile proto
        res = subprocess.run(f'{protobuf_path}/protoc exp/person.proto --cpp_out=exp/stubs', shell=True, text=True, capture_output=True)
        if res.returncode != 0:
            print("Failed to compile proto: ", res.stderr)

        print("Finished protoc")

    if args.hacky:
        # Generate setters.
        #setters = NestedMessageGenerator.generate_setters(n_fields, NUM_STRINGS, D, W, args.string)
        setters = NestedMessageGenerator.generate_setters(n_fields, n_strings, D, W, args.string)
        gather_schema = NestedMessageGenerator.generate_gather_schema(n_fields, D, W)
        scatter_schema = NestedMessageGenerator.generate_scatter_schema(n_fields, D, W)
        with open(benchmark_tmpl_path, 'r') as f:
                lines = f.readlines()

        for j, line in enumerate(lines):
            if "<------------ SETTERS ------>" in line:
                lines.insert(j + 1, setters)
                break
        for j, line in enumerate(lines):
            if "<------------ GATHER SCHEMA ------>" in line:
                lines.insert(j + 1, gather_schema)
                break
        for j, line in enumerate(lines):
            if "<------------ SCATTER SCHEMA ------>" in line:
                lines.insert(j + 1, scatter_schema)
                break

        with open(benchmark_source_path, 'w') as f:
            f.writelines(lines)

        print("Finished hacky setter/schema generation")
    else:
        # Generate setters.
        #setters = NestedMessageGenerator.generate_setters(n_fields, NUM_STRINGS, D, W, args.string)
        #string_setters = NestedMessageGenerator.generate_only_string_setters(n_fields, NUM_STRINGS, D, W, args.string)
        setters = NestedMessageGenerator.generate_setters(n_fields, n_strings, D, W, args.string)
        string_setters = NestedMessageGenerator.generate_only_string_setters(n_fields, n_strings, D, W, args.string)
        with open(benchmark_tmpl_path, 'r') as f:
                lines = f.readlines()

        for j, line in enumerate(lines):
            if "<------------ SETTERS ------>" in line:
                lines.insert(j + 1, setters)
                break
        for j, line in enumerate(lines):
            if "<------------ NUM STRINGS ------>" in line:
                #lines.insert(j + 1, f'\tnum_strings = {NUM_STRINGS};\n')
                lines.insert(j + 1, f'\tnum_strings = {n_strings};\n')
                break
        for j, line in enumerate(lines):
            if "<------------ STRING SETTERS ------>" in line:
                lines.insert(j + 1, string_setters)
                break
        for j, line in enumerate(lines):
            if "<------------ GATHER SCHEMA ------>" in line:
                lines.insert(j + 1, "\t\tmessages[i].generate_schema(gather_schema);\n")
                lines.insert(j + 2, "\t\tmessages[i].generate_scatter_sizes(sizes);\n")
                break
        for j, line in enumerate(lines):
            if "<------------ SCATTER SCHEMA ------>" in line:
                lines.insert(j + 1, "\t\tout_messages[i].generate_schema(scatter_schema);\n")
                break

        with open(benchmark_source_path, 'w') as f:
            f.writelines(lines)

        print("Finished protoc setter/schema generation")


    if args.build:
        # Build benchmark
        res = subprocess.run(f'make -j', cwd='build', shell=True, text=True, capture_output=True)
        if res.returncode != 0:
            print("Failed to build benchmark: ", res.stderr)
        else:
            print("Build successful")


    if args.run:
        # Run benchmark
        res = subprocess.run(f'sudo ./test', cwd='build', shell=True, text=True, capture_output=True)
        result = res.stdout
        print(f'iteration #{i}: {n_fields} int32 fields and {n_strings} string fields')
        print(result)
        if res.returncode != 0:
            print("Problem running benchmark: ", res.stderr)
