#include "camara.h"

Camara::Camara() {
  this->camara_.setToIdentity();
}
void Camara::set_camara_look_at(QVector3D center,
                                QVector3D position) {
  this->camara_.lookAt(position, center, QVector3D(0, 1, 0));
}
QMatrix4x4 Camara::get_camara() {
  return this->camara_;
}

Camara::~Camara() {

}

