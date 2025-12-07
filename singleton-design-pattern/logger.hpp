#ifndef logger_hpp
#define logger_hpp

#include <string>
#include <mutex>

class Logger
{
    static int instanceCount;
    static Logger *loggerInstance;
    static std::mutex mtx;
    Logger();

public:
    static Logger *getInstance();
    void log(std::string msg);
};

#endif