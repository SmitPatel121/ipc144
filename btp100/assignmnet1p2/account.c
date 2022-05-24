/*
  Assignment #1 Milestone #4
  Full name - Jay Girishkumar Patel
  Student ID number - 158741199
  Seneca email address - jgpatel10@gmail.com
  Course section code - ZCC
*/

#define _CRT_SECURE_NO_WARNINGS
#include "commonHelpers.h"
#include "account.h"

void getAccount(struct Account* account)
{

	printf("Account Data: New Record\n");
	printf("----------------------------------------\n");
	printf("Enter the account number: ");
	account->number = getInteger();
	printf("\n");
	printf("Enter the account type (A=Agent | C=Customer): ");
	account->type = getCharOption("AC");


}

void getUserLogin(struct Account* account)
{

	printf("User Login Data Input\n");
	printf("----------------------------------------\n");
	printf("Enter user login (10 chars max): ");
	getCString(account->userlog.username, 1, 10);
	printf("Enter the display name (30 chars max): ");
	getCString(account->userlog.name, 1, 30);
	printf("Enter the password (must be 8 chars in length): ");
	getCString(account->userlog.password, 8, 8);
	printf("\n");
}

void getDemographic(struct Account* account)
{
	int year;
	year = currentYear();
	int min_range = 18;
	int max_range = 110;
	int flag = 0;
	printf("Demographic Data Input\n");
	printf("----------------------------------------\n");
	printf("Enter birth year (current age must be between %d and %d): ", min_range, max_range);
	do
	{
		flag = 0;
		scanf("%d", &account->demo.birthyear);
		if (account->demo.birthyear < year - max_range || account->demo.birthyear > year - min_range)
		{
			printf("ERROR: Value must be between %d and %d inclusive: ", year - max_range, year - min_range);
			flag = 1;
		}

	} while (flag != 0);
	printf("Enter the household Income: $");
	account->demo.income = getPositiveDouble();
	printf("Enter the country (30 chars max.): ");
	getCString(account->demo.country, 1, 30);

}

void updateAccount(struct Account* account)
{
	int select;
	int flag;
	do
	{
		flag = 0;
		printf("Account: %05d - Update Options\n", account->number);
		printf("----------------------------------------\n");
		printf("1) Update account type (current value: %c)\n", account->type);
		printf("2) Login\n");
		printf("3) Demographics\n");
		printf("0) Done\n");
		printf("Selection: ");
		select = getIntFromRange(0, 3);
		if (select == 1)
		{
			printf("\nEnter the account type (A=Agent | C=Customer): ");
			account->type = getCharOption("AC");
			printf("\n");
		}
		else if (select == 2)
		{
			updateUserLogin(account);
			printf("\n");
		}
		else if (select == 3)
		{
			updateDemographic(account);
			printf("\n");
		}
		else
			flag = 1;
	} while (flag == 0);
}

void updateUserLogin(struct Account* account)
{
	int flag = 0;
	do
	{
		flag = 0;
		int select;
		printf("\n");
		printf("User Login: %s - Update Options\n", account->userlog.username);
		printf("----------------------------------------\n");
		printf("1) Display name (current value: %s)\n", account->userlog.name);
		printf("2) Password\n");
		printf("0) Done\n");
		printf("Selection: ");
		select = getIntFromRange(0, 2);

		if (select == 1)
		{

			printf("\nEnter the display name (30 chars max): ");
			getCString(account->userlog.name, 1, 30);
		}
		else if (select == 2)
		{
			printf("\nEnter the password (must be 8 chars in length): ");
			getCString(account->userlog.password, 8, 8);
		}
		else
			flag = 1;
	} while (flag == 0);
}



void updateDemographic(struct Account* account)
{
	int flag = 0;
	do
	{
		flag = 0;
		int select;
		printf("\n");
		printf("Demographic Update Options\n");
		printf("----------------------------------------\n");
		printf("1) Household Income (current value: $%0.2lf)\n", account->demo.income);
		printf("2) Country (current value: %s)\n", account->demo.country);
		printf("0) Done\n");
		printf("Selection: ");
		select = getIntFromRange(0, 2);
		if (select == 1)
		{

			printf("\nEnter the household Income: $");
			account->demo.income = getPositiveDouble();
		}
		else if (select == 2)
		{
			printf("\nEnter the country (30 chars max.): ");
			getCString(account->demo.country, 1, 30);
		}
		else
			flag = 1;
	} while (flag == 0);
}
