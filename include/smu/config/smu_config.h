#pragma once

enum class SenceMode { TwoWire, FourWire };
enum class SourceMode { DC_Voltage, DC_Current };

struct SmuConfig {
    SenceMode senceMode = SenceMode::TwoWire;
    double voltageComplianceLimit = 21.0;
    double currentComplianceLimit = 0.1;
    bool autoRange = true;
};

struct SweepConfig {
    double startLevel;
    double stopLevel;
    int points;
    double stepDelaySec;
};