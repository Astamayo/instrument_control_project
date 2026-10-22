#include "ki2636b.h"
#include <iostream>

KI2636B_Channel::KI2636_Channel(std::string prefix, int handle) 
    : prefix(prefix), connectionHandle(handle) {}

void KI2636B_Channel::configure(const SmuConfig& config) {
    std::string senseCmd = (config.senseMode == SenseMode::FourWire) ? "SENSE_REMOTE" : "SENSE_LOCAL";
    send(prefix + ".sense = " + prefix + "." + senseCmd);
    send(prefix + ".source.limitv = " + std::to_string(config.voltageComplianceLimit));
}

void KI2636B_Channel::enableOutput(bool enable) {
    send(prefix + ".source.output = " + (enable ? "smua.OUTPUT_ON" : "smua.OUTPUT_OFF"));
}

void KI2636B_Channel::sourceVoltage(double volts) {
    send(prefix + ".source.levelv = " + std::to_string(volts));
}

double KI2636B_Channel::measureCurrent() {
    return 0.001;
}

std::vector<double> KI2636B_Channel::executeVoltageSweep(const SweepConfig& config) {
    return std::vector<double>(config.points, 0.0);
}

void KI2636B_Channel::send(std::string_view cmd) {
    std::cout << "[TX -> 2636B] " << cmd << "\n";
} 









