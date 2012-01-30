#include "simulator.hpp"

Simulator::Simulator(QWidget *parent) :
    QGLWidget(parent)
{
}

void Simulator::initializeGL()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_COLOR_MATERIAL);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    // Lightining
    GLfloat  whiteLight[] = { 0.4f, 0.4f, 0.4f, 1.0f };
    GLfloat  diffuseLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat  specular[] = { 0.9f, 0.9f, 0.9f, 1.0f };
    GLfloat  lightPos[] = { 0.0f, 20.0f, 0.0f, 1.0f };

    glEnable( GL_LIGHTING );
    glLightfv( GL_LIGHT0,GL_AMBIENT,whiteLight);
    glLightfv( GL_LIGHT0,GL_DIFFUSE,diffuseLight);
    glLightfv( GL_LIGHT0,GL_SPECULAR,specular);
    glLightfv( GL_LIGHT0,GL_POSITION,lightPos);
    glEnable( GL_LIGHT0 );

    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glMaterialfv(GL_FRONT, GL_SPECULAR,specular);
    glMateriali(GL_FRONT,GL_SHININESS,128);
}

void Simulator::resizeGL(int width, int height)
{
    GLfloat w = (double)width/(double)height;
    GLfloat h = 1;

    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float near_clip = 1.0; float far_clip = 600;
    glFrustum(-w,w,-h,h,near_clip,far_clip);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslated(0,0,-50);
}

void Simulator::paintGL()
{
    // Should the depth buffer be cleared as well
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glFlush();
}
