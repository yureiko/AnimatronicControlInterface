#ifndef EYESCONTROL_H
#define EYESCONTROL_H

#include <QObject>

class EyesControl : public QObject
{
    Q_OBJECT
public:
    explicit EyesControl(QObject *parent = nullptr);

signals:

};

#endif // EYESCONTROL_H
