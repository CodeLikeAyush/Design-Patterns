#include "logger.hpp"

#include <iostream>
#include <string>
#include <mutex>

int Logger::instanceCount = 0;
Logger *Logger::loggerInstance = nullptr;
std::mutex Logger::mtx;

Logger::Logger()
{
    instanceCount++;
    std::cout << "new instance of logger created. Count: " << Logger::instanceCount << std::endl;
}

void Logger::log(std::string msg)
{

    std::cout << msg << std::endl;
}

Logger *Logger::getInstance()
{
    mtx.lock();
    if (loggerInstance == nullptr)
    {
        loggerInstance = new Logger();
    }
    mtx.unlock();
    return loggerInstance;
}