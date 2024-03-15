#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <cmath>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    float a = ui->spinBox->value();
    float b = ui->spinBox_2->value();
    float c = ui->spinBox_3->value();

    QString error1 = "podaj wlasciwe dane boku A kolezko";
    QString error2 = "podaj wlasciwe dane boku B kolezko";
    QString error3 = "podaj wlasciwe dane boku C kolezko";

    if(a>b+c){
        QMessageBox msg(this);
        msg.setText(error1);
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setWindowTitle("ojej");
        msg.exec();
        ui->spinBox->clear();
    }
    if(b>a+c){
        QMessageBox msg(this);
        msg.setText(error2);
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setWindowTitle("ojej");
        msg.exec();
        ui->spinBox_2->clear();
    }
    if(c>b+a){
        QMessageBox msg(this);
        msg.setText(error3);
        msg.setStandardButtons(QMessageBox::Ok);
        msg.setWindowTitle("ojej");
        msg.exec();
        ui->spinBox_3->clear();
    }
    float p = (a+b+c)/2;
    float s = p*(p-a)*(p-b)*(p-c);
    float heronxd = sqrt(s);

    ui->wynik->setText(QString::number(heronxd));
}

