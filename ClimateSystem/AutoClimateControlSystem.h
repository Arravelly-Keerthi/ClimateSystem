#pragma once
#include "IOutsideTempSensor.h"
#include "IOccupancySensor.h"
#include "ITempCalculator.h"
#include "ITempRegulator.h"

class AutoClimateControlSystem {
private:
    IOutsideTempSensor* outsideTempSensor;
    IOccupancySensor* occupancySensor;
    ITempCalculator* tempCalculator;
    ITempRegulator* tempRegulator;

public:
    AutoClimateControlSystem(IOutsideTempSensor* outsideTempSensorArg, IOccupancySensor* occupancySensorArg, ITempCalculator* tempCalculatorArg, ITempRegulator* tempRegulatorArg);
    void on();
    void off();
};
