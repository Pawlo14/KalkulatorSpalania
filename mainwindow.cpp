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

    long double bb = ui->dystans_2->value(); //przejechany dystans
    long double aa = ui->paliwo_2->value(); //spalone paliwo
    //auto spalanie_2 = std::to_string((aa/bb)*100);
    QString spalanie_2 = QString::number((aa/bb)*100,'f',2);
    if(bb!=0){ //bb to jest dystans
    ui->wynik_2->setValue((aa/bb)*100);
}
    else {
        ui->wynik_2->setValue(0);
        spalanie_2="nie dozwolona operacja - dzielenie przez 0";
}
    //poprawić lokaliziację pliku (nie na sztywno)
    //QString fname = ":/save/save.txt";
    //QFile file(":/save/save.txt");
    QString fname = ("C:\\Users\\pawel\\Desktop\\Pliki\\Projekty\\Programowanie aplikacyjne\\KalkulatorSpalania\\save\\save.txt");
    //QString fname(":/save/zapis.txt");
    QFile file(fname);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QMessageBox::warning(this,"title","błąd otwarcia pliku do zapisu");
    }
    QTextStream stream(&file);
    stream << "dystans (km): " << ui->dystans_2->value() << "\n";
    stream << "spalone paliwo (l): " << ui->paliwo_2->value() << "\n";
    stream << "spalanie (l/100km): " << spalanie_2 << "\n \n";
    //file.flush(); //dopisywanie linii
    file.close();

}


void MainWindow::on_wyswietl_clicked()  //tab3 - wyswietlanie
{

    //QString fname = ":/save/save.txt";
    //QFile file(":/save/save.txt");
    QString fname = ("C:\\Users\\pawel\\Desktop\\Pliki\\Projekty\\Programowanie aplikacyjne\\KalkulatorSpalania\\save\\save.txt");
    //QString fname = ("://save//save.txt");
    QFile file(fname);

    if(!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this,"title","błąd otwarcia pliku do odczytu");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->Odczyt_pole->setPlainText(text);
    file.close();

}

