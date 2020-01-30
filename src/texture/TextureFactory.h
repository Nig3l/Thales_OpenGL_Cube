//
// Created by nig3l on 07/01/2020.
//

#ifndef OPENGL_THALES_CUBE_TEXTUREFACTORY_H
#define OPENGL_THALES_CUBE_TEXTUREFACTORY_H


#include "Texture.h"
#include <vector>

/**
 * Singleton which provide different textures which can be used for the 3D Shapes.
 */
class TextureFactory {
private:
    /**
     * Number of textures available.
     */
    static unsigned int NUMBER_OF_TEXTURE;
    /**
     * Instance of Singleton.
     */
    static TextureFactory INSTANCE;

    /**
     * Index of current texture.
     */
    unsigned int indexOfTexture;

    /**
     * Vector of All Texture.
     */
    std::vector<Texture *> textures;

public:
    TextureFactory();

    ~TextureFactory();

    /**
     * Get a reference on the singleton.
     * @return
     */
    static TextureFactory &getInstance();

    /**
     * Init the singleton.
     */
    static void init();

    /**
     * Change the current texture.
     * @return get a pointer on the new texture.
     */
    Texture *get();
};


#endif //OPENGL_THALES_CUBE_TEXTUREFACTORY_H
