// ClimateSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
#include  "ILogWriter.h"
#include  "LogWriter.h"
int main() {
    
  /*  IOutsideTempSensor* outsideTempSensor = new OutsideTempSensor();
    IOccupancySensor* occupancySensor = new OccupancySensor();
    ITempCalculator* tempCalculator = new TempCalculator();
    ITempRegulator* tempRegulator = new TempRegulator();
    ILogWriter* logWriter= new ConsoleLogWriter();

    AutoClimateControlSystem autoClimateControl(outsideTempSensor, occupancySensor, tempCalculator, tempRegulator,logWriter);

    autoClimateControl.on();
    autoClimateControl.off();

    delete outsideTempSensor;
    delete occupancySensor;
    delete tempCalculator;
    delete tempRegulator;*/

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
