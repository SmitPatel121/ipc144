/*
	==================================================
	Workshop #4 (Part-2):
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
	double net = 0, total = 0, prioritycost;  //declaring double variables

	int things = 0, i = 0, j = 0, p, years, months, pl;

	double price[10]; // declaring double price array

	int pr[10];

	char finance[10];

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

	int keepgoing = 1;


	while (p!=0){

	
		for (i = 0; keepgoing && i < things; i++)
		{




			printf("How do you want to forecast your wish list?\n");
			printf(" 1. All items (no filter)\n");
			printf(" 2. By priority\n");
			printf(" 0. Quit/Exit\n");
			printf("Selection: ");
			scanf("%d", &p);
			
			if (p >= 3 || p < 0)
			{
				printf("\nERROR: Invalid menu selection.\n\n");
				
				
			}

			
			else if (p == 0)
			{
				printf("\nBest of luck in all your future endeavours!\n");
				keepgoing = 0;
			}
			


			if (p == 1) {
				
				printf("\n====================================================\n");
				printf("Filter:   All items\n");
				printf("Amount:   $%.2lf\n", total);
				years = (int)(total / (double)net) / 12;
				months = (int)(total / (double)net) % 12;
				printf("Forecast: %d years, %d months\n", years, months + 1);
				printf("NOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.\n");
				printf("====================================================\n\n");
				
			}

		

			if (p == 2) {
				printf("\nWhat priority do you want to filter by? [1-3]: ");
				scanf("%d", &pl);
				for (i = 0; i < things; i++)
				{
					if (pl == pr[i])
					{
						prioritycost = prioritycost + price[i];

					}

				}
				printf("\n====================================================\n");
				printf("Filter:   by priority (%d)\n", pl);
				printf("Amount:   $%1.2lf\n", prioritycost);
				years = (int)(prioritycost / (double)net) / 12;
				months = (int)(prioritycost / (double)net) % 12;

				printf("Forecast: %d years, %d months\n", years, months + 1);
				prioritycost = 0;
				
					if ( p==2 &&(pl==1 || pl==3))
					{
						printf("NOTE: Financing options are available on some items.\n");
						printf("      You can likely reduce the estimated months.\n");
						printf("====================================================\n");
					}
					if (p ==2 && (pl ==2)){
						printf("====================================================\n");
					}
					
				
				printf("\n");
			}
			

			
			
			

			
		}

	}
	return 0;
}