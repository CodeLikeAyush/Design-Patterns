# Thread-Safe Singleton Logger Example

This C++ project demonstrates the **Singleton Design Pattern** using a `Logger` class.  
It ensures that **only one instance** of `Logger` exists, even when accessed by multiple threads.

---

## **All-in-One Code & Instructions**

```cpp
// logger.hpp
#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <mutex>

class Logger {
    static int instanceCount;
    static Logger* loggerInstance;
    static std::mutex mtx;

    Logger(); // private constructor

public:
    static Logger* getInstance();
    void log(std::string msg);
};

#endif

// logger.cpp
#include "logger.hpp"
#include <iostream>

int Logger::instanceCount = 0;
Logger* Logger::loggerInstance = nullptr;
std::mutex Logger::mtx;

Logger::Logger() {
    instanceCount++;
    std::cout << "New instance of Logger created. Count: " << Logger::instanceCount << std::endl;
}

void Logger::log(std::string msg) {
    std::cout << msg << std::endl;
}

Logger* Logger::getInstance() {
    mtx.lock();
    if (loggerInstance == nullptr) {
        loggerInstance = new Logger();
    }
    mtx.unlock();
    return loggerInstance;
}

// main.cpp
#include <iostream>
#include <thread>
#include "logger.hpp"

void client1() {
    Logger* logger1 = Logger::getInstance();
    logger1->log("This is log message from client1");
}

void client2() {
    Logger* logger2 = Logger::getInstance();
    logger2->log("This is log message from client2");
}

int main() {
    std::thread t1(client1);
    std::thread t2(client2);

    t1.join();
    t2.join();

    return 0;
}
```

## Compilation & Execution Instructions:

1. Compile logger.cpp:
```cpp
   g++ -c logger.cpp
```
2. Compile main.cpp:
```cpp
   g++ -c main.cpp
```
3. Link object files:
```cpp
   g++ main.o logger.o -o logger_app -pthread
```
4. Run the program:
```cpp
   ./logger_app
```
