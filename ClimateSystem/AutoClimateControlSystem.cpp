#include <iostream>
#include "AutoClimateControlSystem.h"

AutoClimateControlSystem::AutoClimateControlSystem(IOutsideTempSensor* outsideTempSensorArg, IOccupancySensor* occupancySensorArg, ITempCalculator* tempCalculatorArg, ITempRegulator* tempRegulatorArg)
    : outsideTempSensor{ outsideTempSensorArg }, occupancySensor{ occupancySensorArg },
    tempCalculator{ tempCalculatorArg }, tempRegulator{ tempRegulatorArg } {}

void AutoClimateControlSystem::on() {
    int peopleCount = occupancySensor->getPeopleCount();
    double outsideTemp = outsideTempSensor->getOutsideTemperature();
    double currentTemperature = tempCalculator->calculateTemperature(peopleCount, outsideTemp);
    double desiredTemperature = currentTemperature + 5;
    tempRegulator->regulateTemperature(desiredTemperature);
}

void AutoClimateControlSystem::off() {
    std::cout << "Climate control system turned off.\n";
}
