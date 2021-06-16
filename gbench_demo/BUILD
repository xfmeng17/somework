package(default_visibility = ["//visibility:public"])

cc_binary(
  name = "stl_map_bench",
  srcs = [
    "stl_map_bench.cc",
  ],
  copts = [
    "-Wno-unused-function",
    "-Wno-unused-but-set-variable",
  ],
  deps = [
    "@git_googlebentchmark//:benchmark_main",
  ],
)

cc_binary(
  name = "readme_demo",
  srcs = [
    "readme_demo.cc",
  ],
  copts = [
    "-Wno-unused-function",
    "-Wno-unused-but-set-variable",
  ],
  deps = [
    "@git_googlebentchmark//:benchmark_main",
  ],
)