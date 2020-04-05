#include "Config.hh"
#include <iostream>
#include "Logger.hh"
#include <cstring>
#include "GNClib/linalg.hh"

Config* Config::instance;

Config::Config(){
    /* Singleton class constructor of the Config class
    */
   Logger::println("Initializing config reader");
}

Config* Config::getInstance(){
    /* Returns the singleton instance of the Config class
    */
    if(!instance)
       instance = new Config();
    return instance;
    
}

void Config::getValue(const char* name, double& val){
    Logger::print("Retrieving double value ");
    Logger::print(name);
    Logger::println(" from configs.");

    if(std::strcmp(name, "fovy")==0)
        val = deg2rad(80.0);
    else if(std::strcmp(name, "near_clip")==0)
        val = 0.01;
    else if(std::strcmp(name, "far_clip")==0)
        val = 1000.0;
    else
        Logger::print("Failed to retrieve value.");
}
void Config::getValue(const char* name, int& val){
    Logger::print("Retrieving integer value ");
    Logger::print(name);
    Logger::println(" from configs.");

    if(std::strcmp(name, "window_width")==0)
        val = 2200;
    else if(std::strcmp(name, "window_height")==0)
        val = 1200;
    else
        Logger::print("Failed to retrieve value.");
    
}

void Config::saveValue(const char* name, double){

}
void Config::saveValue(const char* name, int){
    
}