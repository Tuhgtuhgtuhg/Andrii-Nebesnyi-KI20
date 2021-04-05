#include <iostream>
#include <windows.h>
#include <iomanip>
#include <clocale>
#include <wchar.h>
#include <io.h>
#include <fcntl.h>

#include "ModulesNebesnyi.h"

using namespace std;

void dev_information()
{
    wcout << L" ---------------------------------------------------------------------------- " << endl;
    wcout << L"| Даний застосунок розроблено студентом центральноукраїнського нацiонального |" << endl;
    wcout << L"| технiчного унiверситету Небесним Андрiєм Вадимовичем 24 березня 2021 року. |" << endl;
    wcout << L" ---------------------------©ALL_RIGHTS_ARE_RESERVED-------------------------" << endl;
}

int bool_operation(char a, char b)
{
    wcout << L"Результат виконання логiчної операцiї a+1>b  ---> " << boolalpha << bool(a + 1 > b) << endl;
}

float num_operations(int x, int y, int z, float S)
{
    wcout << dec << L"x = " << x << L" -> " << L"0x" << hex << uppercase << x << endl;
	wcout << dec << L"y = " << y << L" -> " << L"0x" << hex << uppercase << y << endl;
	wcout << dec << L"z = " << z << L" -> " << L"0x" << hex << uppercase << z << endl;

	S = s_calculation(x, y, z);
	wcout << dec << "S = " << S << endl;

	getchar();
}

int main()
{
    _wsetlocale(LC_ALL,L" ");
    _setmode(_fileno(stdout), _O_U8TEXT);

    char a, b;
    int x = 0;
    int y = 0;
    int z = 0;
    float S = 0;

    dev_information();
    wcout << L" ---------------------------------------------------------------------------- " << endl;
    wcout << L"Завдання даної програми - провести деякi логiчнi та арефметичнi операцiї." << endl;
    wcout << L"Користувач вводить два символи та три цiлi числа. Над символами " << endl;
    wcout << L"проводиться логiчна операцiя a+1>b, результатом якої є iстина чи хиба." << endl;
    wcout << L"Цiлi числа переводяться в шiстнадцяткову систему числення," << endl;
    wcout << L"також виконується арифметичний вираз :" << endl;
    wcout << L"S = (2*z - 1)^x - v(|y - 0.5 * z|) + z + п ." << endl;
    wcout << L" ---------------------------------------------------------------------------- " << endl;

    wcout << L"Введiть символ №а" << endl;
    cin >> a;
    wcout << L"Введiть символ №b" << endl;
    cin >> b;
    bool_operation(a, b);

    wcout << L" ---------------------------------------------------------------------------- " << endl;

    while(true)
    {
        wcout << L"Введiть х: ";
        if(!scanf("%d", &x)){
            scanf("%*[^\n]");
            wcout << L"Ви ввели символ, введіть число." << endl;
        }
        else
            break;
    }
    while(true)
    {
        wcout << L"Введiть y: ";
        if(!scanf("%d", &y)){
            scanf("%*[^\n]");
            wcout << L"Ви ввели символ, введіть число." << endl;
        }
        else
            break;
    }
        while(true)
    {
        wcout << L"Введiть z: ";
        if(!scanf("%d", &z)){
            scanf("%*[^\n]");
            wcout << L"Ви ввели символ, введіть число." << endl;
        }
        else
            break;
    }
    num_operations(x, y, z, S);

    getchar();

    return 0;
}

