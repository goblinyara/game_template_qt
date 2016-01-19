#-------------------------------------------------
#
# Project created by QtCreator 2015-12-16T19:42:07
#
#-------------------------------------------------

# add GUI, Qt Core and OpenGL ES and Qt Widgets
QT += gui core
QT += opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mmorpg_engine
CONFIG   += console

TEMPLATE = app


SOURCES += main.cpp \
    renderscene.cpp \
    objectmesh.cpp \
    objectmaterial.cpp \
    objecttransformation.cpp \
    objectrender.cpp \
    characterlevel.cpp \
    camara.cpp

HEADERS += \
    renderscene.h \
    objectmesh.h \
    objectmaterial.h \
    objecttransformation.h \
    objectrender.h \
    characterlevel.h \
    camara.h

DISTFILES += \
    fragment.fsh \
    vertex.vsh \
    cube.obj

RESOURCES += \
    qrc.qrc
