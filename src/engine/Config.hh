#pragma once
#include <string>


class Config
{
private:
    /* data */
    Config();
    static Config* instance;
public:

    static Config* getInstance();
    
    void getValue(const char*, double&);
    void getValue(const char*, int&);

    void saveValue(const char*, double);
    void saveValue(const char*, int);

};

