# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
  name = "test01",
  srcs = ["test01.cc"],
  copts = [
    "-g",
    "-o0",
  ],
  linkopts = [
    "-ltcmalloc",
  ],
)