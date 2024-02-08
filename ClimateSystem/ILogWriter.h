#pragma once
class ILogWriter {
public:
	virtual void log(const std::string& message) = 0;
};