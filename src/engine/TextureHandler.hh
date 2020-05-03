#pragma once
#include "engine/Texture.hh"

class TextureHandler{
public:
    TextureHandler();
    
    static Texture ASPHALT_1;
    static Texture HUD_1;
    static TextureHandler* getInstance();
private:
    static TextureHandler* instance;
};