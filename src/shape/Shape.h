//
// Created by nig3l on 07/01/2020.
//

#ifndef OPENGL_THALES_CUBE_SHAPE_H
#define OPENGL_THALES_CUBE_SHAPE_H

#include <glad/glad.h>

class Shape {
protected:
    unsigned int vertexArray, vertexBuffer;
public:
    Shape();

    virtual ~Shape();

    /**
     * Draw the shape on the screen.
     */
    virtual void draw() = 0;
};


#endif //OPENGL_THALES_CUBE_SHAPE_H
