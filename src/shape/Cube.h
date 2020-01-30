//
// Created by nig3l on 07/01/2020.
//

#ifndef OPENGL_THALES_CUBE_CUBE_H
#define OPENGL_THALES_CUBE_CUBE_H

#include "Shape.h"

class Cube : public Shape {
public:
    Cube();
    ~Cube() override;
    void draw() override ;
};


#endif //OPENGL_THALES_CUBE_CUBE_H
