#pragma once
#include "ITempRegulator.h"

class TempRegulator : public ITempRegulator {
public:
    void regulateTemperature(double desiredTemp) override;
};
