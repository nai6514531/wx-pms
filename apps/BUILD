cc_library(
    name = "3rd_md5",
    srcs = ["3rd/md5.cc"],
    hdrs = ["3rd/md5.hpp"],
    visibility = ["//visibility:public"]
)

cc_library(
    name = "3rd_json",
    hdrs = ["3rd/json.hpp"],
    visibility = ["//visibility:public"]
)

cc_library(
    name = "utils_strings",
    srcs = ["utils/strings.cc"],
    hdrs = ["utils/strings.hpp", "3rd/bin2ascii.hpp"],
    deps = [":3rd_md5"]
)


cc_binary(
    name = "client",
    srcs = [
        "client.cc", 
    ],
    copts = [],
    deps = [
        ":3rd_json",
        ":utils_strings",
        "@com_github_grpc_grpc//:grpc++",
        "//apis:feepb",
    ],
)

cc_binary(
    name = "server",
    srcs = [
        "server.cc", 
    ],
    copts = [],
    deps = [
        "@com_github_grpc_grpc//:grpc++",
        "//apis:feepb",
    ],
)