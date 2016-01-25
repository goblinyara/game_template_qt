#include "objecttransformation.h"

ObjectTransformation::ObjectTransformation() {
  this->set_position(QVector3D(0, 0, 0));
  this->set_orientation(QVector3D(0, 0, 0));
  this->set_scale(QVector3D(1.0f, 1.0f, 1.0f));
}
const QVector3D ObjectTransformation::get_position() const {
  const QVector3D position = this->position;
  return position;
}

const QVector3D ObjectTransformation::get_orientation() const {
  return this->orientation;
}

const QVector3D ObjectTransformation::get_scale() const {
  return this->scale;
}

void ObjectTransformation::set_position(QVector3D position) {
  this->position = position;
}

void ObjectTransformation::set_orientation(QVector3D orientation) {
  this->orientation = orientation;
}

void ObjectTransformation::set_scale(QVector3D scale) {
  this->scale = scale;
}

ObjectTransformation::~ObjectTransformation() {

}
