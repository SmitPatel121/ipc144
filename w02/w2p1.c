/*
	==================================================
	Workshop #2 (Part-1):
	==================================================
	Name   : smit anjaykumar patel
	ID     : 104424213
	Email  : sapatel59@myseneca.ca
	Section: BTP100NAA.07777.2217
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{       
        
	int toonies, loonies, quarter;  // toonies, loonies , quarter will be in integer

	double money, left,left1 , left2; // money , left , left1, left2 are double so the walue will cointain decimal
	
	printf("Change Maker Machine\n");

	printf("====================\n");

	printf("Enter dollars and cents amount to convert to coins: $"); //printing (Enter dollars and cents amount to convert to coins: $ )

	scanf("%lf", &money); // getting input from user in value of money 

	toonies = (int)money / 2;  // applying arithmetic and logic to solve the equation
 
	left = money - (toonies * 2);

	loonies = left;

	left1 = left - loonies;

	quarter = (double)left1/0.25;



	left2 = left1 - (quarter * 0.25);
	
	printf("\n$%0.2lf Toonies  X %d (remaining: $%0.2lf)\n", 2.00, toonies, left); // ( printing the output of our calculations )

	printf("$%0.2lf Loonies  X %d (remaining: $%0.2lf)\n", 1.00, loonies, left1);

	printf("$%0.2lf Quarters X %d (remaining: $%0.2lf)\n", 0.25, quarter, left2);

	printf("\nMachine error! Thank you for letting me keep $%0.2lf!\n", left2);
	return 0;
}
