#ifndef RENDERSCENE_H
#define RENDERSCENE_H
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QVector>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include "./objectrender.h"
#include "./objectmaterial.h"
#include "./objectmesh.h"
#include "./objecttransformation.h"
#include "./camara.h"

class RenderScene: public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT
  public:
    explicit RenderScene(QWidget *parent = 0);
    ~RenderScene();

  protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

  private:
    void load_shaders();
    void assign_to_shaders();
    QVector<ObjectRender> objects;
    QOpenGLShaderProgram * shader;
    QOpenGLBuffer vertex_buffer;
    QOpenGLBuffer vertex_index_buffer;
    QVector<Camara *> camara_;
};

#endif // RENDERSCENE_H
