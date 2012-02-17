#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include <QGLWidget>
#include <QTimerEvent>
#include "geometricobject.hpp"
#include "graphicalnode.hpp"

class Simulator : public QGLWidget
{
    Q_OBJECT
public:
    explicit Simulator(QWidget *parent = 0);
    ~Simulator();

protected:
    void initializeGL();
    void resizeGL(int,int);
    void paintGL();
    void timerEvent(QTimerEvent* e);

private:
    std::vector <GeometricObject*> graphicalObjects;
    GraphicalNode node1;

    int timerID;

signals:
public slots:
};

#endif // SIMULATOR_HPP
