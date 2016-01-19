#ifndef OBJECTMESH_H
#define OBJECTMESH_H

#include <QVector>
#include <QVector3D>
#include <QVector2D>
#include <QMatrix4x4>
#include <QOpenGLBuffer>
#include <QString>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include "./objectmaterial.h"
#include "./objecttransformation.h"
#include "./camara.h"
#define VERTEX "qt_Vertex"
#define NORMAL "qt_Normal"
#define ROTATION_MATRIX "qt_ModelRotationMatrix"
#define AMBIENT "ambient_"
#define SPECULAR "specular_"
#define DIFFUSE "diffuse_"
#define SPECULAR_INTENSITY "specular_intensity_"

class ObjectMesh : protected QOpenGLFunctions {
typedef struct { QVector3D vertex;
         QVector3D normal;
         QVector2D texture_coordinate; } vertex_data;
  public:
    ObjectMesh();
    const QVector3D * get_vertices() const;
    void set_vertices(QVector<QVector3D> vertices);
    const QVector<GLuint> get_vertex_indices();
    void set_vertex_indices(QVector<GLuint> indices);
    const ObjectMaterial * get_material();
    void set_material(ObjectMaterial * material);
    const ObjectTransformation get_transformation();
    void set_transformation(ObjectTransformation transformation);
    const int get_vertex_size() const;
    void draw_mesh(QOpenGLShaderProgram *shader, Camara *camara);
    void allocate_buffers();
    const QVector3D * get_normals() const;
    void set_normals(QVector<QVector3D> normals);
    void set_normal_indices(QVector<GLuint> indices);
    void set_max_data(int data);
    const int get_max_data();
    void restructure_object();
    ~ObjectMesh();
  private:
    QVector<GLuint> vertex_indices;
    QVector<QVector3D> vertices;
    QVector<QVector2D> texture_coordinates;
    QVector<QVector3D> normals;
    QVector<GLuint> normal_indices;
    ObjectMaterial *material;
    ObjectTransformation transformation;
    QOpenGLBuffer vertex_buffer;
    QOpenGLBuffer vertex_index_buffer;
    QOpenGLBuffer normal_buffer;
    QVector<vertex_data> vertex_normal_uv;
    int count_maximum_data;

};

#endif // OBJECTMESH_H
