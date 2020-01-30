//
// Created by nig3l on 06/01/2020.
//

#include "Shader.h"

Shader::Shader() {
    this->id = 0;
}

Shader::Shader(unsigned int id) : id(id){}

Shader::~Shader() = default;

unsigned int Shader::getId() const {
    return id;
}
