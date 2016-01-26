#include "objectmesh.h"

ObjectMesh::ObjectMesh() : vertex_index_buffer(QOpenGLBuffer::IndexBuffer) {
  initializeOpenGLFunctions();
  vertex_buffer.create();
  vertex_index_buffer.create();
  normal_buffer.create();
}
void ObjectMesh::set_max_data(int data) {
  this->count_maximum_data = data;
}

const int ObjectMesh::get_max_data() {
  return this->count_maximum_data;
}

const QVector3D * ObjectMesh::get_vertices() const {
  return this->vertices.constData();
}
const QVector3D * ObjectMesh::get_normals() const {
  return this->normals.constData();
}
void ObjectMesh::set_normals(QVector<QVector3D> normals) {
  this->normals.clear();
  this->normals = normals;
/*  for ( int i = 0; i < normals.count(); i++) {
    vertex_data dat = this->vertex_normal_uv.value(i);
    dat.normal = normals.value(i);
    this->vertex_normal_uv.replace(i, dat);
  }*/
  // assign buffer for normal
  //this->normal_buffer.bind();
  //this->normal_buffer.allocate(this->normals.constData(),
   //                            this->normals.count() * sizeof(QVector3D));
}

void ObjectMesh::set_normal_indices(QVector<GLuint> indices) {
  this->normal_indices.clear();
  this->normal_indices = indices;
}

void ObjectMesh::set_vertices(QVector<QVector3D> vertices) {
  this->vertices.clear();
  this->vertices = vertices;
  // assign buffer for the vertices
 // this->vertex_buffer.bind();
//  this->vertex_buffer.allocate(this->vertices.constData(),
  //                             this->vertices.count() * sizeof(QVector3D) );
}

const QVector<GLuint> ObjectMesh::get_vertex_indices() {
  return this->vertex_indices;
}

void ObjectMesh::set_vertex_indices(QVector<GLuint> indices) {
  this->vertex_indices.clear();
  this->vertex_indices = indices;
 // this->vertex_index_buffer.bind();
  //this->vertex_index_buffer.allocate(this->vertex_indices.constData(),
   //                                  this->vertex_indices.count() * sizeof(GL_UNSIGNED_INT));
}

const ObjectMaterial * ObjectMesh::get_material() {
  return this->material;
}

void ObjectMesh::set_material(ObjectMaterial * material) {
  this->material = material;
}

const ObjectTransformation ObjectMesh::get_transformation() const {
  return this->transformation;
}

void ObjectMesh::set_transformation(ObjectTransformation transformation) {
  this->transformation = transformation;
}

const int ObjectMesh::get_vertex_size() const {
  return this->vertices.count();
}

void ObjectMesh::restructure_object() {
 /* QVector<QVector3D> temp_normals = this->normals;
  //this->normals.clear();
 // this->normals.fill(QVector3D(), this->vertices.count());
  for (int i = 0; i < this->vertex_indices.count(); i++) {
      this->normals.replace(this->vertex_indices.value(i),
                            temp_normals.value(this->normal_indices.value(i)));
  }
  qDebug() << this->normals.count();
  for (int a = 0; a < temp_normals.count(); a++) {
    qDebug() << temp_normals.value(a) << " -> " << this->normals.value(a);
  }*/
}

void ObjectMesh::draw_mesh( QOpenGLShaderProgram * shader, Camara *camara) {
  // add rotation to the model
  QMatrix4x4 rotation;
  rotation.rotate(this->transformation.get_orientation().x(), 1, 0, 0);
  rotation.rotate(this->transformation.get_orientation().y(), 0, 1, 0);
  rotation.rotate(this->transformation.get_orientation().z(), 0, 0, 1);
  shader->setUniformValue(ROTATION_MATRIX, rotation);
  shader->setUniformValue(DIFFUSE, this->material->get_diffuse_color());
  shader->setUniformValue(AMBIENT, this->material->get_ambient_color());
  int vertex_location = shader->attributeLocation(VERTEX);
  int normal_location = shader->attributeLocation(NORMAL);
  // bind the vertices
  //this->vertex_buffer.bind();

  shader->enableAttributeArray(vertex_location);
  //shader->setAttributeBuffer(vertex_location, GL_FLOAT, 0, 3, sizeof(QVector3D));
  shader->setAttributeArray(vertex_location, this->vertices.constData());
  //this->vertex_buffer.release();

  // bind the normals
 // this->normal_buffer.bind();
  shader->enableAttributeArray(normal_location);
  shader->setAttributeArray(normal_location, this->normals.constData());
  //this->normal_buffer.release();

  // bind the normals
  //this->vertex_index_buffer.bind();
  //glDrawElements(GL_TRIANGLES, this->vertex_indices.count(), GL_UNSIGNED_INT, 0);
  glDrawArrays(GL_TRIANGLES, 0, this->vertices.size() );
  //this->vertex_index_buffer.release();

  glDisableVertexAttribArray(vertex_location);
  glDisableVertexAttribArray(normal_location);

}

void ObjectMesh::allocate_buffers() {

}

ObjectMesh::~ObjectMesh() {
  /* does not need to be deleted */
  delete this->material;
  this->vertex_buffer.destroy();
  this->vertex_index_buffer.destroy();
}
