#include "naturalui.h"
#include "ui_naturalui.h"
#include <QDebug>
#include <QSpinBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
NaturalUI::NaturalUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NaturalUI)
{
    ui->setupUi(this);
    connect(ui->algorithms_ComboBox, SIGNAL(currentIndexChanged(QString)),this, SLOT(changeUI(QString)));
}

NaturalUI::~NaturalUI()
{
    delete ui;
}


void NaturalUI::changeUI(QString algorithmName)
{
    clear_ui();
    if(algorithmName=="Найменший спільний дільник")
        set_NSD_ui();
    if (algorithmName=="Найбільшe спільне кратне")
        set_NSK_ui();
    if (algorithmName=="Решето ератосфена")
        set_Eratosfen_ui();

}


void NaturalUI::clear_ui()
{
    clear_el(spin1); spin1=Q_NULLPTR;
    clear_el(spin2); spin2=Q_NULLPTR;
    clear_el(label1); label1=Q_NULLPTR;
    clear_el(label2); label2=Q_NULLPTR;
    clear_el(answer_lbl); answer_lbl=Q_NULLPTR;

    if (enter!=Q_NULLPTR){ enter->disconnect(); delete enter; enter=Q_NULLPTR;}
}

void NaturalUI::clear_el(QObject *el)
{
    el->disconnect();
    if (Q_NULLPTR==el)return;
    delete el;
    el=Q_NULLPTR;
}

void NaturalUI::set_NSD_ui()
{
    spin1=new QSpinBox; spin1->setMinimum(1); spin1->setValue(21);
    spin2=new QSpinBox; spin2->setMinimum(1); spin2->setValue(49);

    label1=new QLabel("Число №1");
    label2=new QLabel("Число №2");
    number1.addWidget(label1); number1.addWidget(spin1);
    number2.addWidget(label2); number2.addWidget(spin2);
    enter=new QPushButton("enter");



    hLayout_numbers.addLayout(&number1);hLayout_numbers.addLayout(&number2);
    hLayout_numbers.addWidget(enter);
    ui->verticalLayout->addLayout(&hLayout_numbers);


    connect(enter, SIGNAL(clicked()), this, SLOT(calculate_NSD()));
    calculate_NSD();
}

void NaturalUI::set_NSK_ui()
{
    spin1=new QSpinBox; spin1->setMinimum(1); spin1->setValue(21);
    spin2=new QSpinBox; spin2->setMinimum(1); spin2->setValue(49);

    label1=new QLabel("Число №1");
    label2=new QLabel("Число №2");
    number1.addWidget(label1); number1.addWidget(spin1);
    number2.addWidget(label2); number2.addWidget(spin2);
    enter=new QPushButton("enter");



    hLayout_numbers.addLayout(&number1);hLayout_numbers.addLayout(&number2);
    hLayout_numbers.addWidget(enter);
    ui->verticalLayout->addLayout(&hLayout_numbers);

    connect(enter, SIGNAL(clicked()), this, SLOT(calculate_NSK()));
    calculate_NSK();
}

void NaturalUI::set_Eratosfen_ui()
{
    spin1=new QSpinBox; spin1->setMinimum(1); spin1->setValue(21);
    label1=new QLabel("до якого числа");
    number1.addWidget(label1); number1.addWidget(spin1);

    hLayout_numbers.addLayout(&number1);
    enter=new QPushButton("enter");hLayout_numbers.addWidget(enter);
    ui->verticalLayout->addLayout(&hLayout_numbers);


    connect(enter, SIGNAL(clicked()), this, SLOT(calculate_Eratosfen()));
    calculate_Eratosfen();
}


void NaturalUI::calculate_NSD()
{
    qDebug()<<spin1->value()<<spin2->value();

    //i get int
    clear_el(answer_lbl); answer_lbl=Q_NULLPTR;
    answer_lbl=new QLabel("Найменший спільний дільник: "+QString::number(1));
    ui->verticalLayout->addWidget(answer_lbl);
}

void NaturalUI::calculate_NSK()
{
    qDebug()<<spin1->value()<<spin2->value();

    //i get int
    clear_el(answer_lbl); answer_lbl=Q_NULLPTR;
    answer_lbl=new QLabel("Найбільше спільне кратне: "+QString::number(1));
    ui->verticalLayout->addWidget(answer_lbl);
}

void NaturalUI::calculate_Eratosfen()
{
    qDebug()<<spin1->value();
    //todo smth
}
