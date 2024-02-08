#pragma once
#include "IOutsideTempSensor.h"

class OutsideTempSensor : public IOutsideTempSensor {
private:
    double outsideTemperature;
public:
    double getOutsideTemperature() override;
};
