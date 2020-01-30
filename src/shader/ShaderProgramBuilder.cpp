//
// Created by nig3l on 06/01/2020.
//

#include <iostream>
#include "ShaderProgramBuilder.h"


ShaderProgram * ShaderProgramBuilder::build() {
    glLinkProgram(this->program);
    this->check();
    return new ShaderProgram(this->program);
}

void ShaderProgramBuilder::check() {
    int success;
    char infoLog[512];
    glGetProgramiv(this->program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(this->program, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER PROGRAM::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

ShaderProgramBuilder::ShaderProgramBuilder() {
    this->program = glCreateProgram();
}

ShaderProgramBuilder *ShaderProgramBuilder::setShaders(std::vector<Shader *> shaders) {
    for (Shader *shaderPtr : shaders) {
        glAttachShader(this->program, shaderPtr->getId());
    }
    return this;
}

