#include "graphicaledge.hpp"

GraphicalEdge::GraphicalEdge()
{
    radius = 1;
    length = 5;
}

void GraphicalEdge::create()
{
    GLUquadricObj* cylinder;
    mListIndex = glGenLists(1);

    if (mListIndex != 0)
    {
        glNewList(mListIndex,GL_COMPILE);
            glColor3f(1.0,0.0,0.0);
            cylinder = gluNewQuadric();
            gluQuadricDrawStyle(cylinder,GLU_FILL);
            gluQuadricNormals(cylinder,GLU_SMOOTH);
            gluCylinder(cylinder,radius,radius,length,32,1);
        glEndList();
    }
}

void GraphicalEdge::draw()
{
    glPushMatrix();
//        glTranslated(0.0,0.0,0.0);
//        glRotated(0.0,0.0,0.0,0.0);
        glCallList(mListIndex);
    glPopMatrix();
}

void GraphicalEdge::setDimension(double inRadius, double inLength)
{
    radius = inRadius;
    length = inLength;
}

void GraphicalEdge::getDimension(double& inRadius, double& inLength)
{
    inRadius = radius;
    inLength = length;
}
