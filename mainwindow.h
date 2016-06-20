#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

class DemoStateMachine;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void AppendTextToInfoDisplay(QString text);

private slots:
    void on_startStatemachineButton_clicked();

private:
    Ui::MainWindow *ui;
    DemoStateMachine* mpDemoStateMachine;
};

#endif // MAINWINDOW_H
