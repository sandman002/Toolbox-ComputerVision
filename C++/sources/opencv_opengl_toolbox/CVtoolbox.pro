#-------------------------------------------------
#
# Project created by QtCreator 2015-02-09T20:03:57
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MdiArea
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    CvGLWidget.cpp \
    explorerhisto.cpp \
    customkernel.cpp \
    kernel2d.cpp \
    morphprocess.cpp \
    custommorph.cpp \
    thresholdui.cpp \
    someclass.cpp \
    cvglcam.cpp \
    cam.cpp \
    collage.cpp \
    console.cpp \
    contoursui.cpp \
    calibwindow.cpp \
    calibacam.cpp \
    fundoptui.cpp \
    featuresui.cpp \
    brightcontrastui.cpp

HEADERS  += mainwindow.h \
    CvGlWidget.h \
    explorerhisto.h \
    harriscorner.h \
    customkernel.h \
    kernel2d.h \
    morphprocess.h \
    custommorph.h \
    thresholdui.h \
    someclass.h \
    cvglcam.h \
    cam.h \
    collage.h \
    matcher.h \
    contoursui.h \
    calibwindow.h \
    calibacam.h \
    fundoptui.h \
    featuresui.h \
    brightcontrastui.h

FORMS    += mainwindow.ui \
    explorerhisto.ui \
    customkernel.ui \
    custommorph.ui \
    thresholdui.ui \
    cam.ui \
    contoursui.ui \
    calibwindow.ui \
    fundoptui.ui \
    featuresui.ui \
    brightcontrastui.ui

INCLUDEPATH += /usr/local/include/opencv2
LIBS += -L/usr/local/lib
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_contrib
LIBS += -lopencv_legacy
LIBS += -lopencv_flann
LIBS += -lopencv_nonfree

OTHER_FILES +=

RESOURCES += \
    background.qrc
