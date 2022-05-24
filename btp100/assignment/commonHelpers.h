/*
	==================================================
	Assignment #1 Milestone #2
	==================================================
	Name   : Smit Anjaykumar Patel
	ID     : 104424213 
	Email  : sapatel59@myseneca.ca 
	Section: BTP100NAA
*/

int currentYear(void);  //declaring currentyear as function prototypes .

void clearStandardInputBuffer(void); //declaring clearstandarsInputBuffer as function prototypes  to use in a1ms2.c .

int getInteger(); //function: getInteger getting inputs and displaying error message if an invalid value is entered.

int getPositiveInteger();//function getting positive integer greater then 0.

// declaring getDouble to get valid double value and display error message if an invalid value is entered.
double getDouble();

// declaring getPositiveDouble function to get double value ,getting value greater than 0 and display error when value is zero or less then 0.
double getPositiveDouble();

// declaring getintformrange function to return an integer value and receive 2 argument and display error mesage if it excides the permited range.
int getIntFromRange(int low_bound, int up_bound); // int low and int up are the two arguments in which we will specify the range.


// declaring getcharoption to get character function to get a single character value and validating charater value entered.
char getCharOption(char* f); //declaring f as c string array which represent valid characters.

// declaring void function getcstring to obtain user input for c string value with a length.
void getCString(char* s, int min_value, int max_value);// declaring char s pointer representing a C string , min_value and max_value to represent min and maximum number of character respectively.


// declaring stringrange function to get increamention in character 
int stringrange(char* r);

