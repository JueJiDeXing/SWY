QT       += core gui network concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TcpClient
TEMPLATE = app


SOURCES += main.cpp\
    Swygame.cpp \
    game_backpackwdiget.cpp \
    game_friendwdiget.cpp \
    game_mainwdiget.cpp \
    login.cpp \
    mainwdiget.cpp \
    register.cpp \
    roomwidget.cpp \
    user_mainwidget.cpp \
    widgetmanager.cpp

HEADERS += \
    Card.h \
    Room.h \
    Seat.h \
    Swygame.h \
    User.h \
    Util.h \
    game_backpackwdiget.h \
    game_friendwdiget.h \
    game_mainwdiget.h \
    login.h \
    mainwdiget.h \
    register.h \
    roomwidget.h \
    user_mainwidget.h \
    widgetmanager.h

FORMS += \
    game_backpackwdiget.ui \
    game_friendwdiget.ui \
    game_mainwdiget.ui \
    login.ui \
    mainwdiget.ui \
    register.ui \
    roomwidget.ui \
    user_mainwidget.ui

RESOURCES += \
    QRC.qrc

