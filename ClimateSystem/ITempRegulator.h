#pragma once

class ITempRegulator {
public:
    virtual void regulateTemperature(double desiredTemp) = 0;
};
