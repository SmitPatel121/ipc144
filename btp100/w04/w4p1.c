/*
	==================================================
	Workshop #4 (Part-1):
	==================================================
	Name   : Smit Anjaykumar patel
	ID     : 104424213
	Email  : sapatel59@myseneca.ca
	Section: BPT100NAA.07777.2217
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
const int max = 400000;
const int min = 500;

int main(void)
{
	double net = 0, total = 0;  //declaring double variables

	int things = 0, i = 0, j = 0;
	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n");

	printf("\nEnter your monthly NET income: $"); //prompting of the input of net monthly income



	do {
		scanf("%lf", &net);

		if (net >= 400000) {
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00");

			printf("\n\nEnter your monthly NET income: $");
		}
		else if (net < 500) {
			printf("ERROR: You must have a consistent monthly income of at least $500.00");

			printf("\n\nEnter your monthly NET income: $");

		}
	} while (net >= max || net <= min); // using do while loop

	double price[10]; // declaring double price array

	int pr[10];

	char finance[10];

	do {
		printf("\nHow many wish list items do you want to forecast?: ");

		scanf("%d", &things);
		if (things < 1 || things > 10) {

			printf("ERROR: List is restricted to between 1 and 10 items.\n");
		}

	} while (things < 1 || things > 10);

	for (i = 0; i < things; i++) {
		printf("\nItem-%d Details:\n", (i + 1));

		printf("   Item cost: $");

		scanf("%lf", &price[i]);

		while (price[i] < 100) {
			printf("      ERROR: Cost must be at least $100.00\n");
			printf("   Item cost: $");

			scanf("%lf", &price[i]);

		} 
			

			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");

			scanf("%d", &pr[i]);

		while (pr[i] < 1 || pr[i] > 3) {

			printf("      ERROR: Value must be between 1 and 3\n");
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");

			scanf("%d", &pr[i]);
			
		} 
		printf("   Does this item have financing options? [y/n]: ");
		scanf("%s", &finance[i]);
		

		while ((finance[i] != 'y' && finance[i] != 'n')) {
			printf("      ERROR: Must be a lowercase 'y' or 'n'\n");

			printf("   Does this item have financing options? [y/n]: ");

			scanf("%s", &finance[i]);

			
		} 
	}

	printf("\nItem Priority Financed        Cost\n");

	printf("---- -------- -------- -----------\n");

	while (j < things) {
		printf("%3d  %5d    %5c    %11.2lf\n", j + 1, pr[j], finance[j], price[j]);
		total = total + price[j];
		j++;
	}
	printf("---- -------- -------- -----------");

	printf("\n                      $%11.2f\n\n", total);

	printf("Best of luck in all your future endeavours!\n");

	return 0;
}