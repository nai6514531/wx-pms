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

cc_library(
    name = "utils_config",
    srcs = ["utils/config.cc"],
    hdrs = ["utils/config.hpp"],
    deps = [":3rd_json"]
)

cc_library(
    name = "utils_enum",
    hdrs = ["utils/enum.hpp"],
)


cc_library(
    name = "3rd_mysqlplus",
    hdrs = [
        "3rd/sql/mysqlplus.h", 
        "3rd/sql/polyfill/datetime.h",
        "3rd/sql/polyfill/function_traits.h",
        "3rd/sql/polyfill/optional.hpp"
    ],
    deps = [
        "@usr_local//:mysql_build"
    ],
    visibility = ["//visibility:public"]
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
        "//apis:deduction",
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
        "//apis:deduction",
        ":3rd_mysqlplus",
        ":3rd_json",
        ":utils_config",
        ":utils_enum"
    ],
)