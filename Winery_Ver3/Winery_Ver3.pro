#-------------------------------------------------
#
# Project created by QtCreator 2015-02-18T23:13:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Winery_Ver3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    helpwindow.cpp \
    wine.cpp \
    Winery.cpp \
    WriteWineriesToFile.cpp \
    FileToWineries.cpp \
    wineshoppingcart.cpp\
    EditWineAdmin.cpp \
    AddWineAdmin.cpp \
    tourwinerieswidget.cpp \
    takeATrip.cpp \
    shortestPath.cpp \
    shortestTripAlgorithm.cpp

HEADERS  += mainwindow.h \
    helpwindow.h \
    Winery.h \
    wine.h \
    wineshoppingcart.h \
    tourwinerieswidget.h

FORMS    += mainwindow.ui \
    helpwindow.ui \
    wineshoppingcart.ui \
    tourwinerieswidget.ui

RESOURCES += \
    images/Img.qrc

OTHER_FILES += \
    wineries.txt \
    ../../Qt/Tools/QtCreator/bin/build-Winery_Ver3-Desktop_Qt_Qt_Version_MinGW_32bit-Debug/wineries.txt
