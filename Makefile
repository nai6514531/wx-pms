proto:
	./build-proto.sh

apis:
	bazel build //apis:all

build:
	bazel build -c dbg --spawn_strategy=standalone --cxxopt='-std=c++17' //apps:all

server:
	bazel run --cxxopt='-std=c++17' //apps:server

client:
	bazel run --cxxopt='-std=c++17' //apps:client

all: proto apis build

clean:
	rm -rf ./apis/cpp/*
	rm -f *.log
	bazel clean