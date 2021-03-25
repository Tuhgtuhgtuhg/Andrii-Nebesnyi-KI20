#include <iostream>
#include <iomanip>

#include "ModulesNebesnyi.h"

using namespace std;

void dev_information()
{
    cout << " ---------------------------------------------------------------------------- " << endl;
    cout << "| ����� ���������� ���������� ��������� ��������������������� ������������� |" << endl;
    cout << "| ��������� ����������� �������� ����� ����������� 24 ������� 2021 ����. |" << endl;
    cout << " ---------------------------�ALL_RIGHTS_ARE_RESERVED-------------------------" << endl;
}

int bool_operation(char a, char b)
{
    cout << "��������� ��������� ������ �������� a+1>b  ---> " << boolalpha << bool(a + 1 > b) << endl;
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
    cout << "�������� ���� �������� - �������� ���� ����� �� ���������� ��������." << endl;
    cout << "���������� ������� ��� ������� �� ��� ���������� �����. ��� ��������� " << endl;
    cout << "����������� ������ �������� a+1>b, ����������� ��� � ������ �� ����." << endl;
    cout << "���������� ����� ������������ � ��������������� ������� ��������," << endl;
    cout << "����� ���������� ������������ ����� :" << endl;
    cout << "S = (2*z - 1)^x - v(|y - 0.5 * z|) + z + � ." << endl;
    cout << " ---------------------------------------------------------------------------- " << endl;

    cout << "������ ������ ��" << endl;
    cin >> a;
    cout << "������ ������ �b" << endl;
    cin >> b;
    bool_operation(a, b);

    cout << " ---------------------------------------------------------------------------- " << endl;
    cout << "������ �: ";
    cin >> x;
    cout << "������ y: ";
    cin >> y;
    cout << "������ z: ";
    cin >> z;
    num_operations(x, y, z, S);

    getchar();

    return 0;
}
