#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

#include <iostream>
#include <QFile>
#include <QApplication>
using namespace std;

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


void MainWindow::on_Oblicz_clicked()
{
    long double b = ui->dystanss->value();
    long double a = ui->paliwoo->value();
//auto spalanie = std::to_string((a/b)*100);
    QString spalanie = QString::number((a/b)*100,'f');
    if(b!=0){
    ui->wynikk->setValue((a/b)*100);
}
    else {
        ui->wynikk->setValue(0);
}
    QString fname = "C:\\Users\\pawel\\Desktop\\Pliki\\Projekty\\Programowanie aplikacyjne\\KalkulatorSpalania\\test.txt";
    QFile file(fname);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream stream(&file);
        stream << "----" << "\n" << "\n";
        stream << "km: " << ui->dystanss->value() << "\n";
        stream << "dystans: " << ui->paliwoo->value() << "\n";
        stream << "spalanie l/100km: " << spalanie << "\n";
    }
    file.close();
}
