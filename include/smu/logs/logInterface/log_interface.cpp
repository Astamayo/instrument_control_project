#include "smu/logs/logInterface/log_interface.hpp"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;

Logger::Logger(std::string path) : _path(std::move(path)) {}

void Logger::log() {
    try {
        // 1. Create a basic file logger pointing to your exact workspace path
        // basic_logger_mt is thread-safe. (Use _st for single-threaded if preferred).
        auto file_logger = spdlog::basic_logger_mt("smu_logger", _path);
        
        // 2. Set this logger as the global default so spdlog::info() routes here
        spdlog::set_default_logger(file_logger);

        // 3. Set a custom pattern to ensure the whole line is valid JSON
        // %Y-%m-%dT%H:%M:%S.%f%z = ISO 8601 Timestamp
        // %l = Log level
        // %v = The message payload (which we will pass as dumped JSON)
        spdlog::set_pattern("{\"timestamp\": \"%Y-%m-%dT%H:%M:%S.%f%z\", \"level\": \"%l\", \"data\": %v}");
        
        // 4. Force an automatic flush to disk on info level or higher.
        // Critical for instrument control so you don't lose data if the program crashes.
        spdlog::flush_on(spdlog::level::info);

        // 5. Construct your instrument data payload
        json smu_reading = {
            {"channel", 1},
            {"voltage_v", 5.002},
            {"current_ma", 12.4},
            {"mode", "source_v_measure_i"}
        };

        // 6. Log it (dump() serializes the JSON object into a string for the %v placeholder)
        spdlog::info(smu_reading.dump());

    } catch (const spdlog::spdlog_ex& ex) {
        // Handle initialization failures (e.g., directory doesn't exist or permission denied)
        printf("Log initialization failed: %s\n", ex.what());
    }

    // Flush all logs before exit
    spdlog::shutdown();
}