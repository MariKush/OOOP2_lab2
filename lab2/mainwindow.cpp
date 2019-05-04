#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "naturalNumberAlgorithms/naturalui.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Masha_BTN_clicked()
{
    NaturalUI * natural=new NaturalUI;
    natural->show();
    this->close();
}
