#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Models/animatroniccontrol.h"

/**
 * @brief This application follows the MVC architecture, when the models are terminated by "control" sufix
 * views have the ".qml" extensions and controllers are terminated by "controller" sufix
 */
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Registers all Controllers into qml
    qmlRegisterType<JoystickController>("controllers", 1, 0,
                                         "JoystickController");
    qmlRegisterType<ToolBarController>("controllers", 1, 0,
                                         "ToolBarController");
    qmlRegisterType<SliderController>("controllers", 1, 0,
                                         "SliderController");
    qmlRegisterType<LeverController>("controllers", 1, 0,
                                         "LeverController");
    // Creates root class
    AnimatronicControl animatronicControl;

    // Brings controllers references to main context
    ToolBarController *toolBarController = animatronicControl.toolBarController();
    JoystickController *eyesController = animatronicControl.eyesController();
    SliderController *superiorEyelidsController = animatronicControl.superiorEyelidsController();
    SliderController *inferiorEyelidsController = animatronicControl.inferiorEyelidsController();
    LeverController *leftEyebrowController = animatronicControl.leftEyebrowController();
    LeverController *rightEyebrowController = animatronicControl.rightEyebrowController();
    SliderController *mouthController = animatronicControl.mouthController();
    EmotionsButtonGradeController *emotionsButtonGradeController = animatronicControl.emotionsButtonGradeController();

    QQmlApplicationEngine engine;

    // Injects controllers context into qml side
    engine.rootContext()->setContextProperty(QStringLiteral("eyesController"), eyesController);
    engine.rootContext()->setContextProperty(QStringLiteral("toolbarController"), toolBarController);
    engine.rootContext()->setContextProperty(QStringLiteral("superiorEyelidsController"), superiorEyelidsController);
    engine.rootContext()->setContextProperty(QStringLiteral("inferiorEyelidsController"), inferiorEyelidsController);
    engine.rootContext()->setContextProperty(QStringLiteral("leftEyebrowController"), leftEyebrowController);
    engine.rootContext()->setContextProperty(QStringLiteral("rightEyebrowController"), rightEyebrowController);
    engine.rootContext()->setContextProperty(QStringLiteral("mouthController"), mouthController);
    engine.rootContext()->setContextProperty(QStringLiteral("emotionsButtonGradeController"), emotionsButtonGradeController);

    engine.load(QUrl(QStringLiteral("qrc:/Views/mainview.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
