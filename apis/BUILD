
cc_library(
    name = "deduction",
    srcs = [
        'cpp/protocol/v1/deduction.grpc.pb.cc', 
        'cpp/protocol/v1/deduction.pb.cc', 
    ],
    hdrs = [
        'cpp/protocol/v1/deduction.grpc.pb.h',
        'cpp/protocol/v1/deduction.pb.h',
    ],
    deps = [
        '@com_google_protobuf//:protobuf',
        '@com_github_grpc_grpc//:grpc++',
    ],
    visibility = ["//visibility:public"],
)