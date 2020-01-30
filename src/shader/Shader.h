//
// Created by nig3l on 06/01/2020.
//

#ifndef OPENGL_THALES_CUBE_SHADER_H
#define OPENGL_THALES_CUBE_SHADER_H

#include <glad/glad.h>

class Shader {
protected:
    unsigned int id;

public:
    Shader();
    explicit Shader(unsigned int id);
    ~Shader();

    /**
     * Anemic getter.
     */
    unsigned int getId() const;
};


#endif //OPENGL_THALES_CUBE_SHADER_H
