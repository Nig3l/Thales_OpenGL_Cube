//
// Created by nig3l on 06/01/2020.
//

#ifndef OPENGL_THALES_CUBE_SHADERPROGRAM_H
#define OPENGL_THALES_CUBE_SHADERPROGRAM_H

#include <glad/glad.h>
#include <glfw3.h>
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"
#include "../tools/TranslationTool.h"


class ShaderProgram {
private:
    unsigned int id;

    TranslationTool translationTool;

    void translate();

    void rotate();

    void applyMatrix(const char *name, glm::mat4 &matrix);

public:

    explicit ShaderProgram(unsigned int id = 0);

    void updateTranslateTool(glm::vec3 vector);

    void setProjectionMatrix(unsigned int width, unsigned int height);

    void animate();

    ~ShaderProgram();

    unsigned int getId();
};

#endif //OPENGL_THALES_CUBE_SHADERPROGRAM_H
