//
// Created by nig3l on 08/01/2020.
//

#include "ShapeFactory.h"
#include "Cube.h"
#include "Pyramid.h"

unsigned int ShapeFactory::TYPE_OF_SHAPE = 2;
ShapeFactory ShapeFactory::INSTANCE = ShapeFactory();

ShapeFactory::ShapeFactory() {
    this->indexOfShape = 0;
}

ShapeFactory::~ShapeFactory() {
    for (Shape *shapePtr : this->shapes) {
        delete shapePtr;
    }
    this->shapes.clear();
    this->shapes.shrink_to_fit();
}

void ShapeFactory::init() {
    INSTANCE.shapes.emplace_back(new Pyramid());
    INSTANCE.shapes.emplace_back(new Cube());
}

ShapeFactory &ShapeFactory::getInstance() {
    return INSTANCE;
}

Shape *ShapeFactory::get() {
    this->indexOfShape = (this->indexOfShape + 1) % TYPE_OF_SHAPE;
    return this->shapes[this->indexOfShape];
}


