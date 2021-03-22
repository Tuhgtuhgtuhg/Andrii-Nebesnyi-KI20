#include <iostream>
#include "ModulesNebesnyi.h"

using namespace std;

int main()
{
    float x[10] = {1, 2, 2, 1, 1, 1.5, 3, 2, 4, 1};
    float y[10] = {1, 1, -1, -2, 1.8, 12, 1, 2, 10, 0};
    float z[10] = {1, 1, 1, 1.2, 2.1, 2, 10, 0.5, -1, 0};
    float S[10] = {6.14, 12.14, 12.14, 6.33, 9.10, 12.86, 9273.14, 6.23, -0.01, 4.14};

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
