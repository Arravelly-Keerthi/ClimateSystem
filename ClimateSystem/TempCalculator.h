#pragma once
#include "ITempCalculator.h"

class TempCalculator: public ITempCalculator {
public:
     double calculateTemperature(int peopleCount, double outsideTemp) ;
};
