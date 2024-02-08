#include <iostream>
#include "AutoClimateControlSystem.h"
#include "ILogWriter.h"

AutoClimateControlSystem::AutoClimateControlSystem(IOutsideTempSensor* outsideTempSensorArg, IOccupancySensor* occupancySensorArg, ITempCalculator* tempCalculatorArg, ITempRegulator* tempRegulatorArg, ILogWriter* logWriterArg)
    : outsideTempSensor{ outsideTempSensorArg }, occupancySensor{ occupancySensorArg },
    tempCalculator{ tempCalculatorArg }, tempRegulator{ tempRegulatorArg }, logWriter{ logWriterArg } {}

void AutoClimateControlSystem::on() {
    logWriter->log("AutoClimateControlSystem turned on.");
    int peopleCount = occupancySensor->getPeopleCount();
    double outsideTemp = outsideTempSensor->getOutsideTemperature();
    double currentTemperature = tempCalculator->calculateTemperature(peopleCount, outsideTemp);
    double desiredTemperature = currentTemperature + 5; 
    tempRegulator->regulateTemperature(desiredTemperature);

}

void AutoClimateControlSystem::off() {
    logWriter->log("AutoClimateControlSystem turned off.");
}
