#ifndef NATURALALGORITHMS_H
#define NATURALALGORITHMS_H

#include <QObject>

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

signals:

public slots:

private:
    explicit NaturalAlgorithms(QObject *parent = nullptr);
    NaturalAlgorithms( const NaturalAlgorithms& );
    NaturalAlgorithms& operator=( NaturalAlgorithms& );
    static NaturalAlgorithms* _instance;
};

#endif // NATURALALGORITHMS_H
