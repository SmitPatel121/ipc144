/*
	==================================================
	Assignment #1 Milestone #2
	==================================================
	Name   : Smit Anjaykumar Patel
	ID     : 104424213
	Email  : sapatel59@myseneca.ca
	Section: BTP100NAA
*/

struct Person // declaring structure person
{
	char full_name[32], country[32];
	int year_of_birth;
	double household_income;
};

struct UserLogin // declaring userlogin structure
{
	char full_name[12], User_Password[10]; // char full_name to get full name of consumer
};

struct Account // declaring account structure
{
	int Number; // declaring int number to get unmber of consumer
	char* Consumer_type;
};
