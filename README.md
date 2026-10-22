# instrument_control_project

## Build and run

The application uses `spdlog` and `nlohmann/json`. CMake downloads these
dependencies during configuration, so they do not need to be installed
system-wide.

```sh
cmake -S . -B build
cmake --build build
./build/instrument_control_app
```

## Bazel

Bazel downloads the pinned `spdlog` and `nlohmann/json` source archives on
the first build. From the repository root:

```sh
bazel build //:instrument_control_app
bazel run //:instrument_control_app
```

Bazel dependencies are declared with Bzlmod in `MODULE.bazel` and are pinned
to specific source archive versions and checksums.

CMake remains available for environments that already use the existing CMake
workflow.
