#include "demostatemachine.h"
#include <QState>
#include <QSignalTransition>

DemoStateMachine::DemoStateMachine(QObject *parent) :
    QObject(parent),
    mpStateMachine(nullptr)
{
    mpStateMachine = new QStateMachine(this);

    QState* fatalErrorState = new QState(mpStateMachine);
    QState* normalOperationsState = new QState(mpStateMachine);

    QState* idleState = new QState(normalOperationsState);
    QState* displayMailReceivedState = new QState(normalOperationsState);
    QState* displayCheckBatteryState = new QState(normalOperationsState);

    //set top level initial state
    mpStateMachine->setInitialState(normalOperationsState);

    //set normal ops state initial state
    normalOperationsState->setInitialState(idleState);

    //parent state normal operations catch all transitions
    QSignalTransition * buttonIdleTransition = normalOperationsState->addTransition(this, &DemoStateMachine::eventOnButtonPressEvent, idleState);
    buttonIdleTransition->setTransitionType(QSignalTransition::InternalTransition);

    normalOperationsState->addTransition(this, &DemoStateMachine::eventOnRadioFatalErrorEvent, fatalErrorState);

    //idle specific transitions
    idleState->addTransition(this, &DemoStateMachine::eventOnMailSensorMsgEvent, displayMailReceivedState);
    idleState->addTransition(this, &DemoStateMachine::eventOnBatteryTimerExpiredEvent, displayCheckBatteryState);

    connect(fatalErrorState, &QState::entered, this, &DemoStateMachine::enteredFatalErrorState);
    connect(fatalErrorState, &QState::exited, this, &DemoStateMachine::exitedFatalErrorState);

    connect(normalOperationsState, &QState::entered, this, &DemoStateMachine::enteredNormalOperationsState);
    connect(normalOperationsState, &QState::exited, this, &DemoStateMachine::exitedNormalOperationsState);

    connect(idleState, &QState::entered, this, &DemoStateMachine::enteredIdleState);
    connect(idleState, &QState::exited, this, &DemoStateMachine::exitedIdleState);

    connect(displayCheckBatteryState, &QState::entered, this, &DemoStateMachine::enteredCheckBatteryState);
    connect(displayCheckBatteryState, &QState::exited, this, &DemoStateMachine::exitedCheckBatteryState);

    connect(displayMailReceivedState, &QState::entered, this, &DemoStateMachine::enteredDisplayMailReceivedState);
    connect(displayMailReceivedState, &QState::exited, this, &DemoStateMachine::exitedDisplayMailReceivedState);
}

void DemoStateMachine::Start()
{
    mpStateMachine->start();
}
