/*
  Assignment #1 Milestone #4
  Full name - Jay Girishkumar Patel
  Student ID number - 158741199
  Seneca email address - jgpatel10@gmail.com
  Course section code - ZCC
*/

#ifndef COMMON_HELPERS_H_
#define COMMON_HELPERS_H_
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int currentYear(void);

void clearStandardInputBuffer(void);

// 1 getinteger
int getInteger(void);

//2 getPositiveInteger
int getPositiveInteger(void);

//3 getDouble
double getDouble(void);

//4 getPositiveDouble
double getPositiveDouble(void);

//5 getIntFromRange
int getIntFromRange(int lower, int upper);

//6 getCharOption
char getCharOption(const char validchar[]);

//7 getCString
void getCString(char* string, int min, int max);

#endif