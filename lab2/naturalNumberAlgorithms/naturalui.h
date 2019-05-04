#ifndef NATURALUI_H
#define NATURALUI_H

#include <QDialog>
#include <QSpinBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
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
    NaturalAlgorithms algorithms;

    QSpinBox *spin1=Q_NULLPTR, *spin2=Q_NULLPTR;
    QLabel *label1=Q_NULLPTR, *label2=Q_NULLPTR, *answer_lbl=Q_NULLPTR;
    QHBoxLayout hLayout_numbers;
    QVBoxLayout number1, number2;
    QPushButton *enter=Q_NULLPTR;

    void set_NSD_ui();
    void set_NSK_ui();
    void set_Eratosfen_ui();

    void clear_ui();
    void clear_el(QObject *);

private slots:
    void changeUI(QString);

    void calculate_NSD();
    void calculate_NSK();
    void calculate_Eratosfen();
};

#endif // NATURALUI_H
