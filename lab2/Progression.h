//
//  Progression.h
//  laba9
//
//  Created by Богдан on 5/11/19.
//  Copyright © 2019 Guryanova Dasha. All rights reserved.
//

#ifndef Progression_h
#define Progression_h
#include <vector>
#include <math.h>

using namespace std;

vector<int> generate_AProgression(int first_member = 1, int step = 1, int progression_lenght = 10, int max_member = 99999999){//Генерация арефметической прогрессии по заданным параметрам
    int a = first_member;
    vector<int> result;
    result.push_back(a);
    for (int i = 1; i < progression_lenght && abs(a) <= max_member-abs(step); i++){
        a = a + step;
        result.push_back(a);
    }
    return result;
}

vector<int> generate_GProgression(int first_member = 1, int step = 2, int progression_lenght = 10, int max_member = 99999999){//Генерация геометрической прогрессии по заданным параметрам
    int a = first_member;
    vector<int> result;
    result.push_back(a);
    for (int i = 1; i < progression_lenght && abs(a) <= max_member/abs(step); i++){
        a = a * step;
        result.push_back(a);
    }
    return result;
}

int summ_AProgression(int first_member = 1, int step = 1, int progression_lenght = 10){//Сумма арефметической прогрессии по заданным параметрам
    return ((2*first_member + step*(progression_lenght-1))*progression_lenght)/2;
}

int summ_GProgression(int first_member = 1, int step = 2, int progression_lenght = 10){//Сумма геометрической прогрессии по заданным параметрам
        return (first_member*(1-pow(step, progression_lenght)))/(1-step);
}

bool is_AProgression(vector<int> tmp){//Проверка вектора, есть ли арефметической прогрессией
    int a = tmp[1]-tmp[0];
    for (int i = 1; i < tmp.size()-1; i++){
        if (tmp[i+1]-tmp[i] != a){
            return false;
        }
    }
    return true;
}

bool is_GProgression(vector<int> tmp){//Проверка вектора, есть ли геометрической прогрессией
    double a = tmp[1]/tmp[0];
    for (int i = 1; i < tmp.size()-1; i++){
        if (tmp[i+1]/tmp[i] != a){
            return false;
        }
    }
    return true;
}

int member_AProgression(int first_member = 1, int step = 1, int N_of_member = 10){//нахождение члена арефметической прогрессии по заданным параметрам
    return first_member + step*(N_of_member - 1);
}

int member_GProgression(int first_member = 1, int step = 1, int N_of_member = 10){//нахождение члена геометрической прогрессии по заданным параметрам
    return first_member*pow(step,(N_of_member - 1));
}


#endif /* Progression_h */
