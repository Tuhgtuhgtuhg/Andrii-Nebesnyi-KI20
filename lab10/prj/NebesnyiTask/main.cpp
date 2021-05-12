#include <iostream>
#include <cwchar>
#include <io.h>
#include <clocale>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <codecvt>
#include <fcntl.h>

#include "ModulesNebesnyi.h"

using namespace std;

int main()
{
    _wsetlocale(LC_ALL, L"uk_UA.UTF-8");
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);

    wifstream inputFile;
    wchar_t inputName[100] = L"";
    char outputName[] = "output.txt";
    wchar_t Key[2] = L"";
    wchar_t D[2] = L"D";
    wchar_t F[2] = L"F";
    int vowelNum = 0;

    wcout << L"----------------------------------------------------------------------------" << endl;
    wcout << L"Даний застосунок виконує операції над файлами, використовуючи функції:      " << endl;
    wcout << L" * f_searchword - шукає слово з вхідного файлу у поезії та вносить до файлу " << endl;
    wcout << L"   інформацію про розробника та кількість голосних у введеному слові. Увага!" << endl;
    wcout << L"   Дана функція повністю очищує вміст вихідного файлу output.txt            " << endl;
    wcout << L" * f_countcons - рахує кількість приголосних у вхідному слові та записує ре-" << endl;
    wcout << L"   зультат у вихідний файл, у файлі відображається час дозапису інформації. " << endl;
    wcout << L" * f_resofscalc - рахує число S за формулою з лабораторної роботи №8 та пе- " << endl;
    wcout << L"   реводить число binNum у двійкову систему числення, результат записується " << endl;
    wcout << L"   до вихідного файду.                                                      " << endl;
    wcout << L"----------------------------------------------------------------------------" << endl;

    wcout << L"Введіть назву та розширення вхідного файлу(Ви створюєте вхідний файл): ";
    wcin.getline(inputName, 50);
    wcout << L"Введіть до файлу слово для перевірки його наявності в вірші, після введення напишіть в консоль D: ";
    wcin.getline(Key, 2);
    while(!wcsstr(D, Key) && !wcsstr(F, Key)){
        wcout << L"Ви ввели невірний ключ, спробуйте ще раз: ";
        wcin >> Key;
    }
    if(wcsstr(F, Key)){
        wcout << L"Застосунок завершиться після натиснення Enter" << endl;
        system("pause");
        return 0;
    } else if(wcsstr(D, Key)){
        wcout << L"Ключи для виклику функцій: " << endl;
        wcout << L"f_searcword -- F" << endl;
        wcout << L"f_countcons -- C" << endl;
        wcout << L"f_resofscalc -- S" << endl;
        wcout << L"exit - E" << endl;


        while(true){
            wchar_t fKey;
            int x = 0;
            int y = 0;
            int z = 0;
            float S = 0;
            int binNum = 0;
            char ch_inputName[50] = "";
            wcstombs(ch_inputName, inputName, sizeof(ch_inputName));

            wcout << L"Введіть ключ для: ";
            wcin >> fKey;

            if(fKey == 'E')
                return 0;

            switch(fKey)
            {
                case 'F':
                    f_searchword(ch_inputName, outputName, &vowelNum);
                    wcout << L"Робота с файлами була завершена, результати виконання f_searchword можна побачити у вихідному файлі." << endl;
                    break;
                case 'C':
                    f_countcons(ch_inputName, outputName);
                    wcout << L"Робота с файлами була завершена, результати виконання f_countcons можна побачити у вихідному файлі." << endl;
                    break;
                case 'S':
                    wcout << L"Введіть x ";
                    wcin >> x;
                    wcout << L"Введіть y ";
                    wcin >> y;
                    wcout << L"Введіть z ";
                    wcin >> z;
                    wcout << L"Введіть binNum ";
                    wcin >> binNum;
                    f_resofscalc(outputName, x, y, z, &S, &binNum);
                    wcout << L"Робота с файлами була завершена, результати виконання f_resofscalc можна побачити у вихідному файлі." << endl;
                    break;
                default:
                    wcout << L"Невірно введений ключ" << endl;
                    break;
            }
        }
    }

    return 0;
}
