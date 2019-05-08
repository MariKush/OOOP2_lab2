#ifndef NATURALALGORITHMS_H
#define NATURALALGORITHMS_H

#include <QObject>
#include <QPair>

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

signals:

public slots:

private:
    explicit NaturalAlgorithms(QObject *parent = nullptr);
    NaturalAlgorithms( const NaturalAlgorithms& );
    NaturalAlgorithms& operator=( NaturalAlgorithms& );
    static NaturalAlgorithms* _instance;
};

#endif // NATURALALGORITHMS_H
