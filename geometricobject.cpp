#include "geometricobject.hpp"

int GeometricObject::numberOfGeometricObjects = 0;

GeometricObject::GeometricObject()
{
    numberOfGeometricObjects++;
}

GeometricObject::~GeometricObject()
{
    numberOfGeometricObjects--;
}

int GeometricObject::getNumberOfObjects()
{
    return numberOfGeometricObjects;
}

int GeometricObject::getListIndex()
{
    return mListIndex;
}

void GeometricObject::setClr(double c1, double c2, double c3)
{
    clr[0] = c1;
    clr[1] = c2;
    clr[2] = c3;
}
