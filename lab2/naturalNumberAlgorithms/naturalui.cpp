/*
    K-28
    naturalal.cpp
    Purpose: implementation of class NaturalUI functions
    (for user interface for algorithms by natural numbers)
    @author Mariia Kushnirenko
    @version 10/05/19
*/


#include "naturalui.h"
#include "ui_naturalui.h"
#include "mainwindow.h"
#include <QDebug>
#include <QVector>
#include <QSpinBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTableWidgetItem>
#include <QCloseEvent>


/*
    Designer class NaturalUI
    @param QWidget *parent
    @return -
*/
NaturalUI::NaturalUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NaturalUI)
{
    ui->setupUi(this);
    algorithms=NaturalAlgorithms::getInstance();

    hLayout_numbers.addLayout(&number1);
    hLayout_numbers.addLayout(&number2);

    ui->verticalLayout->addLayout(&hLayout_numbers);

    if (!open_old())
        changeUI(ui->algorithms_ComboBox->currentText());

    connect(ui->algorithms_ComboBox, SIGNAL(currentIndexChanged(QString)),this, SLOT(changeUI(QString)));
}


/*
    To open a program with data from a previous session
    @param -
    @return bool true - if all success
*/
bool NaturalUI::open_old()
{
    QFile f1("filename.txt");
    if (!f1.open(QFile::ReadOnly)) return false;
    QTextStream str(&f1);
    QString algname=str.readLine();

    ui->algorithms_ComboBox->setCurrentText(algname);
    changeUI(algname);
    int value;
    str>>value;
    spin1->setValue(value);
    if (ui->algorithms_ComboBox->currentText()=="НСК & НСД"){
        str>>value;
        spin2->setValue(value);
    }
    enter->click();
    f1.close();

    return true;
}


/*
    Destructor class NaturalUI
    @param -
    @return -
*/
NaturalUI::~NaturalUI()
{
    delete ui;
}


/*
    When closing the program, the results of the work are recorded in the file
    @param QCloseEvent *
    @return -
*/
void NaturalUI::closeEvent(QCloseEvent *)
{
    QFile f1("filename.txt");
    f1.open(QFile::WriteOnly|QFile::Truncate);
    QTextStream str(&f1);
    str<<ui->algorithms_ComboBox->currentText()<<endl;
    str<<spin1->value();
    if (ui->algorithms_ComboBox->currentText()=="НСК & НСД"){
        str<<' '<<spin2->value();
    }
    f1.close();

    MainWindow *main=new MainWindow();
    main->show();
}


/*
    Change the user interface, depending on which algorithm we work with
    @param QString algorithmName
    @return -
*/
void NaturalUI::changeUI(QString algorithmName)
{
    clear_ui();
    if (algorithmName=="НСК & НСД")
        set_NSK_NSD_ui();
    else if (algorithmName=="Решето Ератосфена")
        set_Eratosfen_ui();
    else if (algorithmName=="Решето Сундарама")
        set_Sundaram_ui();
    else if (algorithmName=="Розклад на прості множники")
        set_Simple_factors_ui();
    else if (algorithmName=="Перетворення Коперкарда")
        set_Copercard_ui();
    else {
        ui->algorithms_ComboBox->setCurrentText("НСК & НСД");
        set_NSK_NSD_ui();
    }

    enter->click();

}


/*
    Сlearing the user interface
    @param -
    @return -
*/
void NaturalUI::clear_ui()
{
    clear_el(spin1); spin1=Q_NULLPTR;
    clear_el(spin2); spin2=Q_NULLPTR;
    clear_el(label1); label1=Q_NULLPTR;
    clear_el(label2); label2=Q_NULLPTR;
    clear_el(answer_lbl1); answer_lbl1=Q_NULLPTR;
    clear_el(answer_lbl2); answer_lbl2=Q_NULLPTR;
    clear_el(listWidget); listWidget=Q_NULLPTR;
    clear_el(tableWidget); tableWidget=Q_NULLPTR;

    if (enter!=Q_NULLPTR){ enter->disconnect(); delete enter; enter=Q_NULLPTR;}
}


/*
    Delete an item
    @param -
    @return -
*/
void NaturalUI::clear_el(QObject *el)
{
    if (Q_NULLPTR==el)return;
    el->disconnect();
    delete el;
    el=Q_NULLPTR;
}


/*
    Add answer in listWidget
    @param -
    @return -
*/
void NaturalUI::add_label_in_return_listWidget()
{
    clear_el(listWidget); listWidget=Q_NULLPTR;
    clear_el(answer_lbl1); answer_lbl1=Q_NULLPTR;
    add_label1_ans();
    answer_lbl1->setText("invalid");
}


/*
    Add listWidget
    @param -
    @return -
*/
void NaturalUI::add_listWidget_in_return_label()
{
    clear_el(listWidget); listWidget=Q_NULLPTR;
    clear_el(answer_lbl1); answer_lbl1=Q_NULLPTR;
    add_listWidget();
}


/*
    Add block for number 1
    @param -
    @return -
*/
void NaturalUI::add_1_block()
{
    spin1=new QSpinBox; spin1->setMinimum(1); spin1->setValue(21);
    label1=new QLabel("Число №1");
    number1.addWidget(label1); number1.addWidget(spin1);

}


/*
    Add block for number 2
    @param -
    @return -
*/
void NaturalUI::add_2_block()
{
    spin2=new QSpinBox; spin2->setMinimum(1); spin2->setValue(49);
    label2=new QLabel("Число №2");
    number2.addWidget(label2); number2.addWidget(spin2);
}


/*
    Add enter button
    @param -
    @return -
*/
void NaturalUI::add_enter()
{
    enter=new QPushButton("enter");
    hLayout_numbers.addWidget(enter);
}


/*
    Create new and add listWidget
    @param -
    @return -
*/
void NaturalUI::add_listWidget()
{
    clear_el(listWidget); listWidget=Q_NULLPTR;
    listWidget=new QListWidget();
    ui->verticalLayout->addWidget(listWidget);
}


/*
    Create new and add tableWidget
    @param -
    @return -
*/
void NaturalUI::add_tableWidget()
{
    clear_el(tableWidget); tableWidget=Q_NULLPTR;
    tableWidget=new QTableWidget(0,2, this);
    tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);
    ui->verticalLayout->addWidget(tableWidget);
}


/*
    Create new and add label for answer1
    @param -
    @return -
*/
void NaturalUI::add_label1_ans()
{
    clear_el(answer_lbl1); answer_lbl1=Q_NULLPTR;
    answer_lbl1=new QLabel;
    ui->verticalLayout->addWidget(answer_lbl1);
}


/*
    Create new and add label for answer2
    @param -
    @return -
*/
void NaturalUI::add_label2_ans()
{
    clear_el(answer_lbl2); answer_lbl2=Q_NULLPTR;
    answer_lbl2=new QLabel;
    ui->verticalLayout->addWidget(answer_lbl2);
}


/*
    Set UI for NSK & NSD
    @param -
    @return -
*/
void NaturalUI::set_NSK_NSD_ui()
{
    add_1_block();
    add_2_block();
    add_enter();

    connect(enter, SIGNAL(clicked()), this, SLOT(calculate_NSK_NSD()));
}


/*
    Set UI for Eratosfen
    @param -
    @return -
*/
void NaturalUI::set_Eratosfen_ui()
{
    add_1_block();label1->setText("до якого числа"); spin1->setMinimum(2);
    add_enter();


    connect(enter, SIGNAL(clicked()), this, SLOT(calculate_Eratosfen()));
}


/*
    Set UI for Sundaram
    @param -
    @return -
*/
void NaturalUI::set_Sundaram_ui()
{
    add_1_block();label1->setText("до 2*N+1");
    add_enter();

    connect(enter, SIGNAL(clicked()), this, SLOT(calculate_Syndaram()));
}


/*
    Set UI for Simple factors
    @param -
    @return -
*/
void NaturalUI::set_Simple_factors_ui()
{
     add_1_block(); spin1->setMinimum(2);
     add_enter();

     connect(enter, SIGNAL(clicked()), this, SLOT(calculate_Simple_factors()));
}


/*
    Set UI for Copercard
    @param -
    @return -
*/
void NaturalUI::set_Copercard_ui()
{
    add_1_block();label1->setText("число");spin1->setMinimum(1000); spin1->setMaximum(9998);
    add_enter();


    connect(enter, SIGNAL(clicked()), this, SLOT(calculate_Copercard()));
}

//-----------realization--------------

void NaturalUI::calculate_NSK_NSD()
{
    add_tableWidget(); tableWidget->setHorizontalHeaderLabels(QStringList{"a","b"});
    add_label1_ans();
    add_label2_ans();

    QPair<QPair<int,int>, QVector<QPair<int,int>>> ns=algorithms->nsk_nsd(spin1->value(), spin2->value());
    int size=ns.second.size();
    tableWidget->setRowCount(size);

    for (int i=0;i<size;i++){
        tableWidget->setItem(i,0, new QTableWidgetItem(QString::number(ns.second[i].first)));
        tableWidget->setItem(i,1, new QTableWidgetItem(QString::number(ns.second[i].second)));
    }

    answer_lbl1->setText("NSD: "+QString::number(ns.first.first));
    answer_lbl2->setText("NSK: "+QString::number(ns.first.second));
}

void NaturalUI::calculate_Eratosfen()
{
    add_listWidget_in_return_label();
    QVector<int> arr=algorithms->Eratosfen(spin1->value());

    int size=arr.size();
    for (int i=0;i<size;i++)
        listWidget->addItem(QString::number(arr[i]));
    if (size==0)
        add_label_in_return_listWidget();
}

void NaturalUI::calculate_Syndaram()
{
    add_listWidget_in_return_label();
    QVector<int> arr=algorithms->Sundaram(spin1->value());

    int size=arr.size();
    for (int i=0;i<size;i++)
        listWidget->addItem(QString::number(arr[i]));
    if (size==0)
        add_label_in_return_listWidget();
}

void NaturalUI::calculate_Simple_factors()
{
    add_tableWidget();

    QVector<QPair<int,int>> arr=algorithms->simple_factors(spin1->value());

    int size=arr.size();

    tableWidget->setRowCount(size);


    for (int i=0;i<size;i++){
        tableWidget->setItem(i,0, new QTableWidgetItem(QString::number(arr[i].first)));
        tableWidget->setItem(i,1, new QTableWidgetItem(QString::number(arr[i].second)));
    }
    if (size==0)
    {
        qDebug()<<"it is buug";
    }

}

void NaturalUI::calculate_Copercard()
{
    QString number=QString::number(spin1->value());
    if (number.size()!=4||(number[0]==number[1]&&number[1]==number[2]&&number[2]==number[3])){
        add_label_in_return_listWidget();
        answer_lbl1->setText("однаокві цифри у числі");
        return;
    }
    add_listWidget_in_return_label();
    QVector<QString> arr=algorithms->Copercard(spin1->value());

    int size=arr.size();
    for (int i=0;i<size;i++)
        listWidget->addItem(arr[i]);
    if (size==0)
        add_label_in_return_listWidget();
}
