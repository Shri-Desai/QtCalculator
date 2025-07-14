#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString lcdDisplay;
    double lcdAnswer;

private slots:
    void digit_pressed();
    void on_pushButton_point_released();
    void on_pushButton_operator_pressed();
    void on_pushButton_AC_released();
    void on_pushButton_equals_released();
};
#endif // MAINWINDOW_H
