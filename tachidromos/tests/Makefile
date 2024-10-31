# Define variables
PROTOC = /home/christos/final/protobuf/protoc
PROTO_SRC = test.proto
PROTO_GEN_DIR = ./protos
PROTO_CPP_OUT = $(PROTO_GEN_DIR)
CMAKE_BUILD_DIR = build
EXECUTABLE = test

# Default target
all: run run_ri run_rs run_rm

# Generate C++ code from .proto file
proto: $(PROTO_GEN_DIR)/test.pb.cc

$(PROTO_GEN_DIR)/test.pb.cc: $(PROTO_SRC)
	$(PROTOC) --cpp_out=$(PROTO_CPP_OUT) $(PROTO_SRC)

# Build the project using CMake
$(CMAKE_BUILD_DIR)/Makefile: $(PROTO_GEN_DIR)/test.pb.cc
	mkdir -p $(CMAKE_BUILD_DIR)
	cd $(CMAKE_BUILD_DIR) && cmake ..

build/$(EXECUTABLE): $(CMAKE_BUILD_DIR)/Makefile
	cd $(CMAKE_BUILD_DIR) && make -j

# Compile the project
build: $(CMAKE_BUILD_DIR)/Makefile
	cd $(CMAKE_BUILD_DIR) && make -j

# Run the executable
run: build/$(EXECUTABLE)
	./$(CMAKE_BUILD_DIR)/$(EXECUTABLE)

# run with repeated ints
run_ri: build/$(EXECUTABLE)
	./$(CMAKE_BUILD_DIR)/$(EXECUTABLE) ri

# run with repeated strings
run_rs: build/$(EXECUTABLE)
	./$(CMAKE_BUILD_DIR)/$(EXECUTABLE) rs

# run with repeated strings
run_rm: build/$(EXECUTABLE)
	./$(CMAKE_BUILD_DIR)/$(EXECUTABLE) rm

# Clean the build directory
clean:
	rm -rf $(CMAKE_BUILD_DIR) $(PROTO_GEN_DIR)/test.pb.cc $(PROTO_GEN_DIR)/test.pb.h

.PHONY: all proto build run clean
