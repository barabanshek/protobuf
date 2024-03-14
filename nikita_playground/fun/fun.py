import subprocess

# Env.
protobuf_path = "/home/nikita/protobuf"
benchmark_path = "main.cc"

def generate_message(num_lines):
    # Header of the message
    message_content = '''syntax = "proto2";

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
        msg += f'   person.set_age_{i+1}({i+1});\n'
    return msg

#
# Run fun.
#
N = 10

for i in range(1, N + 1):
    # Generate .proto
    with open(f'exp/person.proto', 'w') as f:
        f.write(generate_message(i))

    # Compile proto
    res = subprocess.run(f'{protobuf_path}/protoc exp/person.proto --cpp_out=exp/stubs', shell=True, text=True, capture_output=True)
    if res.returncode != 0:
        print("Failed to compile proto: ", res.stderr)

    # Generate setters.
    setters = generate_setters(i)
    with open(benchmark_path, 'r') as f:
         lines = f.readlines()
         original_lines = lines.copy()

    for j, line in enumerate(lines):
         if "<------------ SETTERS ------>" in line:
             lines.insert(j + 1, setters + '\n')
             break

    with open(benchmark_path, 'w') as f:
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
        print(f'iteration #{i}: {i} int32 fields, {result}')

    # Restore original benchmark
    with open(benchmark_path, 'w') as f:
        f.writelines(original_lines)
