/*
==================================================
Workshop #6 (Part-1):
==================================================
Name : smit anjaykumar patel
ID : 104424213
Email : sapatel59@myseneca.ca
Section: BTP100NAA.07777.2217
*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries

#include <stdio.h>

// User Libraries
#include "w6p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
// (return the number while also assigning it to the pointer argument)

int getIntPositive(int* number) {
	int n = 0;

	while (n < 1) {
		scanf("%d", &n);

		if (n < 1)

			printf("ERROR: Enter a positive value: ");
	}
	if (number != NULL)

		*number = n;

	return n;
}
// 2. Get user input of double type and validate for a positive non-zero number
// (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* number) {

	double n = 0;

	while (n < 1) {
		scanf("%lf", &n);

		if (n < 1)

			printf("ERROR: Enter a positive value: ");
	}
	if (number != 0)

		*number = n;
	return n;
}
// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int num_of_products) {

	//printf("========================== =");
	//printf("Starting Main Program Logic");
	//printf("========================== =");

	printf("Cat Food Cost Analysis\n");

	printf("======================\n\n");

	printf("Enter the details for %d dry food bags of product data for analysis.\n", num_of_products);

	printf("NOTE: A 'serving' is 64g\n");

	return;
}


// 4. Get user input for the details of cat food product
CatFoodInfo getCatFoodInfo(int sku_num) {

	CatFoodInfo food;

	food.sku_num = sku_num;

	double worth = 0;

	printf("PRICE         : $");

	while (worth <= 0)

		worth = getDoublePositive(NULL);

	food.value = worth;

	printf("WEIGHT (LBS)  : ");

	double weight = 0;

	while (weight <= 0)

		weight = getDoublePositive(NULL);

	food.weight = weight;

	printf("CALORIES/SERV.: ");

	int calories = 0;

	while (calories <= 0)


		calories = getIntPositive(NULL);

	food.calories = calories;

	return food;
}


// 5. Display the formatted table header

void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");

	printf("------- ---------- ---------- --------\n");
}
// 6. Display a formatted record of cat food data

void displayCatFoodData(int sku_num, double* value, double* weight,	int calories) 
{

	printf("%07d %10.2lf %10.1lf %8d\n", sku_num, *value, *weight, calories);

}

// 7. Logic entry point

void start() {
	setbuf(stdout, NULL);

	CatFoodInfo food[MAX_NUM_PRODUCTS];

	openingMessage(MAX_NUM_PRODUCTS);

	int j, sku_num;

	for (j = 0; j < MAX_NUM_PRODUCTS; j++) {

		printf("\nCat Food Product #%d", j + 1);

		printf("\n--------------------\n");

		printf("SKU           : ");

		sku_num = 0;

		while (sku_num <= 0)

			sku_num = getIntPositive(NULL);

		food[j] = getCatFoodInfo(sku_num);

	}
	displayCatFoodHeader();

	for (j = 0; j < MAX_NUM_PRODUCTS; j++)

		displayCatFoodData(food[j].sku_num, &food[j].value,	&food[j].weight, food[j].calories);

	return;
}