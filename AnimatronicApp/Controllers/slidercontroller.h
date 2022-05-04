#ifndef SLIDERCONTROLLER_H
#define SLIDERCONTROLLER_H

#include <QObject>

class SliderController : public QObject
{
    Q_OBJECT
public:
    explicit SliderController(QObject *parent = nullptr);

    float sliderPosition() const;

signals:
    void sliderPositionChanged();

public slots:
    Q_INVOKABLE void onPositionChanged(float position);

private:
    float m_sliderPosition;
};

#endif // SLIDERCONTROLLER_H
