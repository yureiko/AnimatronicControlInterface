#ifndef ANIMATRONICCONTROL_H
#define ANIMATRONICCONTROL_H

#include <QObject>
#include "Controllers/joystickcontroller.h"
#include "Controllers/toolbarcontroller.h"
#include "Controllers/slidercontroller.h"
#include "Threads/communicationthread.h"
#include "eyescontrol.h"
#include "eyelidscontrol.h"

class AnimatronicControl : public QObject
{
    Q_OBJECT
public:
    explicit AnimatronicControl(QObject *parent = nullptr);

    JoystickController *joystickController() const;

    ToolBarController *toolBarController() const;

    SliderController *sliderController() const;

signals:

private:

    void sendEyesPosition(QPointF eyesPosition);
    void sendEyelidsPosition(QPair<float,float>);

    CommunicationThread *m_communicationThread;
    JoystickController *m_joystickController;
    ToolBarController *m_toolBarController;
    SliderController *m_sliderController;

    EyesControl *m_eyesControl;
    EyelidsControl *m_eyelidsControl;

};

#endif // ANIMATRONICCONTROL_H
