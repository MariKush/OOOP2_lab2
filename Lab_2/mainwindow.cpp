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
    if (ui->lineEdit->text() != nullptr && ui->lineEdit_2->text() != nullptr && ui->lineEdit_3->text() != nullptr){
        if (is_pifagorthree(ui->lineEdit->text().toInt(), ui->lineEdit_2->text().toInt(), ui->lineEdit_3->text().toInt())){
            QMessageBox::about(this, "Pifagor`s threes", "YES, this IS pifagor`s three (" + ui->lineEdit->text() + ", " + ui->lineEdit_2->text() + ", " + ui->lineEdit_3->text() + ")");
        } else {
            QMessageBox::about(this, "Pifagor`s threes", "NO, this is NOT pifagor`s three (" + ui->lineEdit->text() + ", " + ui->lineEdit_2->text() + ", " + ui->lineEdit_3->text() + ")");
        }
    } else {
        QMessageBox::about(this, "Pifagor`s threes", "Enter numbers!");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if (ui->lineEdit->text() != nullptr && ui->lineEdit_2->text() != nullptr && ui->lineEdit_3->text() != nullptr){
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

    if (ui->lineEdit_4->text() != nullptr && ui->lineEdit_5->text() != nullptr){
        input = generate_pifagorthrees((ui->lineEdit_5->text()).toInt(), (ui->lineEdit_4->text()).toInt());
    } else if (ui->lineEdit_5->text() != nullptr){
        input = generate_pifagorthrees((ui->lineEdit_5->text()).toInt());
    } else if (ui->lineEdit_4->text() != nullptr){
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

    if (ui->lineEdit_4->text() != nullptr && ui->lineEdit_5->text() != nullptr){
        input = generate_primitive_pifagorthrees((ui->lineEdit_5->text()).toInt(), (ui->lineEdit_4->text()).toInt());
    } else if (ui->lineEdit_5->text() != nullptr){
        input = generate_primitive_pifagorthrees((ui->lineEdit_5->text()).toInt());
    } else if (ui->lineEdit_4->text() != nullptr){
        input = generate_primitive_pifagorthrees(100, (ui->lineEdit_4->text()).toInt());
    } else {
        input = generate_primitive_pifagorthrees();
    }


    for (auto i = 0; i < input.size(); i++){
        result.push_back(QString("(%1, %2, %3) ").arg(input[i][0]).arg(input[i][1]).arg(input[i][2]));
    }

    QMessageBox::about(this, "Pifagor`s threes", result);
}

void MainWindow::on_pushButton_5_clicked()
{
    QVector<int> input;
    QString result;

    if (ui->lineEdit_6->text() == nullptr){
        if (ui->lineEdit_7->text() == nullptr){
            if (ui->lineEdit_8->text() == nullptr){
                if (ui->lineEdit_9->text() == nullptr){
                    input = generate_AProgression();
                } else {
                    input = generate_AProgression(1, 1, 10, ui->lineEdit_9->text().toInt());
                }
            } else {
                if (ui->lineEdit_9->text() == nullptr){
                    input = generate_AProgression(1, 1, ui->lineEdit_8->text().toInt());
                } else {
                    input = generate_AProgression(1, 1, ui->lineEdit_8->text().toInt(), ui->lineEdit_9->text().toInt());
                }
            }
        } else {
            if (ui->lineEdit_8->text() == nullptr){
                if (ui->lineEdit_9->text() == nullptr){
                    input = generate_AProgression(1, ui->lineEdit_7->text().toInt());
                } else {
                    input = generate_AProgression(1, ui->lineEdit_7->text().toInt(), 10, ui->lineEdit_9->text().toInt());
                }
            } else {
                if (ui->lineEdit_9->text() == nullptr){
                    input = generate_AProgression(1, ui->lineEdit_7->text().toInt(), ui->lineEdit_8->text().toInt());
                } else {
                    input = generate_AProgression(1, ui->lineEdit_7->text().toInt(), ui->lineEdit_8->text().toInt(), ui->lineEdit_9->text().toInt());
                }
            }
        }
    } else {
        if (ui->lineEdit_7->text() == nullptr){
            if (ui->lineEdit_8->text() == nullptr){
                if (ui->lineEdit_9->text() == nullptr){
                    input = generate_AProgression(ui->lineEdit_6->text().toInt());
                } else {
                    input = generate_AProgression(ui->lineEdit_6->text().toInt(), 1, 10, ui->lineEdit_9->text().toInt());
                }
            } else {
                if (ui->lineEdit_9->text() == nullptr){
                    input = generate_AProgression(ui->lineEdit_6->text().toInt(), 1, ui->lineEdit_8->text().toInt());
                } else {
                    input = generate_AProgression(ui->lineEdit_6->text().toInt(), 1, ui->lineEdit_8->text().toInt(), ui->lineEdit_9->text().toInt());
                }
            }
        } else {
            if (ui->lineEdit_8->text() == nullptr){
                if (ui->lineEdit_9->text() == nullptr){
                    input = generate_AProgression(ui->lineEdit_6->text().toInt(), ui->lineEdit_7->text().toInt());
                } else {
                    input = generate_AProgression(ui->lineEdit_6->text().toInt(), ui->lineEdit_7->text().toInt(), 10, ui->lineEdit_9->text().toInt());
                }
            } else {
                if (ui->lineEdit_9->text() == nullptr){
                    input = generate_AProgression(ui->lineEdit_6->text().toInt(), ui->lineEdit_7->text().toInt(), ui->lineEdit_8->text().toInt());
                } else {
                    input = generate_AProgression(ui->lineEdit_6->text().toInt(), ui->lineEdit_7->text().toInt(), ui->lineEdit_8->text().toInt(), ui->lineEdit_9->text().toInt());
                }
            }
        }
    }

    for (auto i = 0; i < input.size(); i++){
        result.push_back(QString("%1 ").arg(input[i]));
    }

    QMessageBox::about(this, "Progressions", result);
}

void MainWindow::on_pushButton_6_clicked()
{
    QVector<int> input;
    QString result;

    if (ui->lineEdit_6->text() == nullptr){
        if (ui->lineEdit_7->text() == nullptr){
            if (ui->lineEdit_8->text() == nullptr){
                if (ui->lineEdit_9->text() == nullptr){
                    input = generate_GProgression();
                } else {
                    input = generate_GProgression(1, 2, 10, ui->lineEdit_9->text().toInt());
                }
            } else {
                if (ui->lineEdit_9->text() == nullptr){
                    input = generate_GProgression(1, 2, ui->lineEdit_8->text().toInt());
                } else {
                    input = generate_GProgression(1, 2, ui->lineEdit_8->text().toInt(), ui->lineEdit_9->text().toInt());
                }
            }
        } else {
            if (ui->lineEdit_8->text() == nullptr){
                if (ui->lineEdit_9->text() == nullptr){
                    input = generate_GProgression(1, ui->lineEdit_7->text().toInt());
                } else {
                    input = generate_GProgression(1, ui->lineEdit_7->text().toInt(), 10, ui->lineEdit_9->text().toInt());
                }
            } else {
                if (ui->lineEdit_9->text() == nullptr){
                    input = generate_GProgression(1, ui->lineEdit_7->text().toInt(), ui->lineEdit_8->text().toInt());
                } else {
                    input = generate_GProgression(1, ui->lineEdit_7->text().toInt(), ui->lineEdit_8->text().toInt(), ui->lineEdit_9->text().toInt());
                }
            }
        }
    } else {
        if (ui->lineEdit_7->text() == nullptr){
            if (ui->lineEdit_8->text() == nullptr){
                if (ui->lineEdit_9->text() == nullptr){
                    input = generate_GProgression(ui->lineEdit_6->text().toInt());
                } else {
                    input = generate_GProgression(ui->lineEdit_6->text().toInt(), 2, 10, ui->lineEdit_9->text().toInt());
                }
            } else {
                if (ui->lineEdit_9->text() == nullptr){
                    input = generate_GProgression(ui->lineEdit_6->text().toInt(), 2, ui->lineEdit_8->text().toInt());
                } else {
                    input = generate_GProgression(ui->lineEdit_6->text().toInt(), 2, ui->lineEdit_8->text().toInt(), ui->lineEdit_9->text().toInt());
                }
            }
        } else {
            if (ui->lineEdit_8->text() == nullptr){
                if (ui->lineEdit_9->text() == nullptr){
                    input = generate_GProgression(ui->lineEdit_6->text().toInt(), ui->lineEdit_7->text().toInt());
                } else {
                    input = generate_GProgression(ui->lineEdit_6->text().toInt(), ui->lineEdit_7->text().toInt(), 10, ui->lineEdit_9->text().toInt());
                }
            } else {
                if (ui->lineEdit_9->text() == nullptr){
                    input = generate_GProgression(ui->lineEdit_6->text().toInt(), ui->lineEdit_7->text().toInt(), ui->lineEdit_8->text().toInt());
                } else {
                    input = generate_GProgression(ui->lineEdit_6->text().toInt(), ui->lineEdit_7->text().toInt(), ui->lineEdit_8->text().toInt(), ui->lineEdit_9->text().toInt());
                }
            }
        }
    }

    for (auto i = 0; i < input.size(); i++){
        result.push_back(QString("%1 ").arg(input[i]));
    }

    QMessageBox::about(this, "Progressions", result);
}

void MainWindow::on_pushButton_7_clicked()
{
    int input;
    QString result;

    if (ui->lineEdit_6->text() == nullptr){
        if (ui->lineEdit_7->text() == nullptr){
            if (ui->lineEdit_8->text() == nullptr){
                    input = summ_AProgression();
            } else {
                    input = summ_AProgression(1, 1, ui->lineEdit_8->text().toInt());
            }
        } else {
            if (ui->lineEdit_8->text() == nullptr){
                    input = summ_AProgression(1, ui->lineEdit_7->text().toInt());
            } else {
                    input = summ_AProgression(1, ui->lineEdit_7->text().toInt(), ui->lineEdit_8->text().toInt());
            }
        }
    } else {
        if (ui->lineEdit_7->text() == nullptr){
            if (ui->lineEdit_8->text() == nullptr){
                    input = summ_AProgression(ui->lineEdit_6->text().toInt());
            } else {
                    input = summ_AProgression(ui->lineEdit_6->text().toInt(), 1, ui->lineEdit_8->text().toInt());
            }
        } else {
            if (ui->lineEdit_8->text() == nullptr){
                    input = summ_AProgression(ui->lineEdit_6->text().toInt(), ui->lineEdit_7->text().toInt());
            } else {
                    input = summ_AProgression(ui->lineEdit_6->text().toInt(), ui->lineEdit_7->text().toInt(), ui->lineEdit_8->text().toInt());
            }
        }
    }

    result.push_back(QString("Summ = %1 ").arg(input));

    QMessageBox::about(this, "Progressions", result);
}

void MainWindow::on_pushButton_8_clicked()
{
    int input;
    QString result;

    if (ui->lineEdit_6->text() == nullptr){
        if (ui->lineEdit_7->text() == nullptr){
            if (ui->lineEdit_8->text() == nullptr){
                    input = summ_GProgression();
            } else {
                    input = summ_GProgression(1, 2, ui->lineEdit_8->text().toInt());
            }
        } else {
            if (ui->lineEdit_8->text() == nullptr){
                    input = summ_GProgression(1, ui->lineEdit_7->text().toInt());
            } else {
                    input = summ_GProgression(1, ui->lineEdit_7->text().toInt(), ui->lineEdit_8->text().toInt());
            }
        }
    } else {
        if (ui->lineEdit_7->text() == nullptr){
            if (ui->lineEdit_8->text() == nullptr){
                    input = summ_GProgression(ui->lineEdit_6->text().toInt());
            } else {
                    input = summ_GProgression(ui->lineEdit_6->text().toInt(), 2, ui->lineEdit_8->text().toInt());
            }
        } else {
            if (ui->lineEdit_8->text() == nullptr){
                    input = summ_GProgression(ui->lineEdit_6->text().toInt(), ui->lineEdit_7->text().toInt());
            } else {
                    input = summ_GProgression(ui->lineEdit_6->text().toInt(), ui->lineEdit_7->text().toInt(), ui->lineEdit_8->text().toInt());
            }
        }
    }

    result.push_back(QString("Summ = %1 ").arg(input));

    QMessageBox::about(this, "Progressions", result);
}

QVector<int> input;

void MainWindow::on_pushButton_9_clicked()
{
    if (ui->lineEdit_add->text() != nullptr){
        QString tmp;
        for (int i = 0; i < ui->lineEdit_add->text().size(); i++){
            if (ui->lineEdit_add->text().at(i) != " "){
                tmp.push_back(ui->lineEdit_add->text().at(i));
            } else if (ui->lineEdit_add->text().at(i-1) != " "){
                input.push_back(tmp.toInt());
                ui->label_11->setText(ui->label_11->text() + tmp + " ");
                tmp.clear();
            }
        }
        input.push_back(tmp.toInt());
        ui->label_11->setText(ui->label_11->text() + tmp + " ");
        tmp.clear();
        ui->lineEdit_add->setText("");
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    if (is_AProgression(input)){
        QMessageBox::about(this, "Progressions", "Yes, it IS arithmetic progression");
    } else {
        QMessageBox::about(this, "Progressions", "No, it IS NOT arithmetic progression");
    }
    input.clear();
    ui->label_11->setText("");
}

void MainWindow::on_pushButton_11_clicked()
{
    if (is_GProgression(input)){
        QMessageBox::about(this, "Progressions", "Yes, it IS geometric progression");
    } else {
        QMessageBox::about(this, "Progressions", "No, it IS NOT geometric progression");
    }
    input.clear();
    ui->label_11->setText("");
}
