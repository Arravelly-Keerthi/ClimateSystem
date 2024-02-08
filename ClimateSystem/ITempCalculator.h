#pragma once

class ITempCalculator {
public:
    virtual double calculateTemperature(int peopleCount, double outsideTemp) = 0;
};
