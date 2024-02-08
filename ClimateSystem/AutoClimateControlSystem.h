#pragma once
#include "IOutsideTempSensor.h"
#include "IOccupancySensor.h"
#include "ITempCalculator.h"
#include "ITempRegulator.h"
#include  "ILogWriter.h"

class AutoClimateControlSystem {
private:
    IOutsideTempSensor* outsideTempSensor;
    IOccupancySensor* occupancySensor;
    ITempCalculator* tempCalculator;
    ITempRegulator* tempRegulator;
    ILogWriter* logWriter;

public:
    AutoClimateControlSystem(IOutsideTempSensor* outsideTempSensorArg, IOccupancySensor* occupancySensorArg, ITempCalculator* tempCalculatorArg,ITempRegulator* tempRegulatorArg,ILogWriter* logWriterArg);
    void on();
    void off();
};
