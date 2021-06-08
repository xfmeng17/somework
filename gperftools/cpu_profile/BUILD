# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
  name = "test01",
  srcs = ["test01.cc"],
  copts = [
    "-g",
  ],
  linkopts = [
    "-lprofiler",
  ],
  deps = [],
)

cc_binary(
  name = "test02",
  srcs = ["test02.cc"],
  copts = [
    "-g",
    "-o0",
    # "-std=c++17",
  ],
  linkopts = [
    "-lprofiler",
    # "-static",
  ],
  # linkshared = True,
  deps = [],
)
