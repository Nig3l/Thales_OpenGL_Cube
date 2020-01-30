//
// Created by nig3l on 08/01/2020.
//

#ifndef OPENGL_THALES_CUBE_SHAPEFACTORY_H
#define OPENGL_THALES_CUBE_SHAPEFACTORY_H


#include <vector>
#include "Shape.h"

/**
 * Singleton which provide different shapes to the application.
 */
class ShapeFactory {
private:
    /**
     * Singleton Instance.
     */
    static ShapeFactory INSTANCE;

    /**
     * Number of Shapes available.
     */
    static unsigned int TYPE_OF_SHAPE;

    /**
     * Index of the current shape.
     */
    unsigned int indexOfShape;

    ShapeFactory();

    /**
     * Vector of all shapes.
     */
    std::vector<Shape *> shapes;
public:

    ~ShapeFactory();

    /**
     * Get the next shape of the shapes vector.
     * @return a pointer on an other shape.
     */
    Shape *get();

    /**
     * Get the single instance available of ShapeFactory.
     * @return a reference on the Singleton.
     */
    static ShapeFactory &getInstance();

    /**
     * Init the Factory.
     */
    static void init();
};

#endif //OPENGL_THALES_CUBE_SHAPEFACTORY_H
