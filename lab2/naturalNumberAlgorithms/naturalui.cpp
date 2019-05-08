#include "naturalui.h"
#include "ui_naturalui.h"
#include <QDebug>
#include <QVector>
#include <QSpinBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
NaturalUI::NaturalUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NaturalUI)
{
    ui->setupUi(this);
    algorithms=NaturalAlgorithms::getInstance();
    connect(ui->algorithms_ComboBox, SIGNAL(currentIndexChanged(QString)),this, SLOT(changeUI(QString)));

    hLayout_numbers.addLayout(&number1);
    hLayout_numbers.addLayout(&number2);

    ui->verticalLayout->addLayout(&hLayout_numbers);
    changeUI(ui->algorithms_ComboBox->currentText());
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
    if (algorithmName=="Решето Ератосфена")
        set_Eratosfen_ui();
    if (algorithmName=="Решето Сундарама")
        set_Sundaram_ui();
    if (algorithmName=="Розклад на прості множники")
        set_simple_factors_ui();
    if (algorithmName=="Знаходження досконалих чисел")
        set_perfect_numbers_ui();


    enter->click();

}


void NaturalUI::clear_ui()
{
    clear_el(spin1); spin1=Q_NULLPTR;
    clear_el(spin2); spin2=Q_NULLPTR;
    clear_el(label1); label1=Q_NULLPTR;
    clear_el(label2); label2=Q_NULLPTR;
    clear_el(answer_lbl); answer_lbl=Q_NULLPTR;
    clear_el(listWidget); listWidget=Q_NULLPTR;
    clear_el(tableWidget); tableWidget=Q_NULLPTR;

    if (enter!=Q_NULLPTR){ enter->disconnect(); delete enter; enter=Q_NULLPTR;}
}

void NaturalUI::clear_el(QObject *el)
{
    if (Q_NULLPTR==el)return;
    el->disconnect();
    delete el;
    el=Q_NULLPTR;
}

void NaturalUI::add_label_in_return_listWidget()
{
    clear_el(listWidget); listWidget=Q_NULLPTR;
    clear_el(answer_lbl); answer_lbl=Q_NULLPTR;
    add_label_ans();
    answer_lbl->setText("invalid");

}

void NaturalUI::add_listWidget_in_return_label()
{
    clear_el(listWidget); listWidget=Q_NULLPTR;
    clear_el(answer_lbl); answer_lbl=Q_NULLPTR;
    add_listWidget();
}


void NaturalUI::add_1_block()
{
    spin1=new QSpinBox; spin1->setMinimum(1); spin1->setValue(21);
    label1=new QLabel("Число №1");
    number1.addWidget(label1); number1.addWidget(spin1);

}

void NaturalUI::add_2_block()
{
    spin2=new QSpinBox; spin2->setMinimum(1); spin2->setValue(49);
    label2=new QLabel("Число №2");
    number2.addWidget(label2); number2.addWidget(spin2);
}

void NaturalUI::add_enter()
{
    enter=new QPushButton("enter");
    hLayout_numbers.addWidget(enter);
}

void NaturalUI::add_listWidget()
{
    clear_el(listWidget); listWidget=Q_NULLPTR;
    listWidget=new QListWidget();
    ui->verticalLayout->addWidget(listWidget);
}

void NaturalUI::add_tableWidget()
{
    clear_el(tableWidget); tableWidget=Q_NULLPTR;
    tableWidget=new QTableWidget(0,2);
    ui->verticalLayout->addWidget(tableWidget);
}

void NaturalUI::add_label_ans()
{
    clear_el(answer_lbl); answer_lbl=Q_NULLPTR;
    answer_lbl=new QLabel;
    ui->verticalLayout->addWidget(answer_lbl);
}



void NaturalUI::set_NSD_ui()
{
    add_1_block();
    add_2_block();
    add_enter();
    add_label_ans();
    //ui->verticalLayout->addLayout(&hLayout_numbers);


    connect(enter, SIGNAL(clicked()), this, SLOT(calculate_NSD()));
}

void NaturalUI::set_NSK_ui()
{
    add_1_block();
    add_2_block();
    add_enter();
    add_label_ans();
    //ui->verticalLayout->addLayout(&hLayout_numbers);

    connect(enter, SIGNAL(clicked()), this, SLOT(calculate_NSK()));
}

void NaturalUI::set_Eratosfen_ui()
{
    add_1_block();label1->setText("до якого числа крч");
    add_enter();
    add_listWidget();
    //ui->verticalLayout->addLayout(&hLayout_numbers);


    connect(enter, SIGNAL(clicked()), this, SLOT(calculate_Eratosfen()));
}

void NaturalUI::set_Sundaram_ui()
{
    add_1_block();label1->setText("від якого числа крч");
    add_2_block();label2->setText("до якого числа крч");
    add_enter();
    add_listWidget();

    connect(enter, SIGNAL(clicked()), this, SLOT(calculate_Syndaram()));
}

void NaturalUI::set_simple_factors_ui()
{
     add_1_block(); spin1->setMinimum(2);
     add_enter();

     connect(enter, SIGNAL(clicked()), this, SLOT(calculate_simple_factors()));
}

void NaturalUI::set_perfect_numbers_ui()
{
    add_1_block();label1->setText("від якого числа крч");
    add_2_block();label2->setText("до якого числа крч");
    add_enter();
    add_listWidget();


    connect(enter, SIGNAL(clicked()), this, SLOT(calculate_perfect_number()));
}

void NaturalUI::calculate_NSD()
{
    qDebug()<<spin1->value()<<spin2->value();

    //i get int

    answer_lbl->setText("Найменший спільний дільник: "+QString::number(1));
}

void NaturalUI::calculate_NSK()
{
    qDebug()<<spin1->value()<<spin2->value();

    //i get int

    answer_lbl->setText("Найбільше спільне кратне: "+QString::number(1));
}

void NaturalUI::calculate_Eratosfen()
{
    qDebug()<<spin1->value();
    add_listWidget_in_return_label();
    QVector<int> arr;//todo for

    int size=arr.size();
    for (int i=0;i<size;i++)
        listWidget->addItem(QString::number(arr[i]));
    if (size==0)
        add_label_in_return_listWidget();
}

void NaturalUI::calculate_Syndaram()
{
    qDebug()<<spin1->value()<<spin2->value();
    add_listWidget_in_return_label();
    QVector<int> arr;//todo for

    int size=arr.size();
    for (int i=0;i<size;i++)
        listWidget->addItem(QString::number(arr[i]));
    if (size==0)
        add_label_in_return_listWidget();
}

void NaturalUI::calculate_simple_factors()
{
    qDebug()<<spin1->value();
    add_tableWidget();
    QVector<QPair<int,int>> arr;//todo for

    int size=arr.size();
    tableWidget->setRowCount(size);
    for (int i=0;i<size;i++){
        tableWidget->item(i,0)->setText(QString::number(arr[i].first));
        tableWidget->item(i,1)->setText(QString::number(arr[i].second));
    }
    if (size==0)
    {
        qDebug()<<"it is buug";
    }

}

void NaturalUI::calculate_perfect_number()
{
    qDebug()<<spin1->value()<<spin2->value();
    add_listWidget_in_return_label();
    QVector<int> arr;//todo for

    int size=arr.size();
    for (int i=0;i<size;i++)
        listWidget->addItem(QString::number(arr[i]));
    if (size==0)
        add_label_in_return_listWidget();
}
