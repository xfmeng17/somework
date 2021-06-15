load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

git_repository(
  name = "git_googletest",
  remote = "https://github.com/google/googletest",
  tag = "release-1.10.0",
)

http_archive(
  name = "http_googletest",
  sha256 = "9bf1fe5182a604b4135edc1a425ae356c9ad15e9b23f9f12a02e80184c3a249c",
  strip_prefix = "googletest-release-1.8.1",
  build_file = "@//thirdparty/gtest:BUILD",
  urls = ["https://github.com/google/googletest/archive/release-1.8.1.tar.gz"],
)

git_repository(
  name = "git_googlebentchmark",
  remote = "https://github.com/google/benchmark.git",
  tag = "v1.5.3",
)

git_repository(
  name = "git_protobuf",
  remote = "https://github.com/protocolbuffers/protobuf.git",
  tag = "v3.8.0",
)