QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BezierCurve.cpp \
    ChainWidget.cpp \
    MovableWidget.cpp \
    Path.cpp \
    RectangleWidget.cpp \
    RoundedWidget.cpp \
    ScrollAreaWidget.cpp \
    SemicircleWidget.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    BezierCurve.h \
    ChainWidget.h \
    MainWindow.h \
    MovableWidget.h \
    Path.h \
    RectangleWidget.h \
    RoundedWidget.h \
    ScrollAreaWidget.h \
    SemicircleWidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
