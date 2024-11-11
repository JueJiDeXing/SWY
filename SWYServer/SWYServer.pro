
QT       += core gui
QT  += network
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TcpServer
TEMPLATE = app


SOURCES += main.cpp \
    database.cpp \
    swyserver.cpp

HEADERS  += \
    Room.h \
    Seat.h \
    User.h \
    Util.h \
    database.h \
    swyserver.h

FORMS    +=
