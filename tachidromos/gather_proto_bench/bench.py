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
#protobuf_path = "/home/christos/shab_vers/protobuf/bazel-bin/"
#protobuf_path = "/data/sanchez/users/shab/iaa/nikita/protobuf/bazel-bin/"
protobuf_path = "/home/christos/final/protobuf/"
benchmark_tmpl_path = "main.cc"
benchmark_source_path = "main_src.cc"

parser = argparse.ArgumentParser()
parser.add_argument("-p", "--proto", action="store_true", help="Build with protoc")
parser.add_argument("-ha", "--hacky", action="store_true", help="Generate setters/getters/schemas with hacky script")
parser.add_argument("-b", "--build", action="store_true", help="Build protoc output with make")
parser.add_argument("-r", "--run", action="store_true", help="Run tests")
parser.add_argument("-s", "--string", action="store_true", help="Include strings in .proto")

parser.add_argument('-w', '--width', type=int, default=1, help='Number of nested messages within a parent message.')
parser.add_argument('-d', '--depth', type=int, default=1, help='Depth of nested messages.')
parser.add_argument('-nv', '--num-varints', type=int, default=4, help='Number of varints in each message.')
parser.add_argument('-ns', '--num-strings', type=int, default=1, help='Number of strings in each message.')
args = parser.parse_args()

print("Width : ", args.width)
print("Depth : ", args.depth)
print("#varints: ", args.num_varints)
print("#strings: ", args.num_strings)
print("******************************************************")

if args.proto:
    # Generate .proto
    with open(f'exp/person.proto', 'w') as f:
        f.write(NestedMessageGenerator.generate_message(args.num_varints, args.num_strings, args.depth, args.width, args.string))
    print("Generated person.proto")

    # Compile proto
    res = subprocess.run(f'{protobuf_path}/protoc exp/person.proto --cpp_out=exp/stubs', shell=True, text=True, capture_output=True)
    if res.returncode != 0:
        print("Failed to compile proto: ", res.stderr)

    print("Generated person.pb.{cc,h} via protoc")

if args.hacky:
    # Generate setters.
    setters = NestedMessageGenerator.generate_setters(args.num_varints, args.num_strings, args.depth, args.width, args.string)
    gather_schema = NestedMessageGenerator.generate_gather_schema(args.num_varints, args.depth, args.width)
    scatter_schema = NestedMessageGenerator.generate_scatter_schema(args.num_varints, args.depth, args.width)
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
    setters = NestedMessageGenerator.generate_setters(args.num_varints, args.num_strings, args.depth, args.width, args.string)
    string_setters = NestedMessageGenerator.generate_only_string_setters(args.num_varints, args.num_strings, args.depth, args.width, args.string)
    with open(benchmark_tmpl_path, 'r') as f:
            lines = f.readlines()

    for j, line in enumerate(lines):
        if "<------------ SETTERS ------>" in line:
            lines.insert(j + 1, setters)
            break
    for j, line in enumerate(lines):
        if "<------------ NUM STRINGS ------>" in line:
            #lines.insert(j + 1, f'\tnum_strings = {NUM_STRINGS};\n')
            lines.insert(j + 1, f'\tnum_strings = {args.num_strings};\n')
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

    print("Finished setter/schema generation via protoc (our changes)")


if args.build:
    # Build benchmark
    res = subprocess.run(f'make -j', cwd='build', shell=True, text=True, capture_output=True)
    if res.returncode != 0:
        print("Failed to build benchmark: ", res.stderr)
    else:
        print("Build successful.")


if args.run:
    # Run benchmark
    res = subprocess.run(f'./test', cwd='build', shell=True, text=True, capture_output=True)
    result = res.stdout
    print(result)
    if res.returncode != 0:
        print("Problem running benchmark: ", res.stderr)
