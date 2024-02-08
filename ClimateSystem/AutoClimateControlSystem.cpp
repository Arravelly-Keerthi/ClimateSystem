#include <iostream>
#include "AutoClimateControlSystem.h"
#include "ILogWriter.h"

AutoClimateControlSystem::AutoClimateControlSystem(IOutsideTempSensor* outsideTempSensorArg, IOccupancySensor* occupancySensorArg, ITempCalculator* tempCalculatorArg, ITempRegulator* tempRegulatorArg, ILogWriter* logWriterArg)
    : outsideTempSensor{ outsideTempSensorArg }, occupancySensor{ occupancySensorArg },
    tempCalculator{ tempCalculatorArg }, tempRegulator{ tempRegulatorArg }, logWriter{ logWriterArg } {}

void AutoClimateControlSystem::on() {
    // Retrieve sensor values
    int peopleCount = occupancySensor->getPeopleCount();
    double outsideTemp = outsideTempSensor->getOutsideTemperature();

    // Perform temperature calculation and modify values directly
    double currentTemperature = tempCalculator->calculateTemperature(peopleCount, outsideTemp);

    // Set the desired temperature based on the calculation
    double desiredTemperature = currentTemperature + 5; // Example: Increase the temperature by 5 degrees

    // Regulate the temperature
    tempRegulator->regulateTemperature(desiredTemperature);

    // Log the information
    logWriter->log("AutoClimateControlSystem turned on.");
}

void AutoClimateControlSystem::off() {
    // Log the information
    logWriter->log("AutoClimateControlSystem turned off.");
}
