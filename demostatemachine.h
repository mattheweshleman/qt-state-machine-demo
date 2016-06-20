#ifndef DEMOSTATEMACHINE_H
#define DEMOSTATEMACHINE_H

#include <QObject>
#include <QStateMachine>
#include <QString>

class DemoStateMachine : public QObject
{
    Q_OBJECT
public:
    explicit DemoStateMachine(QObject *parent = 0);

    void Start();

signals:

    void enteredNormalOperationsState();
    void exitedNormalOperationsState();

    void enteredIdleState();
    void exitedIdleState();

    void enteredDisplayMailReceivedState();
    void exitedDisplayMailReceivedState();

    void enteredCheckBatteryState();
    void exitedCheckBatteryState();

    void enteredFatalErrorState();
    void exitedFatalErrorState();

    //internal use
    void eventOnMailSensorMsgEvent();
    void eventOnBatteryTimerExpiredEvent();
    void eventOnButtonPressEvent();
    void eventOnRadioFatalErrorEvent();

public slots:

    void onMailSensorMsgEvent() { emit eventOnMailSensorMsgEvent(); }
    void onBatteryTimerExpiredEvent() { emit eventOnBatteryTimerExpiredEvent(); }
    void onButtonPressEvent() { emit eventOnButtonPressEvent(); }
    void onRadioFatalErrorEvent() { emit eventOnRadioFatalErrorEvent(); }

private:
    QStateMachine* mpStateMachine;
};

#endif // DEMOSTATEMACHINE_H
