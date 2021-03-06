#ifndef NATURALALGORITHMS_H
#define NATURALALGORITHMS_H

/*
    K-28
    naturalalgorithms.h
    Purpose: idescription of class NaturalAlgorithms functions
    (for algorithms by natural numbers (patern Singleton))
    @author Mariia Kushnirenko
    @version 10/05/19
*/

#include <QObject>
#include <QPair>

#include <gtest/gtest.h>


class NaturalAlgorithms : public QObject
{
    Q_OBJECT
public:
    static NaturalAlgorithms* getInstance() {
        if(_instance == Q_NULLPTR){
            _instance = new NaturalAlgorithms;
         }
         return _instance;
        }
    QVector<int> Eratosfen(int N) const;
    QVector<int> Sundaram(int N) const;
    QVector<QPair<int, int>> simple_factors(int N) const;
    QPair<QPair<int,int>, QVector<QPair<int,int>>> nsk_nsd(int i, int j) const;
    QVector<QString> Copercard(int i);

signals:

public slots:

private:
    explicit NaturalAlgorithms(QObject *parent = nullptr);
    NaturalAlgorithms( const NaturalAlgorithms& );
    NaturalAlgorithms& operator=( NaturalAlgorithms& );
    static NaturalAlgorithms* _instance;

};
#endif // NATURALALGORITHMS_H
