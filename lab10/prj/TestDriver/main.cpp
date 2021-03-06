#include <iostream>
#include <clocale>
#include <cstdlib>
#include <sstream>
#include <codecvt>
#include <fstream>
#include <wchar.h>
#include <fcntl.h>
#include <string>
#include <tchar.h>
#include <io.h>
#include <locale>

#include <ModulesNebesnyi.h>

using namespace std;

int main()
{
    _wsetlocale(LC_ALL, L"uk_UA.UTF-8");
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);

    wifstream inputFile;
    wofstream inputFileWrite;
    wofstream testOutput1;
    wofstream testOutput2;
    wofstream testOutput3;
    wofstream outputFile;
    int x[10] = {1, 2, 2, 1, 1, 5, 3, 2, 4, 1};
    int y[10] = {1, 1, -1, -2, 8, 12, 1, 2, 10, 0};
    int z[10] = {1, 1, 1, 2, 2, 2, 10, 5, -1, 0};
    float S = 0;
    float TrueS[10] = {6.14, 12.14, 8.74, 7.31, 3126.68, 9273.14, 127.73, -0.01, 4.14};

    wstring input[10] = {L"До", L"щастя", L"орава", L"забава", L"бабуся", L"робити", L"страждати", L"справу", L"життя", L"жити"};
    int resmarker = 0;
    int expMarker[10] = {1, 1, 1, 2, 2, 1, 2, 1, 1, 2};
    int vowelNum = 0;
    int vowNum[10] = {1, 2, 3, 3, 3, 3, 3, 2, 2, 2};
    int consExp[10] = {1, 3, 2, 3, 3, 3, 6, 4, 3, 2};
    char inputName[] = "input.txt";
    char outputName[] = "output.txt";
    int binNum[10] = {2, 3, 1, 4, 7, 5, 6, 8, 9, 10};
    int expBin[10] = {10, 11, 01, 100, 111, 101, 110, 1000, 1001, 1010};


    testOutput1.open("test1.txt");
    testOutput1.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    testOutput1.clear();
    for(int test_iter = 0; test_iter < 10; test_iter++){
        inputFileWrite.open(inputName);
        inputFileWrite.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
        inputFile.clear();

        inputFileWrite << input[test_iter].c_str();
        inputFileWrite.close();

        resmarker = f_searchword(inputName, outputName, &vowelNum);
        f_searchword(inputName, outputName, &vowelNum);

        if(resmarker == 1 && vowelNum == vowNum[test_iter])
            testOutput1 << L"Passed - слово " << input[test_iter].c_str() << L" присутнє в вірші, кількість голосних в слові - " << vowNum[test_iter] << endl;
        if(resmarker == 2 && vowelNum == vowNum[test_iter])
            testOutput1 << L"Passed - слово " << input[test_iter].c_str() << L" відсутнє у вірші, кількість голосних в слові - " << vowNum[test_iter] << endl;
        if(vowelNum != vowNum[test_iter])
            testOutput1 << L"Failed - у слові " << input[test_iter].c_str() << L" повинно бути приголосних " << vowNum[test_iter] << L", отримано було " << vowelNum << endl;
    }
    testOutput1.close();

    testOutput2.open("test2.txt");
    testOutput2.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    testOutput2.clear();
    for(int iter = 0; iter < 10; iter++){
        inputFileWrite.open(inputName);
        inputFileWrite.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
        inputFile.clear();

        inputFileWrite << input[iter].c_str();
        inputFileWrite.close();

        int consCounted = f_countcons(inputName, outputName);
        if(consCounted == consExp[iter]){
            testOutput2 << L"Passed: отриманий результат - " << consCounted <<
             L", приріотетний результат - " << consExp[iter] << L", вхідні дані - " << input[iter].c_str() << endl;
        }
        else{
            testOutput2 << L"Failed: отриманий результат - " << consCounted <<
             L", приріотетний результат - " << consExp[iter] << L", вхідні дані - " << input[iter].c_str() << endl;
        }

    }
    testOutput2.close();

    testOutput3.open("test3.txt");
    testOutput3.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    testOutput3.clear();
    for(int iter = 0; iter < 10; iter++){
        int bin = binNum[iter];
        f_resofscalc(outputName, x[iter], y[iter], z[iter], &S, &binNum[iter]);

        if(TrueS[iter] == S && binNum[iter] == expBin[iter]){
            testOutput3 << L"Passed: при x, y, z " << x[iter] << L" " << y[iter] << L" " << z[iter] << L" відповідно очікуване S = " << TrueS[iter] << L", отримане S = " << S << endl
                        << L"        число " << bin << L" у двійковій системі числення має вигляд 0b" << expBin[iter] << L", отриманий резулятат - 0b" << binNum[iter] << endl;
        }
        else{
            testOutput3 << L"Passed: при x, y, z " << x[iter] << L" " << y[iter] << L" " << z[iter] << L" відповідно очікуване S = " << TrueS[iter] << L", отримане S = " << S << endl
                        << L"        число " << bin << L" у двійковій системі числення має вигляд 0b" << expBin[iter] << L", отриманий резулятат - 0b" << binNum[iter] << endl;

        }
    }
    testOutput3.close();

    wcout << L"Вітаю! Данний тестовий драйвер провів тестування модулів лабораторної роботи №10" << endl;
    wcout << L"Результати тестування записано у файли test1, test2, test3 відповідно." << endl;
    system("pause");

    return 0;
}
