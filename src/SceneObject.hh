#pragma once

class SceneObject{
public:
    SceneObject(){};
    virtual void draw(){};
    virtual void tick(){};
    virtual void instantiate(){};
    virtual void destroy(){};
private:

};