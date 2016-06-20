#ifndef DISPLAYDEMOSTATEMACHINEIMAGEWIDGET_H
#define DISPLAYDEMOSTATEMACHINEIMAGEWIDGET_H

#include <QWidget>

namespace Ui {
class DisplayDemoStateMachineImageWidget;
}

class DisplayDemoStateMachineImageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayDemoStateMachineImageWidget(QWidget *parent = 0);
    ~DisplayDemoStateMachineImageWidget();

public slots:
    void ShowNotInitializedStatemachine();
    void ShowNormalState();
    void ShowIdleState();
    void ShowMailState();
    void ShowBatteryState();
    void ShowFatalState();

private:
    Ui::DisplayDemoStateMachineImageWidget *ui;
};

#endif // DISPLAYDEMOSTATEMACHINEIMAGEWIDGET_H
