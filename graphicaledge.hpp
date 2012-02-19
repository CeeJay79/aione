#ifndef GRAPHICALEDGE_HPP
#define GRAPHICALEDGE_HPP

#include <QtOpenGL/QGLWidget>
#include <geometricobject.hpp>

class GraphicalEdge : public GeometricObject
{
public:
    GraphicalEdge();

    void create();
    void draw();

    void setDimension(double,double);
    void getDimension(double&,double&);

private:
    double radius;
    double length;

};

#endif // GRAPHICALEDGE_HPP
