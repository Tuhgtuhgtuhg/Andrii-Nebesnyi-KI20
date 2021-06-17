
#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <clocale>
#include <string>

using namespace std;

struct Car{
    // ���� ������ �������� �� ������ � ����� ���������� ������
    string nomer = " ";
    string owner = " ";
    string model_year = " ";
    string reg_date =" ";
} obj; // ������ ���������

 vector <struct Car> Reg; // ������� ������ � ��������� ��� ���������
 char filename[] = "register.txt"; // ��� �����
 string line = ""; // ��������������� ����������
 ifstream reg_in;
 ofstream reg_out;

 void greeting(){
     cout << "        ��� ��� ���������� ������� ������ ���� ��� ������."               << endl
            << " --------------------------------------------------------------------- "                       << endl
            << "|         ���������� ���������� ���������� ���� ����� ʲ-20:          |"      << endl
            << "|                           <<DEVELOPERS>>                            |"                    << endl
            << "|        ��������� ������ �������� - ��������� �� ��������� �����.    |" << endl
            << "|        ��������� ³���� ������� - ����� ����� � ����������        |"     << endl
            << "|        �������� ����� ��������� - ������� ����� � ������ ��        |"   << endl
            << " -----------------------(c)AllRightsAreReserved----------------------- "                       << endl;

    system("pause");
    system("cls");
 }

 void reg_down(){
     // ��������� ���� � ��������� ��� ������ � ������ ��������
     //
     reg_in.open(filename, ios_base::in);

     int iter = 0;
     while(!reg_in.eof()){
        getline(reg_in, line);
        if(line.length() > 1){ // ��������� ������ �� ������� ��� ����������� ������ ��������
                Reg.push_back(obj);
                Reg[iter].nomer = line;
                getline(reg_in, Reg[iter].owner);
                getline(reg_in, Reg[iter].model_year);
                getline(reg_in,  Reg[iter].reg_date);
        }

        iter++;
     }

     reg_in.close();
 }

 void reg_reader(){
     // ������� �� ����� ��� ���������� ������� ��������
     //

    cout << "�� ������ ��������� ������ �� �����." << endl
            << "-----------------------------------------------" << endl;

     for(int i = 0; i < Reg.size(); i++){
        cout << Reg[i].nomer << endl;
        cout << Reg[i].owner << endl;
        cout << Reg[i].model_year << endl;
        cout << Reg[i].reg_date << endl;
     }

     cout << "-----------------------------------------------" << endl;
     system("pause");
     system("cls");
 }

 void updater(){
     // ������� ������������ �� ����������
     //

     reg_out.open(filename, ios_base::trunc | ios_base::out);

     for(int j = 0; j < Reg.size(); j++){
            reg_out << Reg[j].nomer << endl
                       << Reg[j].owner << endl
                       << Reg[j].model_year << endl
                       << Reg[j].reg_date << endl;
     }

     reg_out.close();
 }

 void nomers(){
    cout << "� ����� �������� ��� ���� (1, 2, 3... - �������):" << endl;
    for(int i = 0; i < Reg.size(); i++){
        cout << i << ". " << Reg[i].nomer << endl;
    }
    cout << "------------------------------------------------------" << endl;
 }

 void new_car(){
     // ��� ������� ��������� ����� ������� � ������
     //

     Reg.push_back(obj);

    cout << "�� ������ ��������� ������ ��������� �� ������." << endl
            << "-------------------------------------------------------" << endl;

    cout << "���� �����, ������ ����� ������ ��������� (AA0000NA)."
            << endl << ">> ";
    getline(cin, line);
    bool flag = true;
    while(true){
        getline(cin, line);
        if(line.length() != 8){
            cout << "������ �������� �����, ��������� �� ���! (AA0000NA)" << endl << ">> ";
            flag = false;
        }
        else
            break;
    }
    Reg[Reg.size() - 1].nomer = line;

    cout << "������ ϲ� ��������. "
            << endl << ">> ";
    getline(cin, line);
    Reg[Reg.size() - 1].owner = "    " + line;

    cout << "������ ������ �� �� ������� ����. "
            << endl << ">> ";
    getline(cin, line);
    Reg[Reg.size() - 1].model_year = "    " + line;

    cout << "������ ���� ���������. "
            << endl << ">> ";
    getline(cin, line);
    Reg[Reg.size() - 1].reg_date = "    " + line;

    cout << "-------------------------------------------------------" << endl;
    system("pause");
    system("cls");
 }

 int find_car(){
     // ��� ������� ���� ������� � ��������� �� ������������� �������
     // ������� ��������� � ������� ��� ���������� ��������
     // ����������� ���� ���
     cout << "�� ������ ����� ���� �� �������� � �����." << endl;
     cout << "-------------------------------------------------------" << endl;

     nomers();
     int find_Elem;
     cout << "���� �����, ������ ������ ������ ���������, ���� �� ������ ������." << endl << ">> ";
     cin >> find_Elem;

     for(int i = 0; i < Reg.size(); i++)
     {
        if(find_Elem == i)
        {
            cout << "���������� ������ � �����: " << endl;
            cout << Reg[i].nomer << endl;
            cout << Reg[i].owner << endl;
            cout << Reg[i].model_year << endl;
            cout << Reg[i].reg_date << endl;
            break;
        }

        else if(find_Elem >= Reg.size()){
            cout << "���� �� ����� �������� ������." << endl;
            break;
        }

    }

    cout << "-------------------------------------------------------" << endl;
    system("pause");
    system("cls");

 }

int del_car(){
    // ���� ������ �� �������� �������������� ������ � ������� ���
    // ���� ������ �� ���� � �������, ���������� ��������� �� ������
    //

    cout << "�� ������ ��������� ��������� � ������." << endl
            << "-------------------------------------------------------" << endl;
    nomers();

    int del_elem;
    cout << "���� �����, ������ ������ ������ ���������, ���� �� ������ ��������." << endl << ">> ";
    cin >> del_elem;
    if(del_elem < Reg.size()){
        Reg.erase(Reg.begin() + del_elem);
        cout << "��������� ���� �������� � ������!" << endl;
    }
    else{
        cout << "�������, ��������� �� ���! (������� �� ����� �������� �� ���� ���������)" << endl;
    }

    cout << "-------------------------------------------------------" << endl;
    system("pause");
    system("cls");
}

int main(){
    SetConsoleCP(::GetACP());;
    SetConsoleOutputCP(::GetACP());;

    char key = ' ';
    greeting();
    reg_down();

    while(true){
        cout << "������ ������:" << endl
                << "N - ������ ���������;" << endl
                << "S - ������� �� ����� �����;" << endl
                << "D - �������� ���� � ������;" << endl
                << "F - ������ ���� � �����" << endl
                << "E - ���������� ������ � ����������� ���." << endl
                << "------------------------------------------------------" << endl;
        if(Reg.size() == 0){
            cout << "�� ����� ������ ����� ��������, �� �� ������ �������?" << endl;
        }else{
            nomers();
            cout << "�� �� ������ �������?" << endl;
        }
        cout << ">> ";
        cin >> key;
        switch(key){
        case 'S':
            system("cls");
            reg_reader();
            break;
        case 'N':
            system("cls");
            new_car();
            break;
        case 'D':
            system("cls");
            del_car();
            break;
        case 'F':
            system("cls");
            find_car();
            break;
        case 'E':
            system("cls");
            cout << "���������� ������...." << endl;
            updater();
            system("pause");
            return 0;
        default:
            cout << "������ ������� ���, ��������� ����� ����" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
}
