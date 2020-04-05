#pragma once
#include <string>
#include <iostream>

class Logger
{
private:
    /* data */
    Logger();
    static Logger* instance;
public:

    static Logger* getInstance();

    template<typename T>
    static void print(T);
    template<typename T>
    static void println(T);

};

template<typename T>
void Logger::print(T txt){
    std::cout << txt;
}
template<typename T>
void Logger::println(T txt){
    std::cout << txt << std::endl ;
}
