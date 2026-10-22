#pragma once 
#include "smu/core/smu_interface.h"
#include <string_view>
#include <string>
#include <memory>
#include <vector>

class KI2636B_Channel : public SmuChannel, public ISweepable {
public:
    KI2636B_Channel(std::string prefix, int handle);

    void configure(const SmuConfig& config) override;
    void enableOutput(bool enable) override;
    void sourceVoltage(double volts) override;
    double measureCurrent() override;
    std::vector<double> executeVoltageSweep(const SweepConfig& config) override

private:
    std::string prefix;
    int connetionHandle;
    void send(const std::string_view cmd);

};

class KI2636B : public SmuInstrument {
public:
    KI2636B();
    ~Ki2636B() override;
    
    bool connect(const std::string_view resourceAddress) override;
    void disconnect() override;
    SmuChannel* getChannel(int channelIndex) override;

private:
    int connectionHandle;
    std::unique_ptr<KI2636B_Channel> channelA;
    std::unique_ptr<KI2636B_Channel> channelB;
};