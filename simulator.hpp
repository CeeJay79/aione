#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include <QGLWidget>
#include "geometricobject.hpp"
#include "graphicalnode.hpp"

class Simulator : public QGLWidget
{
    Q_OBJECT
public:
    explicit Simulator(QWidget *parent = 0);

    void initializeGL();
    void resizeGL(int,int);
    void paintGL();

protected:


signals:

public slots:

private:
    std::vector <GeometricObject*> graphicalObjects;

};

#endif // SIMULATOR_HPP
