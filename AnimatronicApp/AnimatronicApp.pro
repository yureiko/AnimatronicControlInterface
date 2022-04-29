QT += qml scxml serialport

CONFIG += c++11

RESOURCES += \
    animatronic-qml.qrc

HEADERS += \
    Controllers/toolbarcontroller.h \
    Models/animatroniccontrol.h \
    Models/eyescontrol.h \
    Threads/communicationthread.h \
    Controllers/joystickcontroller.h

SOURCES += \
    Controllers/toolbarcontroller.cpp \
    Models/animatroniccontrol.cpp \
    Models/eyescontrol.cpp \
    Threads/communicationthread.cpp \
    Controllers/joystickcontroller.cpp \
    main.cpp
