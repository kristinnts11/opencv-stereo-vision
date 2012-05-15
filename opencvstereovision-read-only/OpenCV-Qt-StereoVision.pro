# -------------------------------------------------
# Project created by QtCreator 2009-06-25T18:55:22
# -------------------------------------------------
TARGET = OpenCV-Qt-StereoCalibration
TEMPLATE = app

# OpenCV
LIBS +=`pkg-config opencv --cflags --libs`
INCLUDEPATH += /usr/local/include/opencv
SOURCES += main.cpp \
    mainwindow.cpp \
    stereovision.cpp \
    stereocamera.cpp \
    stereovisiontest.cpp
HEADERS += mainwindow.h \
    stereovision.h \
    stereocamera.h \
    ui_mainwindow.h
FORMS += mainwindow.ui
