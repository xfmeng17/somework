load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

#git_repository(
#  name = "gtest",
#  remote = "https://github.com/google/googletest",
#  branch = "v1.10.x",
#)

http_archive(
  name = "googletest",
  url = "https://github.com/google/googletest/archive/release-1.10.0.zip",
  sha256 = "94c634d499558a76fa649edb13721dce6e98fb1e7018dfaeba3cd7a083945e91",
  build_file = "@//:BUILD.bazel",
  strip_prefix = "googletest-release-1.10.0",
)
