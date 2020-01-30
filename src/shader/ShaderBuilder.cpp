//
// Created by nig3l on 06/01/2020.
//

#include "ShaderBuilder.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cwalk.h>
#include <cstring>


ShaderBuilder::ShaderBuilder() {
    this->shaderSource = "";
    this->shader = 0;
}

ShaderBuilder::~ShaderBuilder() = default;

void ShaderBuilder::init(const char *path) {
    std::string *shaderCode = new std::string;
    std::ifstream shaderFile;
    shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        shaderFile.open(path);
        std::stringstream shaderStream;
        shaderStream << shaderFile.rdbuf();
        shaderFile.close();
        *shaderCode = shaderStream.str();
    }
    catch (std::ifstream::failure e) {
        std::cerr << "ERROR::SHADER::" << path << "::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    this->shaderSource = shaderCode->c_str();
}

Shader ShaderBuilder::build(const char *path) {
    this->init(path);
    this->compile(path);
    delete (this->shaderSource);
    return Shader(this->shader);
}

void ShaderBuilder::check() {
    int success;
    char infoLog[512];
    glGetShaderiv(this->shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(this->shader, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

void ShaderBuilder::compile(const char *path) {
    const char *extension;
    size_t length;
    cwk_path_get_extension(path, &extension, &length);
    if (std::strcmp(extension, ".fs") == 0) {
        this->shader = glCreateShader(GL_FRAGMENT_SHADER);
    } else if (std::strcmp(extension, ".vs") == 0) {
        this->shader = glCreateShader(GL_VERTEX_SHADER);
    }
    glShaderSource(this->shader, 1, &this->shaderSource, nullptr);
    glCompileShader(this->shader);
    this->check();
}
