
# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "mysql_build",
    srcs = ["lib/libmysqlclient.dylib"],
    hdrs = glob(["include/**"]),
    includes = ["include"],
    visibility = ["//visibility:public"]
)