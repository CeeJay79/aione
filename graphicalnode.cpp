#include "graphicalnode.hpp"

GraphicalNode::GraphicalNode()
{
}

void GraphicalNode::create()
{
    mListIndex = glGenLists(1);
    if (!mListIndex)
    {
        GLUquadricObj* sphere;
        glNewList(mListIndex,GL_COMPILE);
            sphere = gluNewQuadric();
            gluQuadricDrawStyle(sphere,GLU_FILL);
            gluSphere(sphere,radius,8,8);
        glEndList();
    }
}
