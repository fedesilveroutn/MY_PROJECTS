#ifndef INPUT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define INPUT_H_

/*--------------------------------INPUT DATA--------------------------------*/
int getInt (int* num, char* message, char* error, int min, int max);
int getFloat (float* num, char* message, char* error, float min, float max);
int getString (char* string, char* message, char* error, int max);
int systemPause(char* message);

/*--------------------------------OUTPUT DATA--------------------------------*/
void menu();
void positiveMessage(char* message);
void negativeMessage(char* message);
void actionMessage(char* message);
int stringFormat(char* string, int format);

#endif
