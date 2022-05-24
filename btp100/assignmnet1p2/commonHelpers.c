/*
  Assignment #1 Milestone #4
  Full name - Jay Girishkumar Patel
  Student ID number - 158741199
  Seneca email address - jgpatel10@gmail.com
  Course section code - ZCC
*/


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "commonHelpers.h"
#include <time.h>


// Uses the time.h library to obtain current year information 
// Get the current 4-digit year from the system 
int currentYear(void)
{
	time_t currentTime = time(NULL);
	return localtime(&currentTime)->tm_year + 1900;
}


// As demonstrated in the course notes:
// Empty the standard input buffer 
void clearStandardInputBuffer(void)
{
	while (getchar() != '\n')
	{
		; // On purpose: do nothing 
	}

}

// 1 getinteger
int getInteger(void)
{
	char newline;
	int y;
	int flag = 0;
	do
	{
		newline = 'x';
		scanf("%d%c", &y, &newline);

		if (newline == '\n')
		{
			flag = 1;
		}
		else
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be an integer: ");
		}
	} while (flag == 0);
	return y;
}

//2 getPositiveInteger
int getPositiveInteger(void)
{
	int y;
	int flag = 0;
	do
	{
		scanf("%d", &y);
		if (y >= 0)
		{
			flag = 1;
		}
		else
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be a positive integer greater than zero: ");
		}
	} while (flag == 0);

	return y;
}

//3 getDouble
double getDouble(void)
{
	char newline;
	double y;
	int flag = 0;
	do
	{
		scanf("%lf%c", &y, &newline);
		if (newline == '\n')
		{
			flag = 1;
		}
		else
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be a double floating-point number: ");
		}
	} while (flag == 0);
	return y;
}
//4 getPositiveDouble
double getPositiveDouble(void)
{
	double y;
	char newline;
	int flag = 0;
	do
	{
		scanf("%lf%c", &y, &newline);
		if (newline == '\n')
		{
			if (y > 0)
			{
				flag = 1;
			}
			else
			{
				printf("ERROR: Value must be a positive double floating-point number: ");
			}
		}
		else
		{
			clearStandardInputBuffer();
			printf("ERROR: Value must be a double floating-point number: ");
		}
	} while (flag == 0);
	return y;
}

//5 getIntFromRange
int getIntFromRange(int lower, int upper)
{
	int y;
	int flag = 0;

	do
	{
		y = getInteger();

		if (y <= upper && y >= lower)
		{
			flag = 1;
		}
		else
		{
			printf("ERROR: Value must be between %d and %d inclusive: ", lower, upper);

		}

	} while (flag == 0);
	return y;
}

//6 getCharOption
char getCharOption(const char validchar[])
{
	int flag = 0;
	int flag2 = 0;
	char y;
	int i = 0;
	int n = 0;
	char newline;
	n = sizeof(validchar) / sizeof(validchar[0]);
	do
	{
		scanf(" %c%c", &y, &newline);
		if (newline == '\n')
		{
			for (i = 0; i < n; i++)
			{

				if (y == validchar[i])
				{
					flag++;
				}
			}

			if (flag >= 1)
			{
				flag2 = 1;
			}
			else
			{
				printf("ERROR: Character must be one of [%s]: ", validchar);
			}
		}
		else
		{
			printf("ERROR: Character must be one of [%s]: ", validchar);
			clearStandardInputBuffer();
		}
	} while (flag2 == 0);
	return y;
}

//7 getCString
void getCString(char* string, int min, int max)
{
	int n = 0;
	int flag = 0;
	do
	{


		scanf(" %[^\n]s", string);

		while (string[n] != '\0')
		{
			n++;
		}



		if (n <= max && n >= min)
		{
			flag = 1;
		}
		else
		{
			if (max == min)
			{

				printf("ERROR: String length must be exactly %d chars: ", max);
				clearStandardInputBuffer();
			}
			else if (n > max)
			{

				printf("ERROR: String length must be no more than %d chars: ", max);
				clearStandardInputBuffer();
			}
			else
			{

				printf("ERROR: String length must be between %d and %d chars: ", min, max);
				clearStandardInputBuffer();
			}
		}

		n = 0;
	} while (flag == 0);
}

