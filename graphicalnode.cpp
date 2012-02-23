#include "graphicalnode.hpp"

GraphicalNode::GraphicalNode()
{
}

void GraphicalNode::create()
{
    GLUquadricObj* sphere;
    mListIndex = glGenLists(1);

    if (mListIndex != 0)
    {
        glNewList(mListIndex,GL_COMPILE);
            glColor3f(1.0,0.0,0.0);
            sphere = gluNewQuadric();
            gluQuadricDrawStyle(sphere,GLU_TRUE);
            gluQuadricNormals(sphere,GLU_SMOOTH);
            gluSphere(sphere,radius,16,16);
        glEndList();
    }
}

void GraphicalNode::draw()
{

    glPushMatrix();
//        glTranslated(0.0,0.0,0.0);
//        glRotated(0.0,0.0,0.0,0.0);
        glCallList(mListIndex);
    glPopMatrix();
}

void GraphicalNode::setRadius(double inRadius)
{
    radius = inRadius;
}

double GraphicalNode::getRadius()
{
      return radius;
}
