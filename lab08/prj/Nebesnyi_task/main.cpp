#include <iostream>
#include <iomanip>
#include <windows.h>

#include "ModulesNebesnyi.h"

using namespace std;

void dev_information()
{
    cout << " ---------------------------------------------------------------------------- " << endl;
    cout << "| Даний застосунок розроблено студентом центральноукраїнського нацiонального |" << endl;
    cout << "| технiчного унiверситету Небесним Андрiєм Вадимовичем 24 березня 2021 року. |" << endl;
    cout << " -------------------------(c)ALL_RIGHTS_ARE_RESERVED-------------------------" << endl;
}

int bool_operation(char a, char b)
{
    cout << "Результат виконання логiчної операцiї a+1>b  ---> " << boolalpha << bool(a + 1 > b) << endl;
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
    SetConsoleCP(866);
    SetConsoleOutputCP(866);

    char a, b;
    float x = 0;
    float y = 0;
    float z = 0;
    float S = 0;

    dev_information();
    cout << " ---------------------------------------------------------------------------- " << endl;
    cout << "Завдання даної програми - провести деякi логiчні та арефметичнi операцiї." << endl;
    cout << "Користувач вводить два символи та три рацiональні числа. Над символами " << endl;
    cout << "проводиться логiчна операція a+1>b, результатом якої є iстина чи хиба." << endl;
    cout << "Рацiональні числа переводяться в шiстнадцятирічну систему числення," << endl;
    cout << "також виконується арифметичний вираз :" << endl;
    cout << "S = (2*z - 1)^x - v(|y - 0.5 * z|) + z + 3.14 ." << endl;
    cout << " ---------------------------------------------------------------------------- " << endl;

    cout << "Введiть символ №а" << endl;
    cin >> a;
    cout << "Введiть символ №b" << endl;
    cin >> b;
    bool_operation(a, b);

    cout << " ---------------------------------------------------------------------------- " << endl;
    cout << "Введiть х: ";
    cin >> x;
    cout << "Введiть y: ";
    cin >> y;
    cout << "Введiть z: ";
    cin >> z;
    num_operations(x, y, z, S);

    getchar();

    return 0;
}
