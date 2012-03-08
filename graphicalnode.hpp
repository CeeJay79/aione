#ifndef GRAPHICALNODE_HPP
#define GRAPHICALNODE_HPP

#include <QtOpenGL/QGLWidget>
#include "geometricobject.hpp"


#include <iostream>

class GraphicalNode : public GeometricObject
{
public:
    GraphicalNode();

    void create();
    void draw();

    void setRadius(double);
    double getRadius();
    void setPosition(double inPos[]);

protected:


private:
    double radius;
    double pos[3];
};

#endif // GRAPHICALNODE_HPP
