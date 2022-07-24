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
    JoystickController *eyesController = animatronicControl.eyesController();
    SliderController *eyelidsController = animatronicControl.eyelidsController();
    LeverController *leftEyebrowController = animatronicControl.leftEyebrowController();
    LeverController *rightEyebrowController = animatronicControl.rightEyebrowController();

    QQmlApplicationEngine engine;

    // Injects controllers context into qml side
    engine.rootContext()->setContextProperty(QStringLiteral("eyesController"), eyesController);
    engine.rootContext()->setContextProperty(QStringLiteral("toolbarController"), toolBarController);
    engine.rootContext()->setContextProperty(QStringLiteral("eyelidsController"), eyelidsController);
    engine.rootContext()->setContextProperty(QStringLiteral("leftEyebrowController"), leftEyebrowController);
    engine.rootContext()->setContextProperty(QStringLiteral("rightEyebrowController"), rightEyebrowController);

    engine.load(QUrl(QStringLiteral("qrc:/mainview.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
