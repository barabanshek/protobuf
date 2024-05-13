import subprocess
import argparse
import pandas as pd


def process_output(res, warmups=1):
    def get_line_mean(line, warmups):
        nums = [int(_) for _ in line.strip().split(", ")[1:]]
        nums = nums[warmups:]
        return round(sum(nums) / len(nums), 2)

    ser, deser, comp, decomp, scatter, gather, alloc, gather_schema, scatter_schema = None, None, None, None, None, None, None, None, None
    for line in res.split("\n"):
        if "deserialization" in line:
            deser = get_line_mean(line, warmups)
        elif "serialization" in line:
            ser = get_line_mean(line, warmups)
        elif "decompression" in line:
            decomp = get_line_mean(line, warmups)
        elif "compression" in line:
            comp = get_line_mean(line, warmups)
        elif "gather_schemas" in line:
            gather_schema = get_line_mean(line, warmups)
        elif "gather" in line:
            gather = get_line_mean(line, warmups)
        elif "scatter_schemas" in line:
            scatter_schema = get_line_mean(line, warmups)
        elif "scatter" in line:
            scatter = get_line_mean(line, warmups)
        elif "allocation" in line:
            alloc = get_line_mean(line, warmups)
    return ser, deser, gather_schema, gather, comp, scatter_schema, decomp, scatter, alloc


parser = argparse.ArgumentParser()
parser.add_argument('--widths', metavar='N', type=int, nargs='+', default=[1,2,4])
parser.add_argument('--depths', metavar='N', type=int, nargs='+', default=[1])
parser.add_argument('--ratios', metavar='N', type=int, nargs='+', default=[4])
parser.add_argument('--sets', metavar='N', type=int, nargs='+', default=[1, 2, 3, 4])
args = parser.parse_args()

df = []
col_names = ["width", "depth", "#varint", "#string", "serialization", "deserialization", "gather_schema", "gather", "compression", "scatter_schema", "decompression", "scatter", "allocation"]
for width in args.widths:
    for depth in args.depths:
        for ratio in args.ratios:
            for fset in args.sets:
                num_varint = ratio * fset
                num_string = fset

                cmd = f'python3 bench.py --proto --build --run --string -w {width} -d {depth} -nv {num_varint} -ns {num_string}'
                print(cmd)

                res = subprocess.run(cmd, shell=True, text=True, capture_output=True).stdout
                print(res)

                ser, deser, gather_schema, gather, comp, scatter_schema, decomp, scatter, alloc = process_output(res)
                elem = [width, depth, num_varint, num_string, ser, deser, gather_schema, gather, comp, scatter_schema, decomp, scatter, alloc]

                df += [elem]

data_frame = pd.DataFrame(df, columns=col_names)
print(data_frame)
