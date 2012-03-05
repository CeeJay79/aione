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

    void setPosition(double*);
    void setOrientation(double*);
    void setDimension(double,double);
    void getDimension(double&,double&);

private:
    double radius;
    double length;
    double xRot,yRot,zRot;
    double pos[3];

};

#endif // GRAPHICALEDGE_HPP
