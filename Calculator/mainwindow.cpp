#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

double firstNum;
bool enteredSecondNum = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->pushButton_plus,SIGNAL(released()),this,SLOT(on_pushButton_operator_pressed()));
    connect(ui->pushButton_minus,SIGNAL(released()),this,SLOT(on_pushButton_operator_pressed()));
    connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(on_pushButton_operator_pressed()));
    connect(ui->pushButton_divide,SIGNAL(released()),this,SLOT(on_pushButton_operator_pressed()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);

    lcdDisplay = "";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    QPushButton * button = (QPushButton*)sender();
//    double lcdDisplay;
//    QString newLcd;

    if ((ui->pushButton_plus->isChecked() || ui->pushButton_minus->isChecked() || ui->pushButton_multiply->isChecked() || ui->pushButton_divide->isChecked()) && (!enteredSecondNum))
    {
        lcdDisplay=button->text();
        enteredSecondNum = true;
    }
    else
    {
        lcdDisplay+=button->text();
        qDebug() << lcdDisplay;
    }
//    lcdDisplay = (QString::number(ui->lcdNumber->value())+button->text().toDouble());
//    newLcd = QString::number(lcdDisplay, 'g', 15);
    ui->lcdNumber->display(lcdDisplay.toDouble());

}

void MainWindow::on_pushButton_point_released()
{
//    QString currentText = (QString::number(ui->lcdNumber->value()));
//        if (!currentText.contains('.')) {
//            ui->lcdNumber->display(QString::number(ui->lcdNumber->value())+".");
//        }

    if (!lcdDisplay.contains('.'))
            {
                lcdDisplay += ".";
                ui->lcdNumber->display(lcdDisplay);
            }

}

void MainWindow::on_pushButton_operator_pressed()
{
    QPushButton * button = (QPushButton*)sender();
    firstNum = ui->lcdNumber->value();
    button->setChecked(true);
    qDebug() << firstNum;
}



void MainWindow::on_pushButton_AC_released()
{
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);

    enteredSecondNum = false;

    lcdDisplay = "";

    ui->lcdNumber->display("0");

}


void MainWindow::on_pushButton_equals_released()
{
    double lcdAnswer,secondNum;
    secondNum = ui->lcdNumber->value();
    if (ui->pushButton_plus->isChecked())
    {
        lcdAnswer = firstNum + secondNum;
        ui->lcdNumber->display(lcdAnswer);
        ui->pushButton_plus->setCheckable(false);

    }
    else if (ui->pushButton_minus->isChecked())
    {
        lcdAnswer = firstNum - secondNum;
        ui->lcdNumber->display(lcdAnswer);
        ui->pushButton_minus->setCheckable(false);

    }
    else if (ui->pushButton_multiply->isChecked())
    {
        lcdAnswer = firstNum * secondNum;
        ui->lcdNumber->display(lcdAnswer);
        ui->pushButton_multiply->setCheckable(false);

    }
    else if (ui->pushButton_divide->isChecked())
    {
        lcdAnswer = firstNum / secondNum;
        ui->lcdNumber->display(lcdAnswer);
        ui->pushButton_divide->setCheckable(false);

    }

    enteredSecondNum = false;
    qDebug() << enteredSecondNum;
}

