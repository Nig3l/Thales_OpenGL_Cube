//
// Created by nig3l on 07/01/2020.
//

#include "TranslationTool.h"

/**
 * Get a reference on the vector used for the translation and set
 * the update bool to False.
 * @return
 */
glm::vec3 &TranslationTool::getVectors() {
    this->updated = false;
    return vector;
}

/**
 * Update the vector use inside the view Matrix in the fragment shader.
 * @param nVector the new vector added
 */
void TranslationTool::updateVector(glm::vec3 &nVector) {
    this->vector.x += nVector.x;
    this->vector.y += nVector.y;
    this->vector.z += nVector.z;
    this->updated = true;
}

TranslationTool::TranslationTool() {
    this->updated = true;
    this->vector = glm::vec3(0.0f, 0.0f, -5.0f);
}

/**
 * Check if the vector has been updated since the last translation.
 * @return True or False
 */
bool TranslationTool::isUpdated() const {
    return updated;
}

TranslationTool::~TranslationTool() = default;
