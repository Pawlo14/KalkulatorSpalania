#include "mainwindow.h"
#include "ui_mainwindow.h"


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
    if(b!=0){
    ui->wynikk->setValue((a/b)*100);
}
    else {
        ui->wynikk->setValue(0);
}
}
