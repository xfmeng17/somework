# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
  name = "test2",
  srcs = ["test2.cc"],
  copts = [],
  deps = [
    "//bazel/test1:test1",
    "@googlegtest//:gtest",
    "@googlegtest//:gtest_main",
  ],
)