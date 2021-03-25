#include <iostream>
#include <iomanip>

#include "ModulesNebesnyi.h"

using namespace std;

void dev_information()
{
    cout << " ---------------------------------------------------------------------------- " << endl;
    cout << "| Даний застосунок розроблено студентом центральноукраїнського національного |" << endl;
    cout << "| технічного університету Небесним Андрієм Вадимовичем 24 березня 2021 року. |" << endl;
    cout << " ---------------------------©ALL_RIGHTS_ARE_RESERVED-------------------------" << endl;
}

int bool_operation(char a, char b)
{
    cout << "Результат виконання логічної операції a+1>b  ---> " << boolalpha << bool(a + 1 > b) << endl;
}

float num_operations(float x, float y, float z, float S)
{
    cout << fixed << setprecision(2) << "x = " << x << "->" << hexfloat << x << endl;
	cout << fixed << setprecision(2) << "y = " << y << "->" << hexfloat << y << endl;
	cout << fixed << setprecision(2) << "z = " << z << "->" << hexfloat << z << endl;

	S = s_calculation(x, y, z);
	cout << fixed << setprecision(2) << "S = " << S << endl;

	getchar();
}

int main()
{
    system("chcp 1251 & cls");

    char a, b;
    float x = 0;
    float y = 0;
    float z = 0;
    float S = 0;

    dev_information();
    cout << " ---------------------------------------------------------------------------- " << endl;
    cout << "Завдання даної програми - провести деякі логічні та арефметичні операції." << endl;
    cout << "Користувач вводить два символи та три раціональні числа. Над символами " << endl;
    cout << "проводиться логічна операція a+1>b, результатом якої є істина чи хиба." << endl;
    cout << "Раціональні числа переводяться в шістнадцятирічну систему числення," << endl;
    cout << "також виконується арифметичний вираз :" << endl;
    cout << "S = (2*z - 1)^x - v(|y - 0.5 * z|) + z + п ." << endl;
    cout << " ---------------------------------------------------------------------------- " << endl;

    cout << "Введіть символ №а" << endl;
    cin >> a;
    cout << "Введіть символ №b" << endl;
    cin >> b;
    bool_operation(a, b);

    cout << " ---------------------------------------------------------------------------- " << endl;
    cout << "Введіть х: ";
    cin >> x;
    cout << "Введіть y: ";
    cin >> y;
    cout << "Введіть z: ";
    cin >> z;
    num_operations(x, y, z, S);

    getchar();

    return 0;
}
