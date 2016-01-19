#ifndef OBJECTTRANSFORMATION_H
#define OBJECTTRANSFORMATION_H

#include <QVector3D>

class ObjectTransformation {
  public:
    ObjectTransformation();
    const QVector3D get_position();
    const QVector3D get_orientation();
    const QVector3D get_scale();
    void set_position(QVector3D position);
    void set_orientation(QVector3D orientation);
    void set_scale(QVector3D scale);
    ~ObjectTransformation();
  private:
    QVector3D position;
    QVector3D orientation;
    QVector3D scale;
};

#endif // OBJECTTRANSFORMATION_H
