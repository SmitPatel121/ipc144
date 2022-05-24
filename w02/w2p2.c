/*
	==================================================
	Workshop #2 (Part-2):
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

	int toonies, loonies, quarter,dimes,nickels,pennies,x,left, left1, left2,left3,left4;  // assigining the int to the variable
	float money, fee,p,q,r,s,t,u;  // assigining the float to the variable which requires decimal operations

	printf("Change Maker Machine\n");

	printf("====================\n");

	printf("Enter dollars and cents amount to convert to coins: $"); //printing (Enter dollars and cents amount to convert to coins: $ )

	scanf("%f", &money); // getting input from user in value of money

	fee = money * 0.05; // calculating the service fee from the user inpute. 

	printf("Service fee (5.0 percent): %0.2f\n", fee); //printing the service fee
        
	money = money - fee ;
	printf("Balance to dispense: $%0.2f",money);
	
	x = money*100 ;             
	toonies = x / 200;  // applying arithmetic and logic to solve the equation

	left = x % 200; // modulus is used to do calculation
   	
	p = left / 100.00;
    	
	loonies = left / 100.00;
    	
	left1 = left%100;
    	
	q = left1 / 100.00;
    	
	quarter = left1 / 25.00;
    	
	left2 = left1 % 25;
    	
	r = left2 / 100.00;
    	
	dimes= left2 / 10.00;
    	
	left3 = left2%10;
    	
	s = left3 / 100.00;
    	
	nickels = left3 / 5.00;
    	
	left4 = left3%5;
    	
	t = left4 / 100.00;
    	
	pennies = left4 / 1;
    	
	u=0;
	printf("\n\n$%.2f Toonies  X %d (remaining: $%.2f)\n", 2.00, toonies, p); // ( printing the output of our calculations )

	printf("$%.2f Loonies  X %d (remaining: $%.2f)\n", 1.00, loonies, q);

	printf("$%.2f Quarters X %d (remaining: $%.2f)\n", 0.25, quarter, r);
	
	printf("$%.2f Dimes    X %d (remaining: $%.2f)\n",0.1,dimes, s);

	printf("$%.2f Nickels  X %d (remaining: $%.2f)\n", 0.05, nickels, t);

	printf("$%.2f Pennies  X %d (remaining: $%.2f)\n", 0.01, pennies, u);	

	printf("\nAll coins dispensed!\n");

	return 0;
}
