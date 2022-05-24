/*
==================================================
Workshop #6 (Part-1):
==================================================
Name : smit anjaykumar patel
ID : 104424213
Email : sapatel59@myseneca.ca
Section: BTP100NAA.07777.2217
*/

#define MAX_NUM_PRODUCTS 3

#define MIN_GRAMS_PER_SERVING 64

// ----------------------------------------------------------------------------
// structures

typedef struct
{
	int sku_num;

	double value;

	int calories; //declaring calories for storing calories per suggested serving

	double weight;

}CatFoodInfo;

// ----------------------------------------------------------------------------
// function prototypes
// 1. Get user input of int type and validate for a positive non-zero number
// (return the number while also assigning it to the pointer argument)
int getIntPositive(int * number);

// 2. Get user input of double type and validate for a positive non-zero number
// (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* number);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int num_of_products);

// 4. Get user input for the details of cat food product
CatFoodInfo getCatFoodInfo(int sku_num);


// 5. Display the formatted table header
void displayCatFoodHeader(void);


// 6. Display a formatted record of cat food data
void displayCatFoodData(int sku_num, double* value, double* weight, int
	calories);


// 7. Logic entry point
void start();