#ifndef ANIMATRONICCONTROL_H
#define ANIMATRONICCONTROL_H

#include <QObject>
#include "Controllers/joystickcontroller.h"
#include "Controllers/toolbarcontroller.h"
#include "Threads/communicationthread.h"
#include "eyescontrol.h"

class AnimatronicControl : public QObject
{
    Q_OBJECT
public:
    explicit AnimatronicControl(QObject *parent = nullptr);

    JoystickController *joystickController() const;

    ToolBarController *toolBarController() const;

signals:

private:

    void sendEyesPosition(QPointF eyesPosition);

    CommunicationThread *m_communicationThread;
    JoystickController *m_joystickController;
    ToolBarController *m_toolBarController;

    EyesControl *m_eyesControl;

};

#endif // ANIMATRONICCONTROL_H
