#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pifagorthree.h"
#include "Progression.h"
#include <QMessageBox>

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

void MainWindow::on_pushButton_clicked()
{
    if (ui->lineEdit->text() != NULL && ui->lineEdit_2->text() != NULL && ui->lineEdit_3->text() != NULL){
        if (is_pifagorthree(ui->lineEdit->text().toInt(), ui->lineEdit_2->text().toInt(), ui->lineEdit_3->text().toInt())){
            QMessageBox::about(this, "Pifagor`s threes", "This IS pifagor`s three (" + ui->lineEdit->text() + ", " + ui->lineEdit_2->text() + ", " + ui->lineEdit_3->text() + ")");
        } else {
            QMessageBox::about(this, "Pifagor`s threes", "This is NOT pifagor`s three (" + ui->lineEdit->text() + ", " + ui->lineEdit_2->text() + ", " + ui->lineEdit_3->text() + ")");
        }
    } else {
        QMessageBox::about(this, "Pifagor`s threes", "Enter numbers!");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if (ui->lineEdit->text() != NULL && ui->lineEdit_2->text() != NULL && ui->lineEdit_3->text() != NULL){
        if (is_primitive_pifagorthree(ui->lineEdit->text().toInt(), ui->lineEdit_2->text().toInt(), ui->lineEdit_3->text().toInt())){
            QMessageBox::about(this, "Pifagor`s threes", "This IS SIMPLE pifagor`s three (" + ui->lineEdit->text() + ", " + ui->lineEdit_2->text() + ", " + ui->lineEdit_3->text() + ")");
        } else {
            QMessageBox::about(this, "Pifagor`s threes", "This is NOT SIMPLE pifagor`s three (" + ui->lineEdit->text() + ", " + ui->lineEdit_2->text() + ", " + ui->lineEdit_3->text() + ")");
        }
    } else {
        QMessageBox::about(this, "Pifagor`s threes", "Enter numbers!");
    }
}
