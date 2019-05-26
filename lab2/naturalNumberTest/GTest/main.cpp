#include <gtest/gtest.h>
#include <QApplication>
#include <QRandomGenerator>
#include <QDebug>
#include "mainwindow.h"
#include "naturalNumberAlgorithms/naturalalgorithms.h"
#include "naturalNumberAlgorithms/naturalui.h"

//---------------------tests for mainwindow--------------------------------------------------------

TEST(mainwindow, close){
    MainWindow *m = new MainWindow;
    EXPECT_TRUE(m) << "MainWindow do not create";
    EXPECT_TRUE(m->close())<< "MainWindow do not close";
}

TEST(mainwindow, natural){
    MainWindow *m=new MainWindow;
    m->on_Masha_BTN_clicked();
    EXPECT_TRUE(m->isHidden())<< "MainWindow do not hidden after on_Masha_BTN_clicked()";
    EXPECT_TRUE(m->natural)<< "MainWindow do not create natural window";
    EXPECT_TRUE(m->natural->isVisible())<< "MainWindow do not make visible natural window";
}

//---------------------tests for naturalUI--------------------------------------------------------------


TEST(naturalUI, EratosfenUI){
    NaturalUI *n = new NaturalUI;
    n->changeUI("Решето Ератосфена");
    EXPECT_TRUE(n->enter) << "enter button do not cteate";
    EXPECT_TRUE(n->spin1&&n->label1)<< "spinBox1 do not cteate or do not have label";
    EXPECT_FALSE(n->spin2||n->label2)<< "spinBox2 cteate or have label";
    EXPECT_TRUE(static_cast<bool>(n->listWidget)^static_cast<bool>(n->answer_lbl1));
    EXPECT_FALSE(n->tableWidget)<< "cteate tableWidget";
    EXPECT_FALSE(n->answer_lbl2)<< "cteate answer_lbl2";

}

TEST(naturalUI, SundaramUI){
    NaturalUI *n = new NaturalUI;
    n->changeUI("Решето Сундарама");
    EXPECT_TRUE(n->enter)<< "enter button do not cteate";
    EXPECT_TRUE(n->spin1&&n->label1)<< "spinBox1 do not cteate or do not have label";
    EXPECT_FALSE(n->spin2||n->label2)<< "spinBox2 cteate or have label";
    EXPECT_TRUE(static_cast<bool>(n->listWidget)^static_cast<bool>(n->answer_lbl1));
    EXPECT_FALSE(n->tableWidget)<< "cteate tableWidget";
    EXPECT_FALSE(n->answer_lbl2)<< "cteate answer_lbl2";
}

TEST(naturalUI, NSD_and_NSKUI){
    NaturalUI *n = new NaturalUI;
    n->changeUI("НСК & НСД");
    EXPECT_TRUE(n->enter)<< "enter button do not cteate";
    EXPECT_TRUE(n->spin1&&n->label1)<< "spinBox1 do not cteate or do not have label";
    EXPECT_TRUE(n->spin2&&n->label2)<< "spinBox2 do not cteate or do not have label";
    EXPECT_TRUE(n->answer_lbl1&&n->answer_lbl2);
    EXPECT_TRUE(n->tableWidget)<< "do not cteate tableWidget";
    EXPECT_FALSE(n->listWidget)<< "cteate listWidget";
}

TEST(naturalUI, CopercardUI){
    NaturalUI *n = new NaturalUI;
    n->changeUI("Перетворення Коперкарда");
    EXPECT_TRUE(n->enter)<< "enter button do not cteate";
    EXPECT_TRUE(n->spin1&&n->label1)<< "spinBox1 do not cteate or do not have label";
    EXPECT_FALSE(n->spin2||n->label2)<< "spinBox2 cteate or have label";
    EXPECT_TRUE(static_cast<bool>(n->listWidget)^static_cast<bool>(n->answer_lbl1));
    EXPECT_FALSE(n->tableWidget)<< "cteate tableWidget";
    EXPECT_FALSE(n->answer_lbl2)<< "cteate answer_lbl2";

}

TEST(naturalUI, Simple_factorsUI){
    NaturalUI *n = new NaturalUI;
    n->changeUI("Розклад на прості множники");
    EXPECT_TRUE(n->enter)<< "enter button do not cteate";
    EXPECT_TRUE(n->spin1&&n->label1)<< "spinBox1 do not cteate or do not have label";
    EXPECT_TRUE(n->tableWidget)<< "do not cteate tableWidget";
    EXPECT_FALSE(n->spin2||n->label2)<< "spinBox2 cteate or have label";
    EXPECT_FALSE(n->listWidget)<< "cteate tableWidget";
    EXPECT_FALSE(n->answer_lbl2)<< "cteate answer_lbl2";
}


//for check pattern Singletone
TEST( naturalAlgorithms, Singletone){
    NaturalAlgorithms *a=NaturalAlgorithms::getInstance();
    NaturalAlgorithms *b=NaturalAlgorithms::getInstance();
    NaturalAlgorithms *c=NaturalAlgorithms::getInstance();
    EXPECT_EQ(a,b);
    EXPECT_EQ(a,c);
}

//for check number for simple
bool isSimple(int N){
    int n=static_cast<int>(sqrt(N));
    for(int i = 2; i<=n;i++)
    {
        if(N%i==0) return false;
    }
    return true;
}

//---------------------tests for naturalAlgoritms--------------------------------------------------------------

TEST(naturalAlgoritms, Eratosfen){
    NaturalAlgorithms *n=NaturalAlgorithms::getInstance();
    int N=abs(qrand())+2;
    QVector<int> arr=n->Eratosfen(N);
    int size=arr.size();
    for (int i = 0; i < size; ++i) {
        EXPECT_TRUE(isSimple(arr[i]))<< "not simple number in Eratosfen";
    }

}

TEST(naturalAlgoritms, Sundaram){
    NaturalAlgorithms *n=NaturalAlgorithms::getInstance();
    int N=abs(qrand())+2;
    QVector<int> arr=n->Sundaram(N);
    int size=arr.size();
    for (int i = 0; i < size; ++i) {
        EXPECT_TRUE(isSimple(arr[i])) << "not simple number in Sundaram";
    }
}

TEST(naturalAlgoritms, NSD_and_NSK){
    NaturalAlgorithms *n=NaturalAlgorithms::getInstance();
    int a=abs(qrand())%1000+1, b=abs(qrand())%1000+1;
    QPair<QPair<int, int>, QVector<QPair<int, int>>>ns=n->nsk_nsd(a,b);

    //NSD
    EXPECT_TRUE(a%ns.first.first == 0 &&b%ns.first.first == 0);
    for(int i = ns.first.first+1; i<qMin(a,b); i++){
        EXPECT_FALSE(a%i == 0 &&b%i == 0) <<"not correct NSD";
    }

    //NSK
    EXPECT_TRUE(ns.first.second % a == 0 && ns.first.second%b == 0);
    for(int i=qMax(a,b); i<ns.first.second; i++){
        EXPECT_FALSE(i%a == 0 && i%b == 0)<<"not correct NSK";
    }
}


TEST(naturalAlgoritms, Simple_factors){
     NaturalAlgorithms *n=NaturalAlgorithms::getInstance();
     int a = abs(qrand())+2;
     QVector<QPair<int, int>> arr = n->simple_factors(a);
     int size = arr.size()-1;
     for(int i = 0; i<size; i++){
         EXPECT_EQ(arr[i].first % arr[i].second, 0);
         EXPECT_EQ(arr[i].first/arr[i].second, arr[i+1].first);
         EXPECT_TRUE(isSimple(arr[i].second));
     }
     EXPECT_EQ(arr[size].first, arr[size].second);
     EXPECT_TRUE(isSimple(arr[size].first));
}

TEST(naturalAlgoritms, Copercard){
    NaturalAlgorithms *n=NaturalAlgorithms::getInstance();
    int a = QRandomGenerator::global()->bounded(1000,9999);
    QString str=QString::number(a);
    if (str[0]==str[1]&&str[1]==str[2]&&str[2]==str[3])return;

    QVector<QString>arr=n->Copercard(a);
    EXPECT_TRUE(arr.size()<=8)<<arr.size()<<a;
    EXPECT_EQ(arr.last().right(4), "6174");

}


int main(int argc, char *argv[])
{
    srand (static_cast<unsigned int>(time(nullptr)));
    QApplication a(argc, argv);
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
