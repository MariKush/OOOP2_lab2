/*
    K-28
    naturalalgorithms.cpp
    Purpose: implementation of class NaturalUI functions
    (for algorithms by natural numbers (patern Singleton))
    @author Mariia Kushnirenko
    @version 10/05/19
*/


#include "naturalalgorithms.h"
#include <QVector>
#include <QtAlgorithms>
#include <QDebug>

//for realization patern Singleton
NaturalAlgorithms* NaturalAlgorithms::_instance = Q_NULLPTR;


/*
    Designer class NaturalAlgorithms
    @param QObject *parent
    @return -
*/
NaturalAlgorithms::NaturalAlgorithms(QObject *parent) : QObject(parent)
{

}


/*
    The algorithm for calculating the smallest common multiple and largest common divisor
    @param int i, int j - two numbers
    @return QPair<int, int> - nsd and nsk;
            QVector<QPair<int, int>> - to demonstrate the steps of the Euclidean algorithm
*/
QPair<QPair<int, int>, QVector<QPair<int, int>>> NaturalAlgorithms::nsk_nsd(int i, int j) const
{
    QPair<QPair<int, int>, QVector<QPair<int, int>>> ns;
    int a=qMax(i,j), b=qMin(i,j);
        while (b) {
            ns.second.push_back(QPair<int,int>(a,b));
            a %= b;
            std::swap (a, b);
        }
        ns.second.push_back(QPair<int,int>(a,b));
    ns.first.first=a;
    ns.first.second=i*j/a;
    return ns;
}


/*
    Implementation of the algorithm of the sequence of transformations
    of the Capercard for a four-digit number
    @param int value - number
    @return QVector<QString> - the sequence of all transformations
*/
QVector<QString> NaturalAlgorithms::Copercard(int value)
{
    QVector<QString> arr;
    QString str;

    QString minStr(str), maxStr(str);
    do{
        str=QString::number(value);
        while (str.size()<4) str="0"+str;
        minStr=str;maxStr=str;
        std::sort(minStr.begin(), minStr.end());
        for (int i=0;i<4;i++)
            maxStr[i]=minStr[3-i];
        int newValue=maxStr.toInt()-minStr.toInt();

        arr.push_back("K("+str+")=" +maxStr+"-"+minStr+"="+QString::number(newValue));
        value=newValue;

    }while (maxStr!="7641"&&minStr!="1467");

    return arr;
}


/*
    Realization of the algorithm of Eratosphen - search of all prime numbers to the given one
    @param int N - number to which we will look for all prime numbers
    @return QVector<int> - vector of all primes to a given value N
*/
QVector<int> NaturalAlgorithms::Eratosfen(int N) const
{
    QVector<bool> B;
    int i, P;
    for (P=0; P<=N; P++) B.push_back(true);
    P=2;
    while (P*P<=N)
    {
        i=P*P;
        if (B[P])
            while (i<=N)
            {
                B[i]=false;
                i=i+P;
            }
        P=P+1;
     }
    QVector<int> arr;
    for (P=2; P<=N; P++)
        if (B[P]==true) arr.push_back(P);
    return arr;
}


/*
    Realization of the algorithm of Sundaram -
    simple deterministic algorithm for finding all the prime numbers up to a specified integer
    @param int N - number
    @return QVector<int> - vector of all primes to 2*N+1
*/
QVector<int> NaturalAlgorithms::Sundaram(int N) const
{
    QVector<bool> A;
    int i, j;
    for (i=0; i<=N; i++) A.push_back(true);
    i=1; j=1;
    while ((2*i*j+i+j)<=N)
    {
        while (j<=(N-i)/(2*i+1))
        {
            A[2*i*j+i+j]=false;
            j++;
         }
        i++;
        j=i;
    }
    QVector<int> arr;
    for (i=1; i<=N; i++)
        if (A[i]) arr.push_back(2*i+1);
    return arr;
}


/*
    Realization of the algorithm of the decomposition of the number into simple divisors
    @param int N - number
    @return QVector<QPair<int,int>> - vector pair (divide and divider)
            formed during the operation of the algorithm
*/
QVector<QPair<int,int>> NaturalAlgorithms::simple_factors(int N) const
{
    QVector<QPair<int,int>> arr;
    int divisor = 2;
        while (divisor*divisor <= N)
        {
            if (N%divisor == 0)
            {
                arr.push_back(QPair<int, int>(N, divisor));
                N = N / divisor;
            }
            else if (divisor == 2) divisor = 3;
            else divisor = divisor + 2;
        }
        arr.push_back(QPair<int,int>(N,N));
     return arr;
}


