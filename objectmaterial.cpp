#include "objectmaterial.h"

ObjectMaterial::ObjectMaterial() {
  this->set_diffuse_color(QVector3D(0.5f, 0.5f, 0.5f));
  this->set_ambient_color(QVector3D(0.5f, 0.5f, 0.5f));
  this->set_specular_color(QVector3D(1.0f, 1.0f, 1.0f));
  this->set_specular_intensity(1.0f);
}

const QVector3D ObjectMaterial::get_diffuse_color() {
  return this->diffuse_color;
}

const QVector3D ObjectMaterial::get_specular_color() {
  return this->specular_color;
}

const QVector3D ObjectMaterial::get_ambient_color() {
  return this->ambient_color;
}

float ObjectMaterial::get_specular_intensity() const {
  return this->specular_intensity;
}

void ObjectMaterial::set_diffuse_color(QVector3D diffuse_color) {
  this->diffuse_color = diffuse_color;
}

void ObjectMaterial::set_specular_color(QVector3D specular_color) {
  this->specular_color = specular_color;
}

void ObjectMaterial::set_ambient_color(QVector3D ambient_color) {
  this->ambient_color = ambient_color;
}

void ObjectMaterial::set_specular_intensity(float specular_intensity) {
  this->specular_intensity = specular_intensity;
}

ObjectMaterial::~ObjectMaterial() {

}
