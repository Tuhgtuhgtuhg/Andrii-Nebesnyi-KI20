#include <iostream>

#include "ModulesNebesnyi.h"

using namespace std;

int main()
{
    int number[10] = {1, 10, 123, 567, 4794, 5000, 7777, 7865, 1000000, 17948360};
    int bit_result[10] = {0, 2, 1, 4, 6, 8, 6, 4, 13, 13};

    int mark[10] = {100, 86, 75, 67, 61, 36, 30, 19, 62, 91};
    char rating[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'X', 'X', 'E', 'A'};

    float temp[10][7] =
    {
        {1, 4, 1, 5, 7, 5, 6},
        {13, 10, 11, 9, 7, 5, 6},
        {1, 4, 5, 6, 7, -11, -13},
        {22, 11, 23, 30, 31, 29, 26},
        {1, 4, 1, 5, 0, -1, -2},
        {1, 4, 6, 5, 8, 5, 10},
        {1, 4, 6, 6, 7, 6, 6},
        {-21, -20, -10, -12, -11, -13, -11},
        {1, 4, 1, 5, 0, -1, 0},
        {1, 12, 1, 2, 3, 14, 16}
    };

    float med_f[10] = {39.46, 47.69, 31.74, 76.23, 34.06, 42.03, 41.26, 6.80, 34.57, 44.60};
    float med_c[10] = {4.14, 8.71, -0.13, 24.57, 1.14, 5.57, 5.14, -13.99, 1.43, 7.00};
    float Med_C = 0;
    float Med_F = 0;
    cout << "UnitTest 9.3" << endl;

    for(int i = 0; i < 10; i++){
        if(bin_zero_counter(number[i]) == bit_result[i]){
            cout << bit_result[i] << " - Passed" << endl;
        } else {
            cout << bit_result[i] << " - Failed" << endl;
        }
    }

    cout << " ===================================================== " << endl;
    cout << "UnitTest 9.1" << endl;
    for(int i = 0; i < 10; i++){
        if(rating_actions(mark[i]) == rating[i]){
            cout << rating[i] << " - Passed" << endl;
        } else {
            cout << rating[i] << " - Failed" << endl;
        }
    }

    cout << " ===================================================== " << endl;
    cout << "UnitTest 9.2" << endl;

    float temp_line[7];

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 7; k++)
                temp_line[k] = temp[i][k];
            temp_calculation(temp_line, 7, &Med_F, &Med_C);
            if(med_f[j] == Med_F){
                if(med_c[j] == Med_C){
                    cout << "Med_F = " << Med_F << " , Med_C = " << Med_C << " - Passed" << endl;
                }
                else{
                    cout << "Med_F = " << Med_F << " , Med_C = " << Med_C << " - Failed" << endl;
                }
            }
        }
    }


    getchar();

    return 0;
}
