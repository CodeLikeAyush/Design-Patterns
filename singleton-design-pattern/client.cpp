#include <iostream>
#include <thread>

#include "logger.hpp"

void client1()
{
    Logger *logger1 = Logger::getInstance();

    logger1->log("This is log message from clien1");
}
void client2()
{
    Logger *logger2 = Logger::getInstance();

    logger2->log("This is log message from clien2");
}
int main()
{

    std::thread t1(client1);
    std::thread t2(client2);

    t1.join();
    t2.join();

    return 0;
}