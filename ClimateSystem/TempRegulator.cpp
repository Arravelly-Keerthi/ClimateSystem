#include <iostream>
#include "TempRegulator.h"
#include "LogWriter.h"

using namespace std;
TempRegulator::TempRegulator(ILogWriter* logWriterArg) : logWriter{ logWriterArg } {}

void TempRegulator::regulateTemperature(double desiredTemp) {
    logWriter->log("Regulating Temperature");
}
