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
