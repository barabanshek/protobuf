import subprocess
import re
import matplotlib.pyplot as plt
import random

# Env.
protobuf_path = "/home/nikita/protobuf"
benchmark_tmpl_path = "main.cc"
benchmark_source_path = "main_src.cc"

def generate_message(num_lines):
    # Header of the message
    message_content = '''syntax = "proto3";

message Person {
    '''

    # Generate each line based on the number of lines specified
    for i in range(num_lines):
        message_content += f'  optional int32 age_{i+1} = {i+1};\n'

    # Footer of the message
    message_content += '}\n\n'

    return message_content

def generate_setters(num_lines):
    msg = ""
    for i in range(num_lines):
        val = 0
        size = random.randint(1, 4)
        for j in range(size):
            val |= (random.randint(0, 255) << j * 8)
        msg += f'   person.set_age_{i+1}({val} + i % 8);\n'
    return msg

#
# Run fun.
#
N = 40
STEP = 10

results_cnt = []
results_ser_time = []
results_deser_time = []
for i in range(1, N + 1):
    n_fields = i * STEP

    # Generate .proto
    with open(f'exp/person.proto', 'w') as f:
        f.write(generate_message(n_fields))

    # Compile proto
    res = subprocess.run(f'{protobuf_path}/protoc exp/person.proto --cpp_out=exp/stubs', shell=True, text=True, capture_output=True)
    if res.returncode != 0:
        print("Failed to compile proto: ", res.stderr)

    # Generate setters.
    setters = generate_setters(n_fields)
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
plt.figure()
fig, ax = plt.subplots(2)
ax[0].plot(results_cnt, results_ser_time, marker='o', label='serialize')
ax[0].legend()
ax[0].grid()
ax[0].set_xlabel('Number of int32 fields')
ax[0].set_ylabel('Average time, ns')

ax[1].plot(results_cnt, results_deser_time, marker='o', label='deserialize')
ax[1].legend()
ax[1].grid()
ax[1].set_xlabel('Number of int32 fields')
ax[1].set_ylabel('Average time, ns')

plt.savefig("res.pdf", bbox_inches='tight')
