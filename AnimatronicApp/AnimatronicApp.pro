QT += qml scxml serialport

CONFIG += c++11

RESOURCES += \
    animatronic-images.qrc \
    animatronic-qml.qrc

HEADERS += \
    Controllers/levercontroller.h \
    Controllers/slidercontroller.h \
    Controllers/toolbarcontroller.h \
    Models/animatroniccontrol.h \
    Models/eyelidscontrol.h \
    Models/eyescontrol.h \
    Threads/communicationthread.h \
    Controllers/joystickcontroller.h

SOURCES += \
    Controllers/levercontroller.cpp \
    Controllers/slidercontroller.cpp \
    Controllers/toolbarcontroller.cpp \
    Models/animatroniccontrol.cpp \
    Models/eyelidscontrol.cpp \
    Models/eyescontrol.cpp \
    Threads/communicationthread.cpp \
    Controllers/joystickcontroller.cpp \
    main.cpp
