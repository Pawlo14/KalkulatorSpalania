#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

#include <iostream>
#include <QFile>
#include <QApplication>
#include <QMessageBox>
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


void MainWindow::on_Oblicz_clicked() //kalkulator tab1
{
    long double b = ui->dystans->value();
    long double a = ui->paliwo->value();
//auto spalanie = std::to_string((a/b)*100);
    if(b!=0){
    ui->wynik->setValue((a/b)*100);
}
    else {
        ui->wynik->setValue(0);
}
    //QAbstractSpinBox::NoButtons; //usuwanie przycisków góra/dół w spinboxie w wyniku
}

void MainWindow::on_Zapisz_clicked() //zapis tab2
{

    long double bb = ui->dystans_2->value();
    long double aa = ui->paliwo_2->value();
//auto spalanie = std::to_string((a/b)*100);
    QString spalanie_2 = QString::number((aa/bb)*100,'f',2);
    if(bb!=0){
    ui->wynik_2->setValue((aa/bb)*100);
}
    else {
        ui->wynik_2->setValue(0);
}
    /*
    QString fname = "C:\\Users\\pawel\\Desktop\\Pliki\\Projekty\\Programowanie aplikacyjne\\KalkulatorSpalania\\test.txt";
    QFile file(fname);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream stream(&file);
        stream << "dystans: " << ui->dystans_2->value() << "\n";
        stream << "spalone paliwo: " << ui->paliwo_2->value() << "\n";
        stream << "spalanie l/100km: " << spalanie_2 << "\n";
    }
    file.close();
    */ //stary sposób zapisu

    QString fname = "C:\\Users\\pawel\\Desktop\\Pliki\\Projekty\\Programowanie aplikacyjne\\KalkulatorSpalania\\test.txt";
    QFile file(fname);

    //if(!file.open(QFile::WriteOnly | QFile::Text)) {
    //}
    if(!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this,"title","błąd otwarcia pliku");
    }
    QTextStream stream(&file);
    //out << text;
    stream << "dystans (km): " << ui->dystans_2->value() << "\n";
    stream << "spalone paliwo (l): " << ui->paliwo_2->value() << "\n";
    stream << "spalanie (l/100km): " << spalanie_2 << "\n";
    file.flush();
    file.close();
    //nowy sposób zapisu, taki sam jak odczytu

}


void MainWindow::on_wyswietl_clicked()
{

    QString fname = "C:\\Users\\pawel\\Desktop\\Pliki\\Projekty\\Programowanie aplikacyjne\\KalkulatorSpalania\\test.txt";
    QFile file(fname);

    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this,"title","błąd otwarcia pliku");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->Odczyt_pole->setPlainText(text);
    file.close();

}

