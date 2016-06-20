#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "demostatemachine.h"
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mpDemoStateMachine(nullptr)
{
    ui->setupUi(this);
    mpDemoStateMachine = new DemoStateMachine(this);

    connect(ui->batteryTimerExpiredButton, &QPushButton::clicked, [=](){
        AppendTextToInfoDisplay("Event: Battery Timer Expired");
    });
    connect(ui->buttonPressButton, &QPushButton::clicked, [=](){
        AppendTextToInfoDisplay("Event: Button Press");
    });
    connect(ui->mailSensorMsg, &QPushButton::clicked, [=](){
        AppendTextToInfoDisplay("Event: Mail Sensor Msg");
    });
    connect(ui->radioFatalErrorButton, &QPushButton::clicked, [=](){
        AppendTextToInfoDisplay("Event: Radio Fatal Error");
    });

    connect(ui->batteryTimerExpiredButton, &QPushButton::clicked, mpDemoStateMachine, &DemoStateMachine::onBatteryTimerExpiredEvent);
    connect(ui->buttonPressButton, &QPushButton::clicked, mpDemoStateMachine, &DemoStateMachine::onButtonPressEvent);
    connect(ui->mailSensorMsg, &QPushButton::clicked, mpDemoStateMachine, &DemoStateMachine::onMailSensorMsgEvent);
    connect(ui->radioFatalErrorButton, &QPushButton::clicked, mpDemoStateMachine, &DemoStateMachine::onRadioFatalErrorEvent);

    connect(mpDemoStateMachine, &DemoStateMachine::enteredCheckBatteryState, [=](){
        AppendTextToInfoDisplay("Enter: Display Check Battery State");
    });
    connect(mpDemoStateMachine, &DemoStateMachine::exitedCheckBatteryState, [=](){
        AppendTextToInfoDisplay("Exit: Display Check Battery State");
    });
    connect(mpDemoStateMachine, &DemoStateMachine::enteredNormalOperationsState, [=](){
        AppendTextToInfoDisplay("Enter: Normal Operations State");
    });
    connect(mpDemoStateMachine, &DemoStateMachine::exitedNormalOperationsState, [=](){
        AppendTextToInfoDisplay("Exit: Normal Operations State");
    });
    connect(mpDemoStateMachine, &DemoStateMachine::enteredIdleState, [=](){
        AppendTextToInfoDisplay("Enter: Idle State");
    });
    connect(mpDemoStateMachine, &DemoStateMachine::exitedIdleState, [=](){
        AppendTextToInfoDisplay("Exit: Idle State");
    });
    connect(mpDemoStateMachine, &DemoStateMachine::enteredDisplayMailReceivedState, [=](){
        AppendTextToInfoDisplay("Enter: Display Mail Received State");
    });
    connect(mpDemoStateMachine, &DemoStateMachine::exitedDisplayMailReceivedState, [=](){
        AppendTextToInfoDisplay("Exit: Display Mail Received State");
    });
    connect(mpDemoStateMachine, &DemoStateMachine::enteredFatalErrorState, [=](){
        AppendTextToInfoDisplay("Enter: Display Radio Fatal Error State");
    });
    connect(mpDemoStateMachine, &DemoStateMachine::exitedFatalErrorState, [=](){
        AppendTextToInfoDisplay("Exit: Display Radio Fatal Error State");
    });

    connect(mpDemoStateMachine, &DemoStateMachine::enteredCheckBatteryState,
            ui->visualStateMachineWidget, &DisplayDemoStateMachineImageWidget::ShowBatteryState);
    connect(mpDemoStateMachine, &DemoStateMachine::enteredNormalOperationsState,
            ui->visualStateMachineWidget, &DisplayDemoStateMachineImageWidget::ShowNormalState);
    connect(mpDemoStateMachine, &DemoStateMachine::enteredDisplayMailReceivedState,
            ui->visualStateMachineWidget, &DisplayDemoStateMachineImageWidget::ShowMailState);
    connect(mpDemoStateMachine, &DemoStateMachine::enteredFatalErrorState,
            ui->visualStateMachineWidget, &DisplayDemoStateMachineImageWidget::ShowFatalState);
    connect(mpDemoStateMachine, &DemoStateMachine::enteredIdleState,
            ui->visualStateMachineWidget, &DisplayDemoStateMachineImageWidget::ShowIdleState);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AppendTextToInfoDisplay(QString text)
{
    ui->plainTextEdit->appendPlainText(text);
    ui->plainTextEdit->verticalScrollBar()->setValue(ui->plainTextEdit->verticalScrollBar()->maximum());
}

void MainWindow::on_startStatemachineButton_clicked()
{
    //begin the statemachine
    mpDemoStateMachine->Start();
}
