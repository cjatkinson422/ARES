#include "Logger.hh"
#include <iostream>

Logger* Logger::instance;

Logger::Logger(){
    /* Singleton class constructor of the Logger class
    */
}

Logger* Logger::getInstance(){
    /* Returns the singleton instance of the Logger class
    */
    if(!instance)
       instance = new Logger();
    return instance;
    
}

