#pragma once
#include <string>

struct Path {
    static inline const std::string log = "/workspaces/instrument_control_project/include/smu/logs/log.json";
    static inline const std::string connection = "/workspaces/instrument_control_project/include/smu/logs/connection.json";
};

class Logger {
public:
    explicit Logger(std::string path);
    void log();
private:
    std::string _path;
};
