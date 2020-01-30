//
// Created by nig3l on 07/01/2020.
//

#include "Cube.h"

Cube::Cube() {
    float points[] = {
            // 1ere Face
            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.26f, 0.61f, 1.0f,
            0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.26f, 0.61f, 1.0f,
            0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.26f, 0.61f, 1.0f,
            0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.26f, 0.61f, 1.0f,
            -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.26f, 0.61f, 1.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.26f, 0.61f, 1.0f,

            // 2eme Face
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.67f, 0.04f,
            0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.67f, 0.04f,
            0.5f, 0.5f, 0.5f, 0.0f, 0.0f,1.0f, 0.67f, 0.04f,
            0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.67f, 0.04f,
            -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.67f, 0.04f,
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.67f, 0.04f,

            // 3eme Face
            -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.97f, 0.25f, 0.19f,
            -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.97f, 0.25f, 0.19f,
            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.97f, 0.25f, 0.19f,
            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.97f, 0.25f, 0.19f,
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.97f, 0.25f, 0.19f,
            -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.97f, 0.25f, 0.19f,

            // 4eme Face
            0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.53f, 0.0f, 0.78f,
            0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.53f, 0.0f, 0.78f,
            0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.53f, 0.0f, 0.78f,
            0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.53f, 0.0f, 0.78f,
            0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.53f, 0.0f, 0.78f,
            0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.53f, 0.0f, 0.78f,

            // 5eme Face
            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
            0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f,
            0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,

            // 6eme Face
            -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.09f,
            0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.09f,
            0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.09f,
            0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.09f,
            -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.09f,
            -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.09f
    };

    glGenVertexArrays(1, &this->vertexArray);
    glGenBuffers(1, &this->vertexBuffer);

    glBindVertexArray(this->vertexArray);

    glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void *) (5 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

void Cube::draw() {
    glBindVertexArray(this->vertexArray);
    glDrawArrays(GL_TRIANGLES, 0, 36);
}

Cube::~Cube()= default;
