### Results

Now works with custom protobuf version!
Building using cmake (make version kept for bookeeping)

Instructions:
(first time) touch dummy.pb.cc
(first time) export PROTO\_PATH=/home/your/proto/path
mkdir build ; cd build ; cmake ..
cd ..
python3 cmake\_get\_results.py

Also don't forget to change the proto path inside cmake\_get\_results.py

![Current tedious bench protobuf results in spr-ext-1](https://github.com/barabanshek/protobuf/blob/christos/christos_playground/tedious_varint_bench/res.pdf)
