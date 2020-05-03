#pragma once
#include <string>
#define MAX_TEXTURE_UNITS 16

using std::string;


class Texture{
public:
    Texture(){};
    Texture(string);

    void bind();

private:
    unsigned int texture_ids[MAX_TEXTURE_UNITS];
    bool textures_in_use[MAX_TEXTURE_UNITS] = {false};

    void load(string filename, int index);
};

