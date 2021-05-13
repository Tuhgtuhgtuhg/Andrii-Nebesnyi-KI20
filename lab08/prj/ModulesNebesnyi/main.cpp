#include <iostream>
#include <fstream>
#include <wchar.h>
#include <io.h>
#include <fcntl.h>
#include <clocale>
#include <string>
#include <cstdlib>
#include <sstream>
#include <codecvt>
#include <ctime>
#include <bitset>
#include <cmath>

//#include "ModulesNebesnyi.h"

using namespace std;


int bin_zero_counter(int number){
    int mask = 1;
    int mask_2 = 1;

    int BinOne = 0;
    int BinZero = 0;

    for(int i = 0; i < (log2(number)); i++){
        if(!(number & mask))
            BinZero++;
        else
            BinOne++;
        mask<<=1;
    }

    if(!(number & (mask_2 << 12))){
        wcout << L"Binary Zero - ";
        return BinZero;
    }else{
        wcout << L"Binary One - ";
        return BinOne;
    }
}

float temp_calculation(float week_tem[], int size, float *Med_F, float *Med_C){
    (*Med_F) = 0;
    (*Med_C) = 0;
    for(int i = 0; i < size ; i++){
        (*Med_C) = (*Med_C) + (week_tem[i]);
    }
    (*Med_C) = (*Med_C) / 7;
    (*Med_F) = 32 + (*Med_C) * 9/5;
    (*Med_F) = int((*Med_F)*100 + 0.5)/100.0;
    (*Med_C) = int((*Med_C)*100 + 0.5)/100.0;
}

int rating_actions(int mark){
    char rating = ' ';

    if (mark >= 90 && mark <= 100) {
        rating = 'A';
        wcout << L"Excellent performance with small number of errors - ";
        return (char)rating;
    } else if (mark >= 82 && mark <= 89) {
        rating = 'B';
        wcout << L"Above average some mistakes - ";
        return (char)rating;
    } else if (mark >= 75 && mark <= 81) {
        rating = 'C';
        wcout << L"Overall correct fulfillment of certain significant number of errors - ";
        return (char)rating;
    } else if (mark >= 67 && mark <= 74) {
        rating = 'D';
        wcout << L"Not bad, but with significant number of defects - ";
        return (char)rating;
    } else if (mark >= 60 && mark <= 66) {
        rating = 'E';
        wcout << L"satisfies minimum criteria - ";
        return (char)rating;
    } else if (mark >= 35 && mark <= 59) {
        rating = 'F';
        wcout << L"With a possibility of re-assembly - ";
        return (char)rating;
    } else if (mark >= 0 && mark <= 34) {
        rating = 'X';
        wcout << L"With the obligatory repeated course - F";
        return (char)rating;
    } else {
        return 0.0;
    }
}

float s_calculation(int x, int y, int z){
    float S = pow((2*z + 1), x) - sqrt(abs(y - 1/2 * z)) + 3.14 + z;
    S = int(S*100 + 0.5)/100.0; // two symbols after the coma
    return S;
}

int f_searchword(char *inputName, char *outputName, int *vowelNum){
    _wsetlocale(LC_ALL, L"uk_UA.UTF-8");
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);

    wifstream inputFile;
    wofstream outputFile;
    *vowelNum = 0;
    int vows = 0;
    wstring inputWord;
    wchar_t vowelSounds[] = L"АаЕеЄєиІіЇїУуЮюЯяОо";
    wchar_t poesy[1000] = {L"До щастя не пускає лінощів орава. У чім воно - ніхто не знає до пуття."
                     "Навчитись радісно робити кожну справу - Найперше правило щасливого життя."};

    inputFile.open(inputName);
    inputFile.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    getline(inputFile, inputWord);
    inputFile.close();

    wchar_t wstr[50] = L"";
    wcscat(wstr, inputWord.c_str());

    outputFile.open(outputName);
    outputFile.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    outputFile.clear();
    outputFile << L" ----------------------------------------------- " << endl
               << L"| Застосунок розроблено студентом першого курсу |" << endl
               << L"|                університету ЦНТУ              |" << endl
               << L"|       Небесним Андрієм Вадимовичем КІ-20      |" << endl
               << L" --------------©AllRightsAreReserved------------ " << endl;
    bool Marker = 0;
    int testRes = 0;

    if(wcsstr(poesy ,wstr)){
        outputFile << L"Cлово " << inputWord << L" присутнє в краплинці Віталія Іващенка." << endl;
        testRes = 1;
    }
    else{
        outputFile << L"Cлово " << inputWord << L" відсутнє в краплинці Віталія Іващенка." << endl;
        testRes = 2;
    }
    for(int i = 0; i < wcslen(wstr); i++){
        for(int j = 0; j < wcslen(vowelSounds); j++)
            if(inputWord[i] == vowelSounds[j]) vows++;
    }
    *vowelNum = vows;

    if(*vowelNum > 0)
        outputFile << L"Кількість голосних в слові " << wstr << L" - " << *vowelNum << endl;
    else
        outputFile << L"Голосні в слові " << wstr << L" відсутні." << endl;

    outputFile.close();

    return testRes;
}

int f_countcons(char *inputName,char *outputName){
    _wsetlocale(LC_ALL, L"uk_UA.UTF-8");
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);

    wofstream outputFile;
    wifstream inputFile;
    int consNum = 0;
    wchar_t consSounds[] = L"БбВвГгҐґДдЖжЗзКкЛлМмНнПпРрСсТтфФХхЦцЧчШшЩщ";
    wchar_t ch_IW[50] = L"";
    wstring inputWord;

    inputFile.open(inputName);
    inputFile.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    getline(inputFile, inputWord);
    inputFile.close();

    wcscat(ch_IW, inputWord.c_str());
    outputFile.open(outputName, ios::app);
    outputFile.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));
    for(int i = 0; i < wcslen(ch_IW); i++){
        for(int j = 0; j < wcslen(consSounds); j++)
            if(ch_IW[i] == consSounds[j]) consNum++;
    }

    time_t currTime;
    time(&currTime);

    outputFile << endl << L"Кількість приголосних у слові " << ch_IW << " - " << consNum << endl
               << L"Час дозапису інформації: " << endl << ctime(&currTime) << endl;
    outputFile.close();

    return consNum;
}

int dec2bin(int num)
{
    int bin = 0, k = 1;

    while (num)
    {
        bin += (num % 2) * k;
        k *= 10;
        num /= 2;
    }

    return bin;
}

int f_resofscalc(char *outputName, int x, int y, int z, float *S, int *binNum){
    _wsetlocale(LC_ALL, L"uk_UA.UTF-8");
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);

    wofstream outputFile;
    int bitSize = 0;

    outputFile.open(outputName, ios::app);
    outputFile.imbue(locale(locale(), new codecvt_utf8_utf16<wchar_t>));

    *binNum = dec2bin(*binNum);
    *S = s_calculation(x, y, z);

    outputFile << L"Результат виконання s_calculation: " << *S << endl
               << L"Число B у двійковій системі числення: " << *binNum;

    outputFile.close();

    return 0;
}
