#ifndef NATURALUI_H
#define NATURALUI_H

#include <QDialog>
#include <QSpinBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QTableWidget>
#include "naturalalgorithms.h"

namespace Ui {
class NaturalUI;
}

class NaturalUI : public QDialog
{
    Q_OBJECT

public:
    explicit NaturalUI(QWidget *parent = nullptr);
    ~NaturalUI();

private:
    Ui::NaturalUI *ui;
    NaturalAlgorithms *algorithms;

    QSpinBox *spin1=Q_NULLPTR, *spin2=Q_NULLPTR;
    QLabel *label1=Q_NULLPTR, *label2=Q_NULLPTR, *answer_lbl1=Q_NULLPTR,*answer_lbl2=Q_NULLPTR;
    QHBoxLayout hLayout_numbers;
    QVBoxLayout number1, number2;
    QPushButton *enter=Q_NULLPTR;
    QListWidget *listWidget=Q_NULLPTR;
    QTableWidget *tableWidget=Q_NULLPTR;

    void set_NSK_NSD_ui();
    void set_Eratosfen_ui();
    void set_Sundaram_ui();
    void set_simple_factors_ui();
    void set_perfect_numbers_ui();

    void add_1_block();
    void add_2_block();
    void add_enter();
    void add_listWidget();
    void add_tableWidget();
    void add_label1_ans();
    void add_label2_ans();
    void clear_ui();
    void clear_el(QObject *);
    void add_label_in_return_listWidget();
    void add_listWidget_in_return_label();

private slots:
    void changeUI(QString);

    void calculate_NSK_NSD();
    void calculate_Eratosfen();
    void calculate_Syndaram();
    void calculate_simple_factors();
    void calculate_perfect_number();

};

#endif // NATURALUI_H
