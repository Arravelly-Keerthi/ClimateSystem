#include "gtest/gtest.h"
#include "TempCalculator.h"
#include <gmock/gmock.h>
#include "AutoClimateControlSystem.h"

//Mock methods
class MockOutsideTempSensor : public IOutsideTempSensor {
public:
	MOCK_METHOD(double, getOutsideTemperature, ());
};

class MockOccupancySensor : public IOccupancySensor {
public:
	MOCK_METHOD(int, getPeopleCount, ());
};

class MockTempCalculator : public ITempCalculator {
public:
	MOCK_METHOD(double, calculateTemperature, (int peopleCount, double outsideTemp));
};

class MockTempRegulator : public ITempRegulator {
public:
	MOCK_METHOD(void, regulateTemperature, (double desiredTemp));
};

class MockLogWriter : public ILogWriter {
public:
	MOCK_METHOD(void, log, (const std::string& message));
};


TEST(ClimateSystemTestSuite, ExpectedIntForPeopleCount)
{
    MockOccupancySensor occupancySensor;

    EXPECT_CALL(occupancySensor, getPeopleCount()).WillOnce(::testing::Return(4));

    occupancySensor.getPeopleCount();
}

TEST(ClimateSystemTestSuite, ExpectedDoubleForOutsideTemperature)
{
    MockOutsideTempSensor outsideTempSensor;

    EXPECT_CALL(outsideTempSensor, getOutsideTemperature()).WillOnce(::testing::Return(25));

    outsideTempSensor.getOutsideTemperature();
}

TEST(ClimateSystemTestSuite, OnTurnsSystemOnAndRegulatesTemperature) {
    MockOutsideTempSensor outsideTempSensor;
    MockOccupancySensor occupancySensor;
    MockTempCalculator tempCalculator;
    MockTempRegulator tempRegulator;
    MockLogWriter logWriter;

    EXPECT_CALL(logWriter, log("AutoClimateControlSystem turned on."));
    EXPECT_CALL(occupancySensor, getPeopleCount()).WillOnce(::testing::Return(4));
    EXPECT_CALL(outsideTempSensor, getOutsideTemperature()).WillOnce(::testing::Return(25.0));
    EXPECT_CALL(tempCalculator, calculateTemperature(4, 25.0)).WillOnce(::testing::Return(21.0));
    EXPECT_CALL(tempRegulator, regulateTemperature(26.0));


    AutoClimateControlSystem autoClimateControl(&outsideTempSensor, &occupancySensor, &tempCalculator, &tempRegulator, &logWriter);

    autoClimateControl.on();
}


TEST(ClimateSystemTestSuite, OffTurnsSystemOff) {
    MockOutsideTempSensor outsideTempSensor;
    MockOccupancySensor occupancySensor;
    MockTempCalculator tempCalculator;
    MockTempRegulator tempRegulator;
    MockLogWriter logWriter;

    EXPECT_CALL(logWriter, log("AutoClimateControlSystem turned off."));

    AutoClimateControlSystem autoClimateControl(&outsideTempSensor, &occupancySensor, &tempCalculator, &tempRegulator, &logWriter);

    autoClimateControl.off();
}

TEST(ClimateSystemTestSuite, ExpectedNewTempGivenCurTempAndPeopleCount) {
	//Arrange
	int peopleCount = 2;
	double currentTemp = 97.2;
	double expectedResult = 95.2;
	TempCalculator tempCalculatorObj;

	//Act
	double actualResult = tempCalculatorObj.calculateTemperature(peopleCount, currentTemp);

	//Assert
	ASSERT_EQ(expectedResult, actualResult);
}