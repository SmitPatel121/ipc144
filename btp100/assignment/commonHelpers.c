/*
	==================================================
	Assignment #1 Milestone #2
	==================================================
	Name   : Smit Anjaykumar Patel
	ID     : 104424213
	Email  : sapatel59@myseneca.ca
	Section: BTP100NAA
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <time.h>

int currentYear(void) //using the time.h library to get information about current year
{
	time_t currentTime = time(NULL);
	return localtime(&currentTime)->tm_year + 1900;
}// getting the current 4-digit year from our system

void clearStandardInputBuffer(void)
{
	while (getchar() != '\n')
	{
		; // On purpose: do nothing
	}
}

int stringrange(char* r)
{
	int j = 0;
	while (*r != '\0') //declaring while loop where pointer r is not equal to 0.
	{
		j++;

		r++;
	}
	return j;
}



int getPositiveInteger() // using perdefined function getPositiveInteger
{
	char newline = 'x';

	int value;

	scanf("%d%c", &value, &newline);

	while (newline != '\n' || newline == 'x'){

		clearStandardInputBuffer();

		printf("ERROR: Value must");

		printf(" be an integer: ");

		scanf("%d%c", &value, &newline);
	}

	while (value <= 0) {

		printf("ERROR: Value must be a positive ");
		printf("integer greater than zero: ");

		scanf("%d%c", &value, &newline);
	}

	return value;
}

int getInteger() // using predefinrd function getInteger function
{
	char newline = 'x';

	int value;
	
	scanf("%d%c", &value, &newline);

	while (newline != '\n')
	{
		clearStandardInputBuffer();

		printf("ERROR: Value ");

		printf("must be an integer: ");

		scanf("%d%c", &value, &newline);
	}

	return value;

}

double getPositiveDouble() //using pre defined get positive double function
{
	char newline = 'x';

	double value;

	scanf("%lf%c", &value, &newline);

	while (newline != '\n')
	{
		clearStandardInputBuffer();

		printf("ERROR: Value must be a");

		printf(" double floating-point number: ");

		scanf("%lf%c", &value, &newline);
	}
	while (value <= 0)
	{
		printf("ERROR: Value must be a positive");

		printf(" double floating-point number: ");

		scanf("%lf%c", &value, &newline);
	}
	return value;
}

double getDouble()
{
	char newline = 'x';

	double value;

	scanf("%lf%c", &value, &newline);

	while (newline != '\n'){

		clearStandardInputBuffer();

		printf("ERROR: Value must be a double");

		printf(" floating-point number: ");

		scanf("%lf%c", &value, &newline);
	}

	return value;
}



char getCharOption(char* f)
{
	int m, z = 0;

	char test, newline = 'x';

	scanf("%c%c", &test, &newline);

	while (newline != '\n')
	{
		clearStandardInputBuffer();

		printf("ERROR: Character must be ");

		printf("one of [%s]: ", f);

		scanf("%c%c", &test, &newline);
	}
	for (m = 0; (f[m] != '\0' && z == 0); m++)
	{
		while (newline != '\n' || z == 0)
		{
			for ( m = 0; m <= stringrange(f) &&  z == 0; m++ )
			{
				if (f[m] == test)
				{
					z = 1;
				}
			}

			if (newline != '\n' || z != 1 )
			{
				printf("ERROR: Character must be one of [%s]: ", f);

				scanf("%c%c", &test, &newline);
			}
		}
	}
	return test;
}

int getIntFromRange(int low_bound, int up_bound)
{
	int value;

	char newline = 'x';
	
	scanf("%d%c", &value, &newline);

	if (newline == 'x')
	{
		clearStandardInputBuffer();

		printf("ERROR: Value must be an integer: ");

		scanf("%d%c", &value, &newline);

	}

	while (value < low_bound || value > up_bound){

		printf("ERROR: Value must be between");

		printf(" %d and %d inclusive: ", low_bound, up_bound);

		scanf("%d%c", &value, &newline);
	}
	return value;
}
void getCString(char* s, int min_value, int max_value)
{
	int m = 0, z = 0;

	char ch[41];

	scanf("%40[^\n]", ch);

	for (m = 0; ch[m] != '\0'; m++)
	{
	}


	while ( m > max_value || m < min_value )
	{
		clearStandardInputBuffer();

		if (min_value == max_value)
		{
			printf("ERROR: String length must be exactly ");

			printf("%d chars: ", min_value);

			scanf("%40[^\n]", ch);
		}

		if (min_value != max_value)
		{
			if (m < min_value)
			{
				printf("ERROR: String length must be between %d and %d chars: ", min_value, max_value);
				scanf("%40[^\n]", ch);
			}
			else if (m > max_value)
			{
				printf("ERROR: String length must be no more than %d chars: ", max_value);
				scanf("%40[^\n]", ch);
			}
		}
		for (m = 0; ch[m] != '\0'; m++)
		{
		}
	}
	for (z = 0; ch[z] != '\0'; z++)
	{
		s[z] = ch[z];
	}
	s[z] = '\0';
	getchar();
}
