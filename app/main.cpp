#include "smu/logs/logInterface/log_interface.hpp"
#include <memory>


int main() {
    auto path = Path::log;
    auto lot = std::make_unique<Logger>(path);

    lot->log();

    return 0;
}
