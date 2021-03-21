#include <cmath>

int s_calculation(float x, float y, float z, double S){

    S = pow((2*z + 1), x) - sqrt(abs(y - 0.5 * z)) + 3.14 + z;

    return S;
}
