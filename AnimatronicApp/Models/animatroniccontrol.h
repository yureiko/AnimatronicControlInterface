#ifndef ANIMATRONICCONTROL_H
#define ANIMATRONICCONTROL_H

#include <QObject>
#include <Controllers/emotionsbuttongradecontroller.h>
#include "Controllers/joystickcontroller.h"
#include "Controllers/toolbarcontroller.h"
#include "Controllers/slidercontroller.h"
#include "Controllers/levercontroller.h"
#include "Threads/communicationthread.h"
#include "eyescontrol.h"
#include "eyelidscontrol.h"
#include "eyebrowscontrol.h"
#include "mouthcontrol.h"
#include "emotionscontrol.h"

/**
 * @brief The AnimatronicControl class manage all animatronic parts
 */
class AnimatronicControl : public QObject
{
public:
    /**
     * @brief Constructor
     * @param parent
     */
    explicit AnimatronicControl(QObject *parent = nullptr);

    /**
     * @brief Gets the eyes controller instance
     * @return eyesController
     */
    JoystickController *eyesController() const;

    /**
     * @brief Gets the toolBar controller instance
     * @return toolBarController
     */
    ToolBarController *toolBarController() const;

    /**
     * @brief Gets the eyelids controller instance
     * @return eyelidsController
     */
    SliderController *superiorEyelidsController() const;

    /**
     * @brief Gets the eyelids controller instance
     * @return eyelidsController
     */
    SliderController *inferiorEyelidsController() const;

    /**
     * @brief Gets the left eyebrow controller instance
     * @return leftEyebrowController
     */
    LeverController *leftEyebrowController() const;

    /**
     * @brief Gets the right eyebrow controller instance
     * @return rightEyebrowController
     */
    LeverController *rightEyebrowController() const;

    /**
     * @brief Gets the mouth controller instance
     * @return mouthController
     */
    SliderController *mouthController() const;

    EmotionsButtonGradeController *emotionsButtonGradeController() const;

private:

    /**
     * @brief send formated eyes position to the communication module
     * @param eyesPosition
     */
    void sendEyesPosition(QPointF eyesPosition);

    /**
     * @brief send formated eyelids position to the communication module
     * @param eyelidsPosition
     */
    void sendEyelidsPosition(QPair<float,float> eyelidsPosition);

    /**
     * @brief send formated eyebrows position to the communication module
     * @param eyebrowsPosition
     */
    void sendEyebrowsRotation(QPair<float, float> eyebrowsPosition);

    /**
     * @brief send formated mouth position to the communication module
     * @param mouthPosition
     */
    void sendMouthPosition(float mouthPosition);

    /**
     * @brief send all parts positions, each per call
     */
    void sendPositions();

    /**
     * @brief starts the communication timer
     */
    void startCommunicationTimer();

    /**
     * @brief stops the communication timer
     */
    void stopCommunicationTimer();

    CommunicationThread *m_communicationThread;
    QTimer *m_communicationTimer;
    JoystickController *m_eyesController;
    ToolBarController *m_toolBarController;
    SliderController *m_superiorEyelidsController;
    SliderController *m_inferiorEyelidsController;
    LeverController *m_leftEyebrowController;
    LeverController *m_rightEyebrowController;
    SliderController *m_mouthController;
    EmotionsButtonGradeController *m_emotionsButtonGradeController;

    EyesControl *m_eyesControl;
    EyelidsControl *m_eyelidsControl;
    EyebrowsControl *m_eyebrowsControl;
    MouthControl *m_mouthControl;
    EmotionsControl *m_emotionsControl;
};

#endif // ANIMATRONICCONTROL_H
