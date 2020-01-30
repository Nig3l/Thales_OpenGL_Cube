//
// Created by nig3l on 07/01/2020.
//

#ifndef OPENGL_THALES_CUBE_PYRAMID_H
#define OPENGL_THALES_CUBE_PYRAMID_H

#include "Shape.h"

/**
 * 3D Pyramid
 */
class Pyramid : public Shape {

public:

    Pyramid();

    ~Pyramid() override;

    void draw() override;
};


#endif //OPENGL_THALES_CUBE_PYRAMID_H
