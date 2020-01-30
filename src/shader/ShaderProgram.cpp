//
// Created by nig3l on 06/01/2020.
//

#include "ShaderProgram.h"


ShaderProgram::ShaderProgram(unsigned int i) {
    this->id = i;
    glUseProgram(this->id);
}

void ShaderProgram::rotate() {
    glm::mat4 model(1.0f);
    model = glm::rotate(model, (float) glfwGetTime() * glm::radians(55.0f), glm::vec3(-0.7f, 0.3f, 0.0f));
    this->applyMatrix("model", model);
}

void ShaderProgram::animate() {
    glUseProgram(this->id);
    this->rotate();
    this->translate();
}

void ShaderProgram::translate() {
    if (translationTool.isUpdated()) {
        glm::mat4 view = glm::mat4(1.0f);
        view = glm::translate(view, this->translationTool.getVectors());
        this->applyMatrix("view", view);
    }
}

void ShaderProgram::updateTranslateTool(glm::vec3 vector) {
    this->translationTool.updateVector(vector);
}

void ShaderProgram::applyMatrix(const char *name, glm::mat4 &matrix) {
    unsigned int location;
    location = glGetUniformLocation(this->id, name);
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

void ShaderProgram::setProjectionMatrix(unsigned int width, unsigned int height) {
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), (float) width / (float) height, 0.1f, 100.0f);
    this->applyMatrix("projection", projection);
}

unsigned int ShaderProgram::getId() {
    return this->id;
}

ShaderProgram::~ShaderProgram() = default;


