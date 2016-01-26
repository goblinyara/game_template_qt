#include "renderscene.h"

RenderScene::RenderScene(QWidget *parent): QOpenGLWidget(parent), rotate_y(0.0f) {
  this->camara_.clear();
  this->shader = new QOpenGLShaderProgram(this);
  connect(&this->frame_sync, SIGNAL(timeout()), this, SLOT(update_scene()));
  this->frame_sync.start(1);
}

void RenderScene::initializeGL() {
  /* this initializes all the opengl functions
   * this is needed for all the gl* functions
   * such as glClear, glClearColor, etc.
   */
  initializeOpenGLFunctions();

  ObjectMaterial * material = new ObjectMaterial();
  ObjectRender *render = new ObjectRender();
  material->set_ambient_color(QVector3D(0.0, 0.0, 0.0));
  material->set_diffuse_color(QVector3D(0.5, 0.5, 0.5));


  render->add_object_mesh(render->load_obj("://Cube"));
  //render->load_height_map("://Terrain_Texture");
  for ( int i = 0; i < render->get_mesh_count(); i++)
    render->set_mesh_material(material, i);
  this->objects.append(*render);
  this->objects.append(*render);
  this->camara_.append(new Camara());
}

void RenderScene::resizeGL(int w, int h) {
  /* changes the size of the window */
  //this->setGeometry(this->x(), this->y(), w, h);
  this->projection.setToIdentity();
  this->projection.perspective(60.0f,
                         static_cast<float>(w) / static_cast<float>(h),
                         0.1f, 1000.0f);
}

void RenderScene::load_shaders() {
  if ( !this->shader->isLinked() ) {
    qDebug() << "Vertex Shader added: "
             << this->shader->addShaderFromSourceFile(QOpenGLShader::Vertex,
                                                      "://Vertex");
    // load the pixel/fragment shader.
    // this is the pixel shader (per pixel rendering)
    qDebug() << "Pixel Shader added:"
             << this->shader->addShaderFromSourceFile(QOpenGLShader::Fragment,
                                                      "://Fragment");
    this->shader->link();
  }
}

void RenderScene::assign_to_shaders() {
  // assign each mesh
  foreach ( ObjectRender object_, this->objects ) {
    for ( int i = 0; i < object_.get_mesh_count(); i++) {
      object_.render_models(shader, new Camara());
    }
  }
}

void RenderScene::paintGL() {
  load_shaders();

   glDepthMask(GL_TRUE);
  /* clear the depth */
  glClearDepth(1.0f);
  /* enable the depth test */
  glEnable(GL_DEPTH_TEST);
  /* enable cullmode CCW (counter clockwise) */
  //glEnable(GL_CULL_FACE);
  /* sets the color the screen needs to be cleared with */
  glClearColor(0.392f, 0.584f, 0.929f, 1.0f);
  /* Clear the selected bits */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // Turn on wireframe mode
 // glPolygonMode(GL_FRONT, GL_LINE);
 // glPolygonMode(GL_BACK, GL_LINE);
  // bind the shader
  this->shader->bind();

  QMatrix4x4 view;
  view.lookAt(QVector3D(2, 2, 2), QVector3D(0.1, 0.2, 0.1), QVector3D(0,1,0));

  view.rotate(rotate_y, 0 ,1 ,0);
  this->shader->bind();
  this->shader->setUniformValue("qt_ProjectionMatrix",  projection);
  this->shader->setUniformValue("qt_ViewMatrix",  view);
  this->shader->release();

  if ( this->shader->isLinked() ) {
    assign_to_shaders();
  }
  // Turn on wireframe mode
  // glPolygonMode(GL_FRONT, GL_LINE);
  // glPolygonMode(GL_BACK, GL_LINE);
  // bind the shader
  glDisable(GL_CULL_FACE);
  glDisable(GL_DEPTH_TEST);

}
void RenderScene::update_scene() {
    paintGL();
    rotate_y += 0.25f;
    update();
}

RenderScene::~RenderScene() {
    this->vertex_buffer.destroy();
    this->vertex_index_buffer.destroy();
}
