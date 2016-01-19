#ifndef OBJECTMATERIAL_H
#define OBJECTMATERIAL_H

#include <QVector3D>

class ObjectMaterial {
  public:
    ObjectMaterial();
    const QVector3D get_diffuse_color();
    const QVector3D get_specular_color();
    const QVector3D get_ambient_color();
    float get_specular_intensity() const;
    void set_diffuse_color(QVector3D diffuse_color);
    void set_specular_color(QVector3D specular_color);
    void set_ambient_color(QVector3D ambient_color);
    void set_specular_intensity(float specular_intensity);
    ~ObjectMaterial();

  private:
    QVector3D diffuse_color;
    QVector3D specular_color;
    QVector3D ambient_color;
    float specular_intensity;
};

#endif // OBJECTMATERIAL_H
