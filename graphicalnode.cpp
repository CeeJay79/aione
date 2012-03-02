#include "graphicalnode.hpp"

GraphicalNode::GraphicalNode()
{
    clr[0] = 1.0;
    clr[1] = 0.0;
    clr[2] = 0.0;
}

void GraphicalNode::create()
{
    GLUquadricObj* sphere;
    mListIndex = glGenLists(1);

    if (mListIndex != 0)
    {
        glNewList(mListIndex,GL_COMPILE);
            sphere = gluNewQuadric();
            gluQuadricDrawStyle(sphere,GLU_TRUE);
            gluQuadricNormals(sphere,GLU_SMOOTH);
            gluSphere(sphere,radius,16,16);
        glEndList();
        // Delete the pointer
        gluDeleteQuadric(sphere);
    }
}

void GraphicalNode::draw()
{
    glPushMatrix();
        glColor3dv(clr);
        glTranslated(pos[0],pos[1],pos[2]);
//        glRotated(0.0,0.0,0.0,0.0);
        glCallList(mListIndex);
    glPopMatrix();
}

void GraphicalNode::setRadius(double inRadius)
{
    radius = inRadius;
}

void GraphicalNode::setPosition(double inPos[])
{
    pos[0] = inPos[0];
    pos[1] = inPos[1];
    pos[2] = inPos[2];
}

double GraphicalNode::getRadius()
{
      return radius;
}
