#include <iostream>
#include <io.h>
#include <wchar.h>
#include <fcntl.h>

#include "ModulesNebesnyi.h"

using namespace std;

void dev_information()
{
    wcout << L" ---------------------------------------------------------------------------- " << endl;
    wcout << L"| Даний застосунок розроблено студентом центральноукраїнського нацiонального |" << endl;
    wcout << L"| технiчного унiверситету Небесним Андрiєм Вадимовичем 10 квітня 2021 року.  |" << endl;
    wcout << L" ---------------------------©ALL_RIGHTS_ARE_RESERVED-------------------------" << endl;
}

int main()
{
    _wsetlocale(LC_ALL,L" ");
    _setmode(_fileno(stdout), _O_U8TEXT);

    char input = ' ';
    int x, y, z;
    float Med_F, Med_C;
    float week_temp[7];
    int number = 0;
    int mark = 0;

    dev_information();

    wcout << L"h - розв'язування виразу S = (2*z - 1)^x - v(|y - 0.5 * z|) + z + п." << endl;
    wcout << L"f - розрахувати рейтинг студента за балом." << endl;
    wcout << L"d - розрахувати середньомісячну температуру у цельсії та фарингейтах." << endl;
    wcout << L"s - порахувати кількість бінарних нулів та одиниць числа." << endl;
    wcout << L"a, A, p - вийти." << endl;
    wcout << L"______________________________________________________________________" << endl;

    while(true){
       wcout << L"Введіть ключ: ";
       cin >> input;

       if(input == 'h'){
            while(true){
                 wcout << L"Введiть х: ";
                 if(!scanf("%d", &x)){
                     scanf("%*[^\n]");
                     wcout << L"Ви ввели символ, введіть число." << endl;
                 }
                 else
                     break;
            }
            while(true){
                 wcout << L"Введiть y: ";
                 if(!scanf("%d", &y)){
                     scanf("%*[^\n]");
                     wcout << L"Ви ввели символ, введіть число." << endl;
                 }
                 else
                     break;
             }
             while(true){
                 wcout << L"Введiть z: ";
                 if(!scanf("%d", &z)){
                     scanf("%*[^\n]");
                     wcout << L"Ви ввели символ, введіть число." << endl;
                 }
                 else
                     break;
             }
             wcout << L"Результат S = " << s_calculation(x, y, z) << endl;
             wcout << L"______________________________________________________________________" << endl;
       } else if(input == 'f'){
            while(true){
                wcout << L"Введіть бал студента (від 0 до 100): ";
                cin >> mark;
                if(mark >=0 && mark <= 100)
                {
                    wcout << L"Студент має такий рейтинг - " << (char)rating_actions(mark) << endl;
                    break;
                }
                else{
                    wcout << L"Невірно введено дані, спробуйте ще раз." << endl;
                }
            }
            wcout << L"______________________________________________________________________" << endl;
       } else if(input == 'd'){
            for(int i = 0; i < 7; i++){
                while(true){
                     wcout << L"Введіть температуру за " << i+1 << L" день: ";
                     if(!scanf("%f", &week_temp[i])){
                         scanf("%*[^\n]");
                         wcout << L"Ви ввели символ, введіть число." << endl;
                     }
                     else
                         break;
                }
            }
            temp_calculation(week_temp, 7, &Med_F, &Med_C);
            wcout << L"Середня температура за тиждень у фарингейтах: " << Med_F << endl;
            wcout << L"Середня температура за тиждень у цельсії: " << Med_C << endl;
            wcout << L"______________________________________________________________________" << endl;
       } else if(input == 's'){
            while(true){
                wcout << L"Введіть ціле число від 0 до 17948360: ";
                if(!scanf("%d", &number)){
                    scanf("%*[^\n]");
                    wcout << L"Ви ввели символ, введіть число." << endl;
                }else if(number >= 0 && number <= 17948360)
                {
                    wcout << bin_zero_counter(number) << L" - результат виконання." << endl;
                    break;
                }else{
                    wcout << L"Невірно введені дані." << endl;
                }
            }
            wcout << L"______________________________________________________________________" << endl;
       } else if(input == 'A' || input == 'a' || input == 'p'){
            break;
       } else {
            wcout << L"Невірно введений ключ." << endl;
       }

    }

    return 0;
}
