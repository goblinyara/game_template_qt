#include <QApplication>
#include <QDebug>
#include "./renderscene.h"
#include "./characterlevel.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  RenderScene b;
  b.show();
  return a.exec();
}
