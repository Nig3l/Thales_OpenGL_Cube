//
// Created by nig3l on 06/01/2020.
//

#ifndef OPENGL_THALES_CUBE_SHADERBUILDER_H
#define OPENGL_THALES_CUBE_SHADERBUILDER_H

#include <glad/glad.h>
#include "Shader.h"

/**
 * Builder of Shader.
 */
class ShaderBuilder {

protected:
    const char * shaderSource;

    unsigned int shader;

    /**
     * Check if the Shader built has been correctly created.
     */
    void check();

public:

    virtual ~ShaderBuilder();

    /**
     * Build a Shader from a source file which contains GLSL code.
     * @param path path of the source file.
     * @return the shader built.
     */
    Shader build(const char * path);

    ShaderBuilder();

private:
    /**
     * Init the new Shader.
     * @param path path of the source file.
     */
    void init(const char * path);

    /**
     * Compile the new Shader.
     * @param path path of the source file.
     */
    void compile(const char *path);
};


#endif //OPENGL_THALES_CUBE_SHADERBUILDER_H
