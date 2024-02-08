#include "gtest/gtest.h"
#include "TempCalculator.h"

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