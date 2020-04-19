#include "TextureHandler.hh"

Texture TextureHandler::ASPHALT_1;


TextureHandler* TextureHandler::instance;
TextureHandler* TextureHandler::getInstance(){
    // Returns the singleton instance of the TextureHandler class
    if(!instance)
       instance = new TextureHandler();
    return instance;
}

TextureHandler::TextureHandler(){
    ASPHALT_1 = Texture("data/textures/landing_pad/");
}