#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include <QGLWidget>

class Simulator : public QGLWidget
{
    Q_OBJECT
public:
    explicit Simulator(QWidget *parent = 0);

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

signals:

public slots:

};

#endif // SIMULATOR_HPP
