#include "simulator.hpp"

double pi = atan(1.0)*4.0;

Simulator::Simulator(QWidget *parent) :
    QGLWidget(parent)
{
    xRot = yRot = zRot = 0;
    zHomeView = -40;
    timerID = 0;
    timerID = startTimer(20);
}

Simulator::~Simulator()
{
    for (unsigned int i=0; i<graphicalObjects.size(); i++)
    {
        delete graphicalObjects[i]; // < ----- Is this doing its job
    }
    // Do i need to popback to avoid memory leaks !!!
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

    glTranslated(0.0,0.0,zHomeView);
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

void Simulator::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Needs to be moved to more optimal place - no need to call if no rotation is needed
    glRotatef(xRot/16.0,1.0,0.0,0.0);
    glRotatef(yRot/16.0,0.0,1.0,0.0);
    glRotatef(zRot/16.0,0.0,0.0,1.0);
    // ----------------------------------------------------------------------------------

    for (unsigned int i=0; i<graphicalObjects.size(); i++)
    {
        graphicalObjects[i]->draw();
    }

    glFlush();
}

void::Simulator::drawSolutionPath(Node* solNode)
{
    double solutionColor[3] = {0.0,0.0,1.0};

    while (true)
    {
        int nID = solNode->getNodeID();
        nodeMap[nID]->setClr(solutionColor);

        if (solNode->parentNode == NULL)
            break;

        std::vector <Edge*>* solSuccessors;
        solSuccessors = (solNode->parentNode)->getSuccessors();

        std::vector <Edge*>::iterator it;
        for(it = solSuccessors->begin(); it != solSuccessors->end(); it++)
        {
            if (solNode == (*it)->getTarget())
            {
                int eID = (*it)->getEdgeID();
                edgeMap[eID]->setClr(solutionColor);
                solNode = (*it)->getSource();
                break;
            }
        }
    }
}

void Simulator::notify()
{
}

void Simulator::notify(int __ID,NotificationType updateType)
{
    double exploredColor[3];
    exploredColor[0] = 1.0;
    exploredColor[1] = 0.0;
    exploredColor[2] = 1.0;

    if (updateType == NODE_UPDATE)
    {
        nodeMap[__ID]->setClr(exploredColor);
    }
    else if (updateType == EDGE_UPDATE)
    {
        edgeMap[__ID]->setClr(exploredColor);
    }

    if (!timerID)
        updateGL();
}

void Simulator::initializeNetwork(std::map<int,MechanicalNode*>* inMap)
{
    network = inMap;
    createNetwork();
}

void Simulator::createNetwork()
{
    // Declare Variables
    std::vector <Node*> nodesWithEdges;

    // Create Graphical Nodes and Nodes
    std::map <int,MechanicalNode*>::iterator it;
    for (it = network->begin(); it != network->end(); it++)
    {
        // Create Graphical Nodes
        GraphicalNode* gNode = new GraphicalNode();
        graphicalObjects.push_back(gNode);
        nodeMap.insert(std::pair<int,GraphicalNode*>((*it).first,gNode));
        double* posSource = ((*it).second)->getPos();
        gNode->setRadius(1);
        gNode->setPosition(posSource);
        gNode->create();

        // Create Graphical Edges
        std::vector <Edge*>* successors = ((*it).second)->getSuccessors();
        for (unsigned int i=0; i<successors->size(); i++)
        {
            Node* targetNode = (successors->at(i))->getTarget();

            bool skip = 0;
            for (unsigned int j=0; j<nodesWithEdges.size(); j++)
            {
                if (nodesWithEdges[j] == targetNode)
                {
                    skip = 1;
                    break;
                }
            }
            if (skip)
                continue;

            double* posTarget = ((MechanicalNode*)(targetNode))->getPos();
            double deltaX = posTarget[0] - posSource[0];
            double deltaY = posTarget[1] - posSource[1];
            double deltaZ = posTarget[2] - posSource[2];
            double length = sqrt(deltaX*deltaX + deltaY*deltaY + deltaZ*deltaZ);

            double theta = asin(deltaX/length);
            double phi = asin(-deltaY/length/cos(theta));
            if (deltaZ < 0)
                phi = pi - phi;

            double xRotation = phi * 180/pi;
            double yRotation = theta * 180/pi;
            double zRotation = 0;
            double rotations[3] = {xRotation,yRotation,zRotation};

            GraphicalEdge* gEdge = new GraphicalEdge();
            graphicalObjects.push_back(gEdge);
            edgeMap.insert(std::pair<int,GraphicalEdge*>((successors->at(i))->getEdgeID(),gEdge));
//            edgeMap.push_back(gEdge);

            gEdge->setPosition(posSource);
            gEdge->setDimension(0.2,length);
            gEdge->setOrientation(rotations);
            gEdge->create();
        }
        nodesWithEdges.push_back((*it).second);
    }
}

void Simulator::keyPressEvent(QKeyEvent* event)
{
    switch(event->key())
    {
    case Qt::Key_H:
        homeView();
        break;
    }
}

void Simulator::timerEvent(QTimerEvent* event)
{
    updateGL();
}

void Simulator::mousePressEvent(QMouseEvent* event)
{
    lastPos = event->pos();
}

void Simulator::mouseMoveEvent(QMouseEvent* event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() && Qt::LeftButton)
    {
        setXRotation(xRot + 8*dy);
        setYRotation(yRot + 8*dx);
    }
    else if (event->buttons() && Qt::RightButton)
    {
        setXRotation(xRot + 8*dy);
        setZRotation(zRot + 8*dx);
    }

    lastPos = event->pos();

    if (!timerID)
        updateGL();
}

void Simulator::mouseReleaseEvent(QMouseEvent* e)
{
    xRot = 0;
    yRot = 0;
    zRot = 0;
}

void Simulator::setXRotation(int angle)
{
    normalizeAngle(angle);
    if (angle != xRot)
    {
        xRot = angle;
    }
}

void Simulator::setYRotation(int angle)
{
    normalizeAngle(angle);
    if (angle != yRot)
    {
        yRot = angle;
    }
}

void Simulator::setZRotation(int angle)
{
    normalizeAngle(angle);
    if (angle != zRot)
    {
        zRot = angle;
    }
}

void Simulator::normalizeAngle(int& angle)
{
    while (angle < 0)
        angle += 360*16;
    while (angle > 360*16)
        angle -= 360*16;
}

int Simulator::getXRotation()
{
    return xRot;
}

int Simulator::getYRotation()
{
    return yRot;
}

int Simulator::getZRotation()
{
    return zRot;
}

void Simulator::homeView()
{
    glLoadIdentity();
    glTranslated(0.0,0.0,zHomeView);
    xRot = 0;
    yRot = 0;
    zRot = 0;

    if (!timerID)
        updateGL();
}
