//
// Created by nig3l on 07/01/2020.
//

#ifndef OPENGL_THALES_CUBE_TRANSLATIONTOOL_H
#define OPENGL_THALES_CUBE_TRANSLATIONTOOL_H

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

class TranslationTool {

private:
    glm::vec3 vector{};
    bool updated;
public:
    TranslationTool();

    ~TranslationTool();

    glm::vec3 &getVectors();

    void updateVector(glm::vec3 &nVector);

    bool isUpdated() const;
};


#endif //OPENGL_THALES_CUBE_TRANSLATIONTOOL_H
