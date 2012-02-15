#ifndef GRAPHICALNODE_HPP
#define GRAPHICALNODE_HPP

#include <QtOpenGL/QGLWidget>
#include "geometricobject.hpp"

class GraphicalNode : public GeometricObject
{
public:
    GraphicalNode();

    void create();
    void draw();

private:
    double radius;
};

#endif // GRAPHICALNODE_HPP
