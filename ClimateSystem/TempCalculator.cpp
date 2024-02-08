#include "TempCalculator.h"

double TempCalculator::calculateTemperature(int peopleCount, double outsideTemp) {
    return outsideTemp - peopleCount;
}
