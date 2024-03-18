all: protoc_middleman main_cpp

main_cpp : main.cc
	pkg-config --cflags protobuf  # fails if protobuf is not installed
	g++ -O3 -g -std=c++14 -I/home/christos/qpl_install_dir/include main.cc dummy.pb.cc -o test `pkg-config --cflags --libs protobuf` -L/home/christos/qpl_install_dir/lib -lqpl

protoc_middleman: dummy.proto
	protoc --cpp_out=. dummy.proto

clean:
	rm test dummy.pb.cc dummy.pb.h
