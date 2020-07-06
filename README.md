- [问题](#问题)
- [设计](#设计)
  - [组件和模块](#组件和模块)
  - [数据流](#数据流)
  - [接口和协议](#接口和协议)
  - [错误码和结构体等定义](#错误码和结构体等定义)
  - [库表设计](#库表设计)
  - [安全性](#安全性)
  - [代码组织](#代码组织)
  - [扩展性](#扩展性)
- [编译](#编译)
  - [本地环境](#本地环境)
  - [三方依赖](#三方依赖)
- [操作](#操作)
- [遇到的问题](#遇到的问题)
- [TODO](#TODO)

## 问题

终端扣费管理系统·设计：
* 实现一个扣费服务管理系统的客户端和服务端。
* 拥有查看服务列表，开通扣费服务，关闭扣费服务，新增扣费服务等功能。
* `C++`、`gRPC` 实现，`Bazel` 编译管理依赖，考虑数据、传输等安全。


## 设计

### 组件和模块

分二个模块：

1）客户端，发送操作请求(获取扣费服务列表，新增扣费服务，开通扣费服务，关闭扣费服务)。

2）服务端，接收和处理客户端的请求。

其中客户端与服务端交互有：

* 获取正常状态的扣费服务列表(`getlist`)
* 获取已失效状态的扣费服务列表(`getexpiredlist`)
* 开通扣费服务(`open {"id":1}`)
* 关闭扣费服务(`close {"id":1}`)
* 新增扣费服务记录(`create {"title":"深圳市地铁微信免密支付","desc":"深圳市地铁相关运营主体"}`)

### 数据流

用户与 `client` 端交互时，采用 `命令 JSON包体` 的格式，`client` 解析 `JSON` 包体并转为 `protobuf` 格式， `client` 与 `server` 交互采用 `grpc/protobuf`， `server`端再与 `mysql` 进行通信;

`client` 和 `admin` 收到 `server` 返回，以及 `server` 收到 `client` 和 `admin` 的请求，都做了转 `JSON` 输出，方便查看。 

### 接口和协议

对 `DeductionResp` 一些说明：
`success` 表示服务端处理是否成功
`message` 消息提示信息
`code` 返回码，定义了系统异常的枚举
`data` 服务端返回的数据结构体

详细 `proto` 设计可见 [./apis/protocol/v1/deduction.proto](./apis/protocol/v1/deduction.proto)


### 错误码和结构体等定义

相关的有 消息提示信息，返回码 定义都在 [./apps/utils/enum.hpp](./apps/utils/enum.hpp) 中。

### 库表设计

共一张表：

* `deduction` 用户的扣费服务列表，对应接口的增加，修改，查询都是操作这张表。

详细的数据表的 `schema` 可见 [./confs/deduction.sql](./confs/deduction.sql)


### 安全性

由于时间原因，并没有设计传输安全相关的操作，但是有调研这方面的技术实现。

* 开启 `gRPC` 的 `secure credentials`，添加证书操作可参考[示例](https://github.com/grpc/grpc/issues/9593#issuecomment-277946137)。
* 用户输入校验。对每个具体字段的长度，大小，格式等，也包括sql注入，这里没有做校验。
* 对于水平越权以及垂直越权的校验。

### 代码组织


`apis` 目录下定义的是proto相关的内容， `proto` 文件通过 `protoc` 工具链来生成(`build_proto.sh`)，并且将生成的代码文件一起上库，这样操作主要是考虑到协议变更不频繁，客户端和服务端可以共用一份协议文件。

`apps` 目录下，`utils` 和 `3rd` 为公用依赖。

执行文件的 `main` 入口文件直接置于 `apps` 下，如当前 `client.cc`, `server.cc`。由于目前接口不多并且时间也比较紧张，所以也将具体执行类和 `main` 置于同一文件中。随着接口和逻辑复杂性的提高，应单独提取出执行类到具体的业务目录下。

```text
.
├── Makefile                          # 对 bazel 构建和清理等命令的简单包装
├── README.md                         # 本文档
├── WORKSPACE                         # bazel 的 workspace
├── apis                              # proto 协议和其生成文件目录
│   ├── BUILD                         # apis 的 build 文件，供 apps 依赖
│   ├── cpp                           # 以下是根据协议生成的 cpp 代码
│   │   └── protocol
│   │       └── v1
│   │           ├── deduction.grpc.pb.cc
│   │           ├── deduction.grpc.pb.h
│   │           ├── deduction.pb.cc
│   │           └── deduction.pb.h
│   └── protocol                      # 协议目录，按版本分
│       └── v1                        # v1 为实验中用到的 proto
│           └── deduction.proto
├── apps                              # 服务代码主目录
│   ├── 3rd                           # 三方依赖，由于多是单文件，所以放在一起
│   │   ├── bin2ascii.hpp             #    十六进制和字符串间的转换
│   │   ├── json.hpp                  #    json 处理相关
│   │   ├── md5.cc                    #    md5
│   │   ├── md5.hpp             
│   │   └── sql                       #    mysqlplus第三方库
│   │       ├── mysqlplus.h
│   │       └── (sub dirs omitted)
│   ├── BUILD                         # 服务端 build 文件，依赖了 apis 的build
│   ├── client.cc               # client app的主逻辑
│   ├── server.cc               # server app的主逻辑
│   └── utils                         # 工具箱
│       ├── config.cc                 # 定义获取配置文件的类
│       ├── config.hpp
│       ├── strings.cc                # 常用字符串处理函数
│       ├── strings.hpp
│       └── enum.hpp                  # 枚举相关定义
├── build_proto.sh                    # proto 文件处理脚本
├── confs                             # 配置
│   ├── deduction.sql                 # 库表结构
│   └── server.json                   # server 配置
└── mysql.BUILD                       # mysql的build，依赖处理

```

## 编译

### 本地环境
```
MacOS Mojave 10.14.5

gcc version 6.5.0

Bazel: 3.3.0
```

对编译做了个简单的 `Makefile` 包装：

```makefile
proto:
	./build-proto.sh

apis:
	bazel build //apis:all

apps:
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
```
make proto: 用于生成c++版本的proto。
make apis: 构建接口的依赖。
make apps: 构建app的依赖。

用户需要在项目目录下运行make all
启动客户端 ./bazel-bin/apps/client
启动服务端 ./bazel-bin/apps/server

### 三方依赖

设计上尽量减少依赖或尽量使用轻量级依赖。除了`gRPC` 和 `protobuf`，还有以下依赖：

* [JSON](https://github.com/nlohmann/json) , 对自定义结构体的序列化和反序列化处理非常方便（自定义 `to_json` 和 `from_json`）

* [mysql modern cpp](https://github.com/daotrungkien/mysql-modern-cpp) `MySQL` 包装。

## 操作


首先需要配置对应的数据库和服务器，配置可见 `confs` 目录。对配置文件的说明如下：

配置里的对象全部可以 `JSON` 对象序列化和反序列化，关联的 `JSON` 字段见 `defs.hpp` 和 `connect_options_jsonify.hpp`，除了 `DB` 连接选项外，其他字段都是必选字段。

```json
{
  // server 配置
  "server": {
      "endpoint": "127.0.0.1:50051"
  },
  // 数据库配置
  "db": {
      "server": "127.0.0.1",
      "port": 3306,
      "username": "root",
      "password": "password",
      "dbname": "payment"
  }
}
```
`help` 命令：

对 `client`:

```
--------------------------------------------------------------------------------
| command |   sub command/data  |                   descriptions               |
--------------------------------------------------------------------------------
|close     (args)                eg:close {"id":1}                             |
--------------------------------------------------------------------------------
|create    (args)                eg:create {"title":"测试","desc":"程序添加进去的"}|
--------------------------------------------------------------------------------
|exit      (no args)             exit program. `exit` can also be `quit`, `bye`|
--------------------------------------------------------------------------------
|getexpiredlist(no args)         eg:getexpiredlist                             |
--------------------------------------------------------------------------------
|getlist   (no args)             eg:getlist                                    |
--------------------------------------------------------------------------------
|help                                                                          |
|          (no args)             `help` can also be `man`, `info`              |
|          specific_cmd          help info on specific command                 |
--------------------------------------------------------------------------------
|open      (args)                eg:open {"id":1}                              |
--------------------------------------------------------------------------------
```


## 遇到的问题
  
1. 安装集成开发环境遇到的问题,安装grpc, protoc, bazel以及在vscode如何调试c++项目[总结](https://www.yuque.com/xiaolei-arwvs/kseonb/dthhbb)。
2. 如何将命令行的json字符串映射到proto中(通过JsonStringToMessage方法)。
3. 如何将结构体和mysql进行映射？(未解决)
4. 客户端会偶现内存溢出的问题(未解决)。
5. 系统升级到macOs Catalina后，在vscode中无法调试(未解决)。
6. 如何将现有服务端分离成controller和service层。并且提供数据库连接池(现有的方式是一个请求进行一次数据库连接释放操作)的操作。

## TODO

1. 增加系统日志，方便调试以及定位bug。
2. 将服务端的接口实现分离成具体的执行类。提供数据model层(可以减少大量重复代码)。减轻server.cc中的代码量。
3. 增加程序的健壮性，对于异常的错误处理以及偶现的内存溢出提供更完善的容错机制，而不是让程序直接崩溃。
4. 添加ssl层，对数据进行水平越权和垂直越权的校验。
5. 对接性能监控平台，当程序运行异常时，可以收到相应的告警服务。
6. 对接google test。增加测试用例。
7. 集成cicd，将服务进行docker化部署。