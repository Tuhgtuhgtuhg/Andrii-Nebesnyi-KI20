#include <cmath>
#include <iostream>
#include <wchar.h>
#include <io.h>
#include "ModulesNebesnyi.h"

using namespace std;

int bin_zero_counter(int number){
    int mask = 0b00000000000000000000000000000001;
    int d12 = 0b00000000000000000000100000000000;

    int BinOne = 0;
    int BinZero = 0;

    for(int i = 0; i <  sizeof(int) * 8; i++){
        if(!(number & mask))
            BinZero++;
        else
            BinOne++;
        mask<<=1;
    }

    if(number & (mask << 13)){
        cout << "Binary One - ";
        return BinOne;
    }else if(!(number & (mask << 13))){
        cout << "Binary Zero - ";
        return BinZero;
    }
}

float temp_calculation(float week_tem[], int size, float *Med_F, float *Med_C){
    (*Med_F) = 0;
    (*Med_C) = 0;
    for(int i = 0; i < size ; i++){
        (*Med_C) = (*Med_C) + (week_tem[i]);
    }
    (*Med_C) = (*Med_C) / 7;
    (*Med_F) = 32 + (*Med_C) * 9/5;
    (*Med_F) = int((*Med_F)*100 + 0.5)/100.0;
    (*Med_C) = int((*Med_C)*100 + 0.5)/100.0;
}

int rating_actions(int mark){
    char rating = ' ';

    if (mark >= 90 && mark <= 100) {
        rating = 'A';
        wcout << L"Excellent performance with small number of errors - ";
        return rating;
    } else if (mark >= 82 && mark <= 89) {
        rating = 'B';
        wcout << L"Above average some mistakes - ";
        return rating;
    } else if (mark >= 75 && mark <= 81) {
        rating = 'C';
        wcout << L"Overall correct fulfillment of certain significant number of errors - ";
        return rating;
    } else if (mark >= 67 && mark <= 74) {
        rating = 'D';
        wcout << L"Not bad, but with significant number of defects - ";
        return rating;
    } else if (mark >= 60 && mark <= 66) {
        rating = 'E';
        wcout << L"satisfies minimum criteria - ";
        return rating;
    } else if (mark >= 35 && mark <= 59) {
        rating = 'F';
        wcout << L"With a possibility of re-assembly - ";
        return rating;
    } else if (mark >= 0 && mark <= 34) {
        rating = 'X';
        wcout << L"With the obligatory repeated course - F";
        return rating;
    } else {
        return 0.0;
    }
}

float s_calculation(int x, int y, int z){
    float S = pow((2*z + 1), x) - sqrt(abs(y - 1/2 * z)) + 3.14 + z;
    S = int(S*100 + 0.5)/100.0; // two symbols after the coma
    return S;
}
