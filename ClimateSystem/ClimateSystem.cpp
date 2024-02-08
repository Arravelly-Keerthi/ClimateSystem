
#include <iostream>
#include "IOutsideTempSensor.h"
#include "IOccupancySensor.h"
#include "OutsideTempSensor.h"
#include "OcccupancySensor.h"
#include "ITempCalculator.h"
#include "TempCalculator.h"
#include "ITempRegulator.h"
#include "TempRegulator.h"
#include "gtest/gtest.h"
#include "AutoClimateControlSystem.h"
#include  "ILogWriter.h"
#include  "LogWriter.h"
int main() {
    /*IOutsideTempSensor* outsideTempSensor = new OutsideTempSensor();
    IOccupancySensor* occupancySensor = new OccupancySensor();
    ITempCalculator* tempCalculator = new TempCalculator();
    ILogWriter* logWriter= new ConsoleLogWriter();
    ITempRegulator* tempRegulator = new TempRegulator(logWriter);

    AutoClimateControlSystem autoClimateControl(outsideTempSensor, occupancySensor, tempCalculator, tempRegulator,logWriter);

    autoClimateControl.on();
    autoClimateControl.off();



    delete outsideTempSensor;
    delete occupancySensor;
    delete tempCalculator;
    delete tempRegulator;

    return 0;*/

    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

