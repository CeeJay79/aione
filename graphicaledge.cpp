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
        // Delete the pointer
        gluDeleteQuadric(cylinder);
    }
}

void GraphicalEdge::draw()
{
    glPushMatrix();
        glTranslated(pos[0],pos[1],pos[2]);
        glRotated(xRot,1.0,0.0,0.0);
        glRotated(yRot,0.0,1.0,0.0);
//        glRotated(zRot,0.0,0.0,1.0);
        glCallList(mListIndex);
    glPopMatrix();
}

void GraphicalEdge::setDimension(double inRadius, double inLength)
{
    radius = inRadius;
    length = inLength;
}

void GraphicalEdge::setOrientation(double __xRotation, double __yRotation, double __zRotation)
{
    xRot = __xRotation;
    yRot = __yRotation;
    zRot = __zRotation;
}

void GraphicalEdge::getDimension(double& inRadius, double& inLength)
{
    inRadius = radius;
    inLength = length;
}

void GraphicalEdge::setPosition(double* posPtr)
{
    pos[0] = posPtr[0];
    pos[1] = posPtr[1];
    pos[2] = posPtr[2];
}
