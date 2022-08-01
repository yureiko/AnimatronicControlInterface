#ifndef ANIMATRONICCONTROL_H
#define ANIMATRONICCONTROL_H

#include <QObject>
#include "Controllers/joystickcontroller.h"
#include "Controllers/toolbarcontroller.h"
#include "Controllers/slidercontroller.h"
#include "Controllers/levercontroller.h"
#include "Threads/communicationthread.h"
#include "eyescontrol.h"
#include "eyelidscontrol.h"
#include "eyebrowscontrol.h"
#include "mouthcontrol.h"

class AnimatronicControl : public QObject
{
    Q_OBJECT
public:
    explicit AnimatronicControl(QObject *parent = nullptr);

    JoystickController *eyesController() const;

    ToolBarController *toolBarController() const;

    SliderController *eyelidsController() const;

    LeverController *leftEyebrowController() const;

    LeverController *rightEyebrowController() const;

    SliderController *mouthController() const;

signals:

private:

    void sendEyesPosition(QPointF eyesPosition);
    void sendEyelidsPosition(QPair<float,float> eyelidsPosition);
    void sendEyebrowsRotation(QPair<float, float> eyebrowsPosition);
    void sendMouthPosition(float mouthPosition);

    CommunicationThread *m_communicationThread;
    JoystickController *m_eyesController;
    ToolBarController *m_toolBarController;
    SliderController *m_eyelidsController;
    LeverController *m_leftEyebrowController;
    LeverController *m_rightEyebrowController;
    SliderController *m_mouthController;

    EyesControl *m_eyesControl;
    EyelidsControl *m_eyelidsControl;
    EyebrowsControl *m_eyebrowsControl;
    MouthControl *m_mouthControl;
};

#endif // ANIMATRONICCONTROL_H
