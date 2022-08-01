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
    Models/eyebrowscontrol.h \
    Models/eyelidscontrol.h \
    Models/eyescontrol.h \
    Models/mouthcontrol.h \
    Threads/communicationthread.h \
    Controllers/joystickcontroller.h

SOURCES += \
    Controllers/levercontroller.cpp \
    Controllers/slidercontroller.cpp \
    Controllers/toolbarcontroller.cpp \
    Models/animatroniccontrol.cpp \
    Models/eyebrowscontrol.cpp \
    Models/eyelidscontrol.cpp \
    Models/eyescontrol.cpp \
    Models/mouthcontrol.cpp \
    Threads/communicationthread.cpp \
    Controllers/joystickcontroller.cpp \
    main.cpp
