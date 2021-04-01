#include <iostream>
#include <iomanip>
#include <windows.h>

#include "ModulesNebesnyi.h"

using namespace std;

void dev_information()
{
    cout << " ---------------------------------------------------------------------------- " << endl;
    cout << "| ����� ���������� ���������� ��������� ��������������������� ���i��������� |" << endl;
    cout << "| ����i����� ��i��������� �������� ����i�� ����������� 24 ������� 2021 ����. |" << endl;
    cout << " -------------------------(c)ALL_RIGHTS_ARE_RESERVED-------------------------" << endl;
}

int bool_operation(char a, char b)
{
    cout << "��������� ��������� ���i��� ������i� a+1>b  ---> " << boolalpha << bool(a + 1 > b) << endl;
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
    cout << "�������� ���� �������� - �������� ����i ���i�� �� ����������i ������i�." << endl;
    cout << "���������� ������� ��� ������� �� ��� ���i������ �����. ��� ��������� " << endl;
    cout << "����������� ���i��� �������� a+1>b, ����������� ��� � i����� �� ����." << endl;
    cout << "���i������ ����� ������������ � �i������������� ������� ��������," << endl;
    cout << "����� ���������� ������������ ����� :" << endl;
    cout << "S = (2*z - 1)^x - v(|y - 0.5 * z|) + z + 3.14 ." << endl;
    cout << " ---------------------------------------------------------------------------- " << endl;

    cout << "����i�� ������ ��" << endl;
    cin >> a;
    cout << "����i�� ������ �b" << endl;
    cin >> b;
    bool_operation(a, b);

    cout << " ---------------------------------------------------------------------------- " << endl;
    cout << "����i�� �: ";
    cin >> x;
    cout << "����i�� y: ";
    cin >> y;
    cout << "����i�� z: ";
    cin >> z;
    num_operations(x, y, z, S);

    getchar();

    return 0;
}
