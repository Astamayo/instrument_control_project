load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def _deps_impl(_module_ctx):
    http_archive(
        name = "spdlog",
        sha256 = "15a04e69c222eb6c01094b5c7ff8a249b36bb22788d72519646fb85feb267e67",
        strip_prefix = "spdlog-1.15.3",
        urls = ["https://github.com/gabime/spdlog/archive/refs/tags/v1.15.3.tar.gz"],
        build_file_content = """
load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "spdlog",
    hdrs = glob(["include/**/*.h"]),
    includes = ["include"],
    defines = ["SPDLOG_HEADER_ONLY"],
    visibility = ["//visibility:public"],
)
""",
    )

    http_archive(
        name = "nlohmann_json",
        sha256 = "0d8ef5af7f9794e3263480193c491549b2ba6cc74bb018906202ada498a79406",
        strip_prefix = "json-3.11.3",
        urls = ["https://github.com/nlohmann/json/archive/refs/tags/v3.11.3.tar.gz"],
        build_file_content = """
load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "json",
    hdrs = glob(["single_include/nlohmann/**/*.hpp"]),
    includes = ["single_include"],
    visibility = ["//visibility:public"],
)
""",
    )

deps = module_extension(implementation = _deps_impl)
