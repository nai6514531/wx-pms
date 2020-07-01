proto:
	./build-proto.sh

apis:
	bazel build //apis:all

build:
	bazel build --cxxopt='-std=c++17'  

all: proto apis build

clean:
	rm -rf ./apis/cpp/*
	rm -f *.log
	bazel clean