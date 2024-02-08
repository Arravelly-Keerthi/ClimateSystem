#pragma once
#include "ILogWriter.h"

class ConsoleLogWriter : public ILogWriter {
public:
    void log(const std::string& message) override {
        std::cout << message << std::endl;
    }
};
