#include "Texture.hh"

class TextureHandler{
public:
    TextureHandler();
    
    Texture ASPHALT_1;
    static TextureHandler* getInstance();
private:
    static TextureHandler* instance;
};