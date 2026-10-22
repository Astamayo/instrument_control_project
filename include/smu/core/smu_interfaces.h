#pragma once 
#include <string_view>
#include <vector>
#include <memory>
#include "../../config/smu_config.h"

class SmuChannel {
public:
    virtual ~SmuChannel() = default;
    virtual void configure(const SmuConfig& config) = 0;
    virtual void enableOutput(bool enable) = 0;
    virtual void sourceVoltage(double volts) = 0;
    virtual double measureCurrent() = 0;
};

class ISweepable {
public:
    virtual ~ISweepable() = default;
    virtual std::vector<double> executeVoltageSweep(const SweepConfig& config) = 0;
};

class SmuInstrument {
public:
    virtual ~SmuInstrument() = default;
    virtual bool connect(std::string_view resourceAddress) = 0;
    virtual void disconnect() = 0;

    virtual SmuChannel* getChannel(int channelIndex) = 0;  
};