#pragma once
#include "IOccupancySensor.h"

class OccupancySensor : public IOccupancySensor {
private:
    int peopleCount;
public:
    int getPeopleCount() override;
};

