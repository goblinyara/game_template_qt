#ifndef CAMARA_H
#define CAMARA_H

#include <QMatrix4x4>

class Camara {
  public:
    void set_camara_look_at(QVector3D center, QVector3D position);
    QMatrix4x4 get_camara();
    Camara();
    ~Camara();
  private:
    QMatrix4x4 camara_;
};

#endif // CAMARA_H
