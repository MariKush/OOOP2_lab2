#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pifagorthree.h"
#include "Progression.h"
#include <QMessageBox>
#include <QString>
#include <QVector>

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

void MainWindow::on_pushButton_3_clicked()
{
    QVector<QVector<int>> input;
    QString result;

    if (ui->lineEdit_4->text() != NULL && ui->lineEdit_5->text() != NULL){
        input = generate_pifagorthrees((ui->lineEdit_5->text()).toInt(), (ui->lineEdit_4->text()).toInt());
    } else if (ui->lineEdit_5->text() != NULL){
        input = generate_pifagorthrees((ui->lineEdit_5->text()).toInt());
    } else if (ui->lineEdit_4->text() != NULL){
        input = generate_pifagorthrees(100, (ui->lineEdit_4->text()).toInt());
    } else {
        input = generate_pifagorthrees();
    }


    for (auto i = 0; i < input.size(); i++){
        result.push_back(QString("(%1, %2, %3) ").arg(input[i][0]).arg(input[i][1]).arg(input[i][2]));
    }

    QMessageBox::about(this, "Pifagor`s threes", result);
}

void MainWindow::on_pushButton_4_clicked()
{
    QVector<QVector<int>> input;
    QString result;

    if (ui->lineEdit_4->text() != NULL && ui->lineEdit_5->text() != NULL){
        input = generate_primitive_pifagorthrees((ui->lineEdit_5->text()).toInt(), (ui->lineEdit_4->text()).toInt());
    } else if (ui->lineEdit_5->text() != NULL){
        input = generate_primitive_pifagorthrees((ui->lineEdit_5->text()).toInt());
    } else if (ui->lineEdit_4->text() != NULL){
        input = generate_primitive_pifagorthrees(100, (ui->lineEdit_4->text()).toInt());
    } else {
        input = generate_primitive_pifagorthrees();
    }


    for (auto i = 0; i < input.size(); i++){
        result.push_back(QString("(%1, %2, %3) ").arg(input[i][0]).arg(input[i][1]).arg(input[i][2]));
    }

    QMessageBox::about(this, "Pifagor`s threes", result);
}
