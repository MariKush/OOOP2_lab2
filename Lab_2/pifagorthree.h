//
//  pifagorthree.h
//  laba9
//
//  Created by Богдан on 5/11/19.
//  Copyright © 2019 Guryanova Dasha. All rights reserved.
//

#ifndef pifagorthree_h
#define pifagorthree_h
#include <vector>
#include <math.h>
#include <QVector>

using namespace std;

bool is_pifagorthree(int x, int y, int z){ //проверка, является ли тройка пифагоровой
    if (x*x + y*y == z*z){
        return true;
    } else {
        return false;
    }
}

int NOD(int a, int b) { // Наибольший Общий Делитель
    if (a == b) {
        return a;
    }
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    return NOD(a, b - a);
}

bool is_primitive_pifagorthree(int x, int y, int z){ //Проверка, является ли пифагорова тройка примитивной
    if (is_pifagorthree(x, y, z) && NOD(x, y) == 1 && NOD(x, z) == 1 && NOD(y, z) == 1){
        return true;
    } else {
        return false;
    }
}

QVector<QVector<int>> generate_pifagorthrees(int upper_limit = 100, int lower_limit = 1){ //Нахождение всех пифагоровых троек по диапазону (), по стандарту (1:100), можно задавать только верхнюю границу, можно обе
    QVector<QVector<int>> result;
    for (int x = lower_limit; x < upper_limit; x++){
        for (int y = lower_limit; y < upper_limit; y++){
            for (int z = lower_limit; z < upper_limit; z++){
                if (is_pifagorthree(x, y, z) && y>=x){
                    QVector<int> tmp;
                    tmp.push_back(x);
                    tmp.push_back(y);
                    tmp.push_back(z);
                    result.push_back(tmp);
                }
            }
        }
    }
    return result; //Возвращает вектор с векторами из 3-х значений (x, y, z)
}

QVector<QVector<int>> generate_primitive_pifagorthrees(int upper_limit = 100, int lower_limit = 1){ //Нахождение всех простых пифагоровых троек по диапазону, аналогично предыдущему
    QVector<QVector<int>> result;
    for (int m = lower_limit; m < sqrt(upper_limit); m++){
        for (int n = lower_limit; n < sqrt(upper_limit); n++){
            int x = m*m - n*n;
            int y = 2*m*n;
            int z = m*m + n*n;
            if (z <= upper_limit && x>0 && y>0 && z> 0 && NOD(x, y) == 1 && NOD(x, z) == 1 && NOD(y, z) == 1){
                QVector<int> tmp;
                tmp.push_back(x);
                tmp.push_back(y);
                tmp.push_back(z);
                result.push_back(tmp);
            }
        }
    }
    return result; //Возвращает вектор с векторами из 3-х значений (x, y, z)
}

/*void print_result(vector<vector<int>> tmp){ //Вывод результата в консоль
    for (auto i = tmp.begin(); i != tmp.end(); i++){
        cout << i->data()[0] << " " << i->data()[1] << " " << i->data()[2] << endl;
    }
}*/


#endif /* pifagorthree_h */
