proto:
	./build-proto.sh

apis:
	bazel build //apis:all

build:
	bazel build -c dbg --spawn_strategy=standalone --cxxopt='-std=c++17' //apps:all

all: proto apis build

clean:
	rm -rf ./apis/cpp/*
	rm -f *.log
	bazel clean