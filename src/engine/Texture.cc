#include "engine/Texture.hh"
#include "engine/Logger.hh"
#define STB_IMAGE_IMPLEMENTATION
#include "third_party/stb/stb_image.h"
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;


bool hasEnding (std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

Texture::Texture(string path){

    // generate the needed texture slots on the GPU
    glGenTextures(MAX_TEXTURE_UNITS, texture_ids);

    // If the user passed a string ending in .png, assume that they 
    // want to load only a single texture
    if( hasEnding(path, ".png")){
        load(path, 0);
    }

    // Else if the user passed something without a .png extension (presumably a texture set)
    else{
        for (const auto & entry : fs::directory_iterator(path)){
            if(hasEnding(entry.path(), "diffuse.png"))
                load(entry.path(), 0);
            if(hasEnding(entry.path(), "normal.png"))
                load(entry.path(), 1);
            if(hasEnding(entry.path(), "roughness.png"))
                load(entry.path(), 2);
        }
    }
}

void Texture::load(string filename, int index){
    
    // Check to make sure that the index doesnt exceed the size
    if(index > MAX_TEXTURE_UNITS){
        Logger::println("Attempted to load texture with index greater than 16");
        return;
    }
    glActiveTexture(GL_TEXTURE0 + index);
    glBindTexture(GL_TEXTURE_2D,texture_ids[index]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // load and generate the texture
    int width, height, nrChannels;
    unsigned char *data = stbi_load(filename.c_str(), &width, &height, &nrChannels, 0);
    if (data && nrChannels == 3){
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else if (data && nrChannels == 4){
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else{
        Logger::println("Failed to load texutre " + filename);
        return;
    }
    stbi_image_free(data);


    Logger::println("Loaded texture " + filename + " with " + std::to_string(nrChannels) + " channels");
    textures_in_use[index] = true;
}


void Texture::bind(){
    for(int i = 0; i < MAX_TEXTURE_UNITS; ++i){
        if(textures_in_use[i]){
            glActiveTexture(GL_TEXTURE0 + i);
            glBindTexture(GL_TEXTURE_2D, texture_ids[i]);
        }
    }
}