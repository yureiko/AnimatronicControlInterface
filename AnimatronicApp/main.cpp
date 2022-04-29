#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Models/animatroniccontrol.h"
#include "Controllers/joystickcontroller.h"
#include "Controllers/toolbarcontroller.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<JoystickController>("controllers", 1, 0,
                                         "JoystickController");
    qmlRegisterType<ToolBarController>("controllers", 1, 0,
                                         "ToolBarController");

    AnimatronicControl animatronicControl;

    ToolBarController *toolBarController = new ToolBarController();
    JoystickController *joystickController = new JoystickController();

    animatronicControl.setToolBarController(toolBarController);
    animatronicControl.setJoystickController(joystickController);
    animatronicControl.setConnections();

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty(QStringLiteral("joystickController"), joystickController);
    engine.rootContext()->setContextProperty(QStringLiteral("toolbarController"), toolBarController);


    engine.load(QUrl(QStringLiteral("qrc:/mainview.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
