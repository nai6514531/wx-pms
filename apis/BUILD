
cc_library(
    name = "feepb",
    srcs = [
        'cpp/protocol/v1/fee.grpc.pb.cc', 
        'cpp/protocol/v1/fee.pb.cc', 
    ],
    hdrs = [
        'cpp/protocol/v1/fee.grpc.pb.h',
        'cpp/protocol/v1/fee.pb.h',
    ],
    deps = [
        '@com_google_protobuf//:protobuf',
        '@com_github_grpc_grpc//:grpc++',
    ],
    visibility = ["//visibility:public"],
)