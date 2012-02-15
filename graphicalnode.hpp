#ifndef GRAPHICALNODE_HPP
#define GRAPHICALNODE_HPP

#include <QtOpenGL/QGLWidget>
#include "geometricobject.hpp"

class GraphicalNode : public GeometricObject
{
public:
    GraphicalNode();

    void create();

private:
    double radius;
};

#endif // GRAPHICALNODE_HPP
