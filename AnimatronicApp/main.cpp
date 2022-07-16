#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Models/animatroniccontrol.h"
#include "Controllers/joystickcontroller.h"
#include "Controllers/toolbarcontroller.h"
#include "Controllers/slidercontroller.h"
#include "Controllers/levercontroller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<JoystickController>("controllers", 1, 0,
                                         "JoystickController");
    qmlRegisterType<ToolBarController>("controllers", 1, 0,
                                         "ToolBarController");
    qmlRegisterType<SliderController>("controllers", 1, 0,
                                         "ToolBarController");
    qmlRegisterType<LeverController>("controllers", 1, 0,
                                         "LeverController");
    // Creates root class
    AnimatronicControl animatronicControl;

    // Brings controllers references to main context
    ToolBarController *toolBarController = animatronicControl.toolBarController();
    JoystickController *joystickController = animatronicControl.joystickController();
    SliderController *sliderController = animatronicControl.sliderController();
    LeverController *leverController = animatronicControl.leverController();

    QQmlApplicationEngine engine;

    // Injects controllers context into qml side
    engine.rootContext()->setContextProperty(QStringLiteral("joystickController"), joystickController);
    engine.rootContext()->setContextProperty(QStringLiteral("toolbarController"), toolBarController);
    engine.rootContext()->setContextProperty(QStringLiteral("sliderController"), sliderController);
    engine.rootContext()->setContextProperty(QStringLiteral("leverController"), leverController);

    engine.load(QUrl(QStringLiteral("qrc:/mainview.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
