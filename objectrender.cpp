#include "objectrender.h"

ObjectRender::ObjectRender() {

}

void ObjectRender::set_transformation(ObjectTransformation transformation) {
  this->global_transformation = transformation;
}

const ObjectTransformation ObjectRender::get_transformation() {
  return this->global_transformation;
}

void ObjectRender::add_object_mesh(ObjectMesh * mesh) {
  meshes.append(mesh);
}

void ObjectRender::remove_object_mesh(int index) {
  if ( index < this->meshes.count())
    this->meshes.removeAt(index);
}

ObjectMesh * ObjectRender::get_object_mesh(int index) {
  return this->meshes.value(index);
}

int ObjectRender::get_mesh_count() const {
  return this->meshes.count();
}

void ObjectRender::render_models(QOpenGLShaderProgram *shader, Camara *camara) {
  foreach ( ObjectMesh * mesh_, this->meshes ) {
      shader->bind();
      mesh_->draw_mesh(shader, camara);
      shader->release();
  }
}

void ObjectRender::set_mesh_material(ObjectMaterial *material, int index) {
  if ( this->meshes.count() > index ) {
    ObjectMesh *mesh = this->meshes.value(index);
    mesh->set_material(material);
    this->meshes.replace(index, mesh);
  }
}

void ObjectRender::load_obj(QString filename) {
  ObjectMesh *mesh = new ObjectMesh();
  QVector< QVector3D > temp_vertices;
  temp_vertices.clear();
  QVector< QVector2D > temp_uvs;
  QVector< QVector3D > temp_normals;
  QVector< GLuint > vertex_indices;
  vertex_indices.clear();
  QVector< GLuint > normal_indices;
  QVector< GLuint > uv_indices;
  QFile textfile(filename);
  textfile.open(QIODevice::ReadOnly | QIODevice::Text);
  QTextStream ascread(&textfile);
    if ( textfile.isOpen() ) {
     QString line = ascread.readLine();
     while ( !line.isNull() ) {
       QStringList list = line.split(" ");
       const unsigned int ListCount = list.count();
       if ( list[0] == "v" ) {
         float *vertex = (float*)malloc(sizeof(float) * ListCount);
         for ( unsigned int i = 0; i < ListCount - 1; i++ )
           QTextStream(&list[i + 1]) >> vertex[i];
              temp_vertices.push_back(QVector3D(vertex[0],
                                                vertex[1],
                                                vertex[2]));
              free(vertex);
            } else if ( list[0] == "vt" ) {
                    float *uv = (float*)malloc(sizeof(float) * ListCount);
                    //float uv[ListCount];
                    for ( unsigned int i = 0; i < ListCount - 1; i++ )
                      QTextStream(&list[i + 1]) >> uv[i];
                      temp_uvs.push_back(QVector2D(uv[0], uv[1]));
                    free(uv);
            } else if ( list[0] == "vn" ) {
                    //float vertexnormal[ListCount];
                    float *vertexnormal = (float*)malloc(sizeof(float) * ListCount);
                    for ( unsigned int i = 0; i < ListCount - 1; i++ )
                      QTextStream(&list[i + 1]) >> vertexnormal[i];
                      temp_normals.push_back(QVector3D(vertexnormal[0],
                                                       vertexnormal[1],
                                                       vertexnormal[2]));
                    free(vertexnormal);
            } else if ( list[0] == "f" ) {
                    unsigned int vertexIndex[3],
                                 uvIndex[3],
                                 normalIndex[3];
                    for ( int i = 0; i < list.count() - 1; i++ ) {
                      QStringList facelist = list[i + 1].split("/");
                      QTextStream(&facelist[0]) >> vertexIndex[i];
                      QTextStream(&facelist[1]) >> uvIndex[i];
                      QTextStream(&facelist[2]) >> normalIndex[i];
                    }
                    for ( int j = 0; j < 3; j++ ) {
                      vertex_indices.push_back(vertexIndex[j] - 1);
                      uv_indices.push_back(uvIndex[j] - 1);
                      normal_indices.push_back(normalIndex[j] - 1);
                    }
            }
            line = ascread.readLine();
        }
        textfile.close();
      }

    QVector< QVector3D > temp_vertices_complete;
    QVector< QVector2D > temp_uvs_complete;
    QVector< QVector3D > temp_normals_complete;

    // For each vertex of each triangle
    for( int i = 0; i < vertex_indices.size(); i++ ){
      int vertex_index = vertex_indices[i];
      QVector3D vertex = temp_vertices[ vertex_index ];
      temp_vertices_complete.push_back(vertex);
    }
    // For each vertex of each triangle
    for( int i = 0; i < uv_indices.size(); i++ ){
      int uv_index = uv_indices[i];
      QVector2D uvs = temp_uvs[ uv_index ];
      temp_uvs_complete.push_back(uvs);
    }
    // For each vertex of each triangle
    for( int k = 0; k < normal_indices.size(); k++ ){
      int normal_index = normal_indices[k];
      QVector3D normal = temp_normals[ normal_index ];
      temp_normals_complete.push_back(normal);
    }
   // vertex_indices.clear();
  //  for ( int p = 0; p < temp_vertices_complete.count(); p++) {
  //      vertex_indices.append(p);
   // }
    mesh->set_vertex_indices(vertex_indices);
    mesh->set_vertices(temp_vertices_complete);
    mesh->set_normals(temp_normals_complete);
   // mesh->set_normal_indices(normal_indices);
    this->add_object_mesh(mesh);

    //mesh->restructure_object();
}

ObjectRender::~ObjectRender() {

}
