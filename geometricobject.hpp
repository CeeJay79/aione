#ifndef GEOMETRICOBJECT_HPP
#define GEOMETRICOBJECT_HPP

#include <QtOpenGL/QGLWidget>

enum ObjectType
{
    GRAPHICAL_NODE,
    GRAPHICAL_EDGE
};

class GeometricObject
{
public:
    GeometricObject();
    virtual ~GeometricObject() = 0;

    int getNumberOfObjects();

    virtual void create() = 0;
    virtual void draw() = 0;

    int getListIndex();
    void setClr(double*);

protected:
    int mListIndex;
    double clr[3];

private:
    static int numberOfGeometricObjects;

};

#endif // GEOMETRICOBJECT_HPP
