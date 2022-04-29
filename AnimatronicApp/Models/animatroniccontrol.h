#ifndef ANIMATRONICCONTROL_H
#define ANIMATRONICCONTROL_H

#include <QObject>
#include "Controllers/joystickcontroller.h"
#include "Controllers/toolbarcontroller.h"
#include "Threads/communicationthread.h"

class AnimatronicControl : public QObject
{
    Q_OBJECT
public:
    explicit AnimatronicControl(QObject *parent = nullptr);

    JoystickController *joystickController() const;
    void setJoystickController(JoystickController *newJoystickController);

    ToolBarController *toolBarController() const;
    void setToolBarController(ToolBarController *newToolBarController);

    void setConnections();

signals:

private:

    CommunicationThread *m_communicationThread;
    JoystickController *m_joystickController;
    ToolBarController *m_toolBarController;

};

#endif // ANIMATRONICCONTROL_H
