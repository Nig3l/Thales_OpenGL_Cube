//
// Created by nig3l on 06/01/2020.
//

#include <glad/glad.h>
#ifndef OPENGL_THALES_CUBE_TEXTURE_H


#define OPENGL_THALES_CUBE_TEXTURE_H
#include "../../includes/stb_image.h"

/**
 * Texture available for 3D Object.
 */
class Texture {

private:
    unsigned int id;

public:
    Texture();

    explicit Texture(const char *path);

    ~Texture();

    /**
     * Apply a Texture.
     */
    void apply();
};


#endif //OPENGL_THALES_CUBE_TEXTURE_H
