#include "texture.h"

Texture::Texture(const std::string& image_path){
    filename = image_path;

    ILuint imageID;
    ILenum error;
    ILboolean success;
    ilGenImages(1, &imageID);
    ilBindImage(imageID);
    success = ilLoadImage(filename.c_str());

    if(!success){
        throw std::runtime_error("could not load image");
    }

    ILinfo imageInfo;
    iluGetImageInfo(&imageInfo);
    if(imageInfo.Origin == IL_ORIGIN_UPPER_LEFT){
        iluFlipImage();
    }

    success = ilConvertImage(IL_RGB, IL_UNSIGNED_BYTE);
    if(!success){
        error = ilGetError();
        throw std::runtime_error("got error converting image");
    }

    //all data is prepped, load it into a texture now
    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    // Set texture clamping method
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    // Set texture interpolation method to use linear interpolation (no MIPMAPS)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //load data into texture
    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 ilGetInteger(IL_IMAGE_FORMAT),
                 ilGetInteger(IL_IMAGE_WIDTH),
                 ilGetInteger(IL_IMAGE_HEIGHT),
                 0,
                 ilGetInteger(IL_IMAGE_FORMAT),
                 GL_UNSIGNED_BYTE,
                 ilGetData());

    ilDeleteImages(1, &imageID);
}

Texture::~Texture(){
    printf("Texture released\n");
}

void Texture::bind(GLuint uniform){
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture_id);
    glUniform1i(uniform, texture_id);
}

void Texture::unbind(){
    //printf("unbinding\n");
}
