#-------------------------------------------------
#
# Project created by QtCreator 2019-04-09T10:25:54
#
#-------------------------------------------------

QT       += widgets
QT       += gui

TARGET = ExampleServer

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11


SOURCES += main.cpp \
    HttpServer.cpp \
    ServerDialog.cpp

win32 {
    INCLUDEPATH += D:/Project/Boost_1_63_0

    LIBS += -LD:/Project/Boost_1_63_0/stage/lib \
            -llibboost_system-mgw48-mt-d-1_63 \
            -llibboost_thread-mgw48-mt-d-1_63 \
            -lWs2_32

    DEFINES  += BOOST_ENABLE_ASSERT_DEBUG_HANDLER \
                NDEBUG

}

HEADERS += \
    Server.h \
    HttpServer.h \
    ServerDialog.h
