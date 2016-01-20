#ifndef OBJECTRENDER_H
#define OBJECTRENDER_H

#include <QVector>
#include <QString>
#include <QFile>
#include <QImage>
#include <QTextStream>
#include "./objectmesh.h"
#include "./objecttransformation.h"
#include "./objectmaterial.h"

class ObjectRender {
  public:
    ObjectRender();
    void set_transformation(ObjectTransformation transformation);
    const ObjectTransformation get_transformation();
    void add_object_mesh(ObjectMesh * mesh);
    void set_mesh_material(ObjectMaterial *material, int index);
    void remove_object_mesh(int index);
    ObjectMesh * get_object_mesh(int index);
    int get_mesh_count() const;
    void render_models(QOpenGLShaderProgram *shader, Camara *camara);
    void load_obj(QString filename);
    void load_height_map(QString filename);
    ~ObjectRender();
  private:
    QVector<ObjectMesh *> meshes;
    ObjectTransformation global_transformation;

};

#endif // OBJECTRENDER_H
