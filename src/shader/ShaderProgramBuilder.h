//
// Created by nig3l on 06/01/2020.
//

#ifndef OPENGL_THALES_CUBE_SHADERPROGRAMBUILDER_H
#define OPENGL_THALES_CUBE_SHADERPROGRAMBUILDER_H


#include <vector>
#include "ShaderProgram.h"
#include "Shader.h"

class ShaderProgramBuilder {
private:
    unsigned int program;

public:
    ShaderProgramBuilder();

    /**
     * Build the shader program.
     * @return a pointer on the shaderProgram built.
     */
    ShaderProgram *build();

    /**
     * Check if the program built has been correctly created.
     */
    void check();

    /**
     * Add a shader's vector to the program.
     * @param shaders the shader's vector
     * @return a pointer to the builder.
     */
    ShaderProgramBuilder *setShaders(std::vector<Shader *> shaders);
};


#endif //OPENGL_THALES_CUBE_SHADERPROGRAMBUILDER_H
