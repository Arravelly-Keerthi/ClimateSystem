#pragma once
#include "ITempRegulator.h"
#include "ILogWriter.h"

class TempRegulator : public ITempRegulator {
private:
    ILogWriter* logWriter;
public:
    TempRegulator(ILogWriter* logWriter);
    void regulateTemperature(double desiredTemp) override;
};
