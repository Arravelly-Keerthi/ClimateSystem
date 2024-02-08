
#include <iostream>
#include "IOutsideTempSensor.h"
#include "IOccupancySensor.h"
#include "OutsideTempSensor.h"
#include "OcccupancySensor.h"
#include "ITempCalculator.h"
#include "TempCalculator.h"
#include "ITempRegulator.h"
#include "TempRegulator.h"
#include "AutoClimateControlSystem.h"

int main() {
    IOutsideTempSensor* outsideTempSensor = new OutsideTempSensor();
    IOccupancySensor* occupancySensor = new OccupancySensor();
    ITempCalculator* tempCalculator = new TempCalculator();
    ITempRegulator* tempRegulator = new TempRegulator();

    AutoClimateControlSystem autoClimateControl(outsideTempSensor, occupancySensor, tempCalculator, tempRegulator);

    autoClimateControl.on();
    autoClimateControl.off();

    delete outsideTempSensor;
    delete occupancySensor;
    delete tempCalculator;
    delete tempRegulator;

    return 0;
}

