#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql
QT+= network charts svg axcontainer multimedia multimediawidgets serialport
QT += charts
QT += widgets printsupport serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app

TARGET = Atelier_Connexion
TEMPLATE = app
QT += printsupport
QT += charts
QT += core gui
QT += core gui charts

LIBS+= -LC:/testingSSL/OpenSSL-Win32
LIBS+= -LC:/testingSSL/OpenSSL-Win32/bin
LIBS+= -lssl32

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    Arduino.cpp \
    Medicament.cpp \
    addtaskdialog.cpp \
    ambulance.cpp \
    employe.cpp \
    equipement.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    notification.cpp \
    smtp.cpp \
    tache.cpp \
    patient.cpp

HEADERS += \
    Arduino.h \
    Medicament.h \
    addtaskdialog.h \
    ambulance.h \
    employe.h \
    equipement.h \
        mainwindow.h \
    connection.h \
    notification.h \
    smtp.h \
    tache.h \
    webaxwidget.h \
    patient.h

FORMS += \
        mainwindow.ui
# QXlsx code for Application Qt project
QXLSX_PARENTPATH=./         # current QXlsx path is . (. means curret directory)
QXLSX_HEADERPATH=./header/  # current QXlsx header path is ./header/
QXLSX_SOURCEPATH=./source/  # current QXlsx source path is ./source/
include(./QXlsx.pri)
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    fond.qrc


DISTFILES += \
    Logo.png \
    fond (2).png \
    fond.png



