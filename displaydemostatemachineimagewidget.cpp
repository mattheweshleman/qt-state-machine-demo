#include "displaydemostatemachineimagewidget.h"
#include "ui_displaydemostatemachineimagewidget.h"

DisplayDemoStateMachineImageWidget::DisplayDemoStateMachineImageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayDemoStateMachineImageWidget)
{
    ui->setupUi(this);
}

DisplayDemoStateMachineImageWidget::~DisplayDemoStateMachineImageWidget()
{
    delete ui;
}

void DisplayDemoStateMachineImageWidget::ShowNotInitializedStatemachine()
{
    ui->label->setPixmap(QPixmap(QString::fromUtf8(":/images/statemachine_plain.png")));
}

void DisplayDemoStateMachineImageWidget::ShowNormalState()
{
    ui->label->setPixmap(QPixmap(QString::fromUtf8(":/images/statemachine_normal.png")));
}

void DisplayDemoStateMachineImageWidget::ShowIdleState()
{
    ui->label->setPixmap(QPixmap(QString::fromUtf8(":/images/statemachine_idle.png")));
}

void DisplayDemoStateMachineImageWidget::ShowMailState()
{
    ui->label->setPixmap(QPixmap(QString::fromUtf8(":/images/statemachine_mail.png")));
}

void DisplayDemoStateMachineImageWidget::ShowBatteryState()
{
    ui->label->setPixmap(QPixmap(QString::fromUtf8(":/images/statemachine_battery.png")));
}

void DisplayDemoStateMachineImageWidget::ShowFatalState()
{
    ui->label->setPixmap(QPixmap(QString::fromUtf8(":/images/statemachine_fatal.png")));
}
