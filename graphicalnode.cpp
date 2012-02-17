#include "graphicalnode.hpp"

GraphicalNode::GraphicalNode()
{
}

void GraphicalNode::create()
{
    mListIndex = glGenLists(2);

    if (!mListIndex)
    {
        GLUquadricObj* sphere;
        glNewList(mListIndex+1,GL_COMPILE);

            sphere = gluNewQuadric();
            gluQuadricDrawStyle(sphere,GLU_FILL);
            gluSphere(sphere,radius,8,8);

        glEndList();

        glNewList(mListIndex,GL_COMPILE);
            glColor3f(1.0,0.0,0.0);
            glCallList(mListIndex+1);
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
