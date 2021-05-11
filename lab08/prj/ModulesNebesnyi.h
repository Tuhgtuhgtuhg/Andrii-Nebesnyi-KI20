#ifndef MODULESNEBESNYI_H_INCLUDED
#define MODULESNEBESNYI_H_INCLUDED


float s_calculation(int x, int y, int z);
float temp_calculation(float week_tem[], int els, float *Med_F, float *Med_C);
int rating_actions(int mark);
int bin_zero_counter(int number);
int dec2bin(int num);
int f_resofscalc(char *outputName, int x, int y, int z, float *S, int *binNum);
int f_countcons(char *inputName, char *outputName);
int f_searchword(char *inputName, char *outputName, int *vowelNum);

#endif // MODULESNEBESNYI_H_INCLUDED
