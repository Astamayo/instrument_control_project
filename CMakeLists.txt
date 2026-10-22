cmake_minimum_required(VERSION 3.20)

project(instrument_control_project LANGUAGES CXX)

include(FetchContent)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(SPDLOG_BUILD_EXAMPLE OFF CACHE BOOL "" FORCE)
set(SPDLOG_BUILD_TESTS OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.15.3
)
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(spdlog nlohmann_json)

add_executable(instrument_control_app
    app/main.cpp
    include/smu/logs/logInterface/log_interface.cpp
)

target_link_libraries(instrument_control_app
    PRIVATE
        spdlog::spdlog
        nlohmann_json::nlohmann_json
)

target_include_directories(instrument_control_app PRIVATE include)