#include <cmath>
#include <iostream>

#include "ModulesNebesnyi.h"

using namespace std;

float s_calculation(int x, int y, int z){
    float S = pow((2*z + 1), x) - sqrt(abs(y - 1/2 * z)) + 3.14 + z;
    S = int(S*100 + 0.5)/100.0; // two symbols after the coma
    return S;
}
