#include <iostream>
#include "ModulesNebesnyi.h"

using namespace std;

int main()
{
    float x[10] = {1, 2, 2, 1, 1, 5, 3, 2, 4, 1};
    float y[10] = {1, 1, -1, -2, 8, 12, 1, 2, 10, 0};
    float z[10] = {1, 1, 1, 2, 2, 2, 10, 5, -1, 0};
    float S[10] = {6.14, 12.14, 12.14, 8.74, 7.31, 3126.68, 9273.14, 127.73, -0.01, 4.14};

    for(int i = 0; i < 10; i++){
        if(s_calculation(x[i], y[i], z[i]) == S[i]){
            cout << "x = " << x[i] << ", y = " << y[i] << ", z = " << z[i] << endl;
            cout << "Passed - testing result = " << S[i] << endl;
        }
        else{
            cout << "Testing result - " << s_calculation(x[i], y[i], z[i]) << endl;
            cout << "Failed - testing result != " << S[i] << endl;
        }
    }

    getchar();
    return 0;
}
