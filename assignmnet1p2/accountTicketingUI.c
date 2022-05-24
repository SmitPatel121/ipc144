/*
  Assignment #1 Milestone #4
  Full name - Jay Girishkumar Patel
  Student ID number - 158741199
  Seneca email address - jgpatel10@gmail.com
  Course section code - ZCC
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "accountTicketingUI.h"
#include "account.h"
#include "commonHelpers.h"
#define SIZE 5


void displayAccountSummaryHeader(void)
{
	printf("Acct# Acct.Type Birth\n");
	printf("----- --------- -----\n");
}

void displayAccountDetailHeader(void)
{
	printf("Acct# Acct.Type Birth Income      Country    Disp.Name       Login      Password\n");
	printf("----- --------- ----- ----------- ---------- --------------- ---------- --------\n");
}

void displayAccountSummaryRecord(const struct Account* accounts)
{
	printf("%05d %-9s %5d\n", accounts->number, accounts->type == 'A' ? "AGENT" : "CUSTOMER", accounts->demo.birthyear);
}
void displayAccountDetailRecord(const struct Account* accounts)
{
	int i = 0;
	char password[15];
	for (i = 0; i < 9; i++)
	{
		password[i] = accounts->userlog.password[i];
	}
	for (i = 1; i < 9; i += 2)
	{
		password[i] = '*';
	}


	printf("%05d %-9s %5d $%10.2lf %-10s %-15s %-10s %-8s\n", accounts->number, accounts->type == 'A' ? "AGENT" : "CUSTOMER", accounts->demo.birthyear, accounts->demo.income, accounts->demo.country, accounts->userlog.name, accounts->userlog.username, password);
}

void applicationStartup(struct Account accounts[], int max)
{
	int Z = 0;
	int flag = 0;
	do
	{
		Z = menuLogin(accounts, max);

		
		if (Z < 0)
		{
			printf("\n==============================================\n");
			printf("Account Ticketing System - Terminated\n");
			printf("==============================================\n");
			flag = 1;
		}
		else
		{
			if (accounts[Z].type == 'C')
			{
				printf("\nCUSTOMER: home menu currently unavailable...\n\n");
				pauseExecution();
			}
			else
			{
				printf("\n");
				menuAgent(accounts, SIZE, &accounts[Z]);
			}
		}
	} while (flag == 0);

}

int menuLogin(const struct Account accounts[], int max)
{
	int select;
	int number;
	
	int flag = 0;
	int x;
	int Z = 0;
	do
	{
		
		printf("==============================================\n");
		printf("Account Ticketing System - Login\n");
		printf("==============================================\n");
		printf("1) Login to the system\n");
		printf("0) Exit application\n");
		printf("----------------------------------------------\n");
		printf("\n");
		printf("Selection: ");

		select = getIntFromRange(0, 1);
		//()
		if (select == 1)
		{
			printf("\nEnter your account#: ");
			number = getInteger();
			Z = findAccountIndexByAcctNum(number, accounts, SIZE, &Z);
			if (Z >= 0)
			{
				flag = 1;
			}
			else
			{
				printf("\nERROR: Access Denied.\n\n");
				pauseExecution();
			}
		}
		else
		{
			printf("\nAre you sure you want to exit? ([Y]es|[N]o): ");
			x = getCharOption("yYnN");
			if (x == 'n' || x == 'N')
			{
				printf("\n");
			}
			else
			{
				Z = -1;
				flag = 1;
			}
		}

	} while (flag == 0);
	return Z;
}

void menuAgent(struct Account accounts[], int max, const struct Account* acc)
{
	int select;
	int flag = 0;
	int NEW = 0;
	do
	{
		printf("AGENT: %s (%d)\n", acc->userlog.name, acc->number);
		printf("==============================================\n");
		printf("Account Ticketing System - Agent Menu\n");
		printf("==============================================\n");
		printf("1) Add a new account\n");
		printf("2) Modify an existing account\n");
		printf("3) Remove an account\n");
		printf("4) List accounts: summary view\n");
		printf("5) List accounts: detailed view\n");
		printf("----------------------------------------------\n");
		printf("0) Logout\n");
		printf("\n");
		printf("Selection: ");
		select = getIntFromRange(0, 5);
		printf("\n");
		if (select == 1)
		{
			if (SIZE + NEW <= SIZE)
			{
				getAccount(&accounts[SIZE + NEW]);
				printf("\n");
				getUserLogin(&accounts[SIZE + NEW]);
				getDemographic(&accounts[SIZE + NEW]);
				printf("\n*** New account added! ***\n\n");
				pauseExecution();
				printf("\n");
				NEW++;
			}
			else
			{
				printf("ERROR: Account listing is FULL, call ITS Support!\n\n");
				pauseExecution();
			}
		}
		else if (select == 2)
		{
			int accnumber;
			int Z = 0;
			printf("Enter your account#: ");
			accnumber = getInteger();
			Z = findAccountIndexByAcctNum(accnumber, accounts, SIZE + NEW, &Z);
			if (Z >= 0)
			{
				printf("\n");
				updateAccount(&accounts[Z]);
				printf("\n");
			}
		}
		else if (select == 3)
		{
			int accnumber;
			printf("Enter your account#: ");
			accnumber = getInteger();
			if (acc->number == accnumber)
			{
				printf("\nERROR: You can't remove your own account!\n\n");
				pauseExecution();
			}
			else
			{
				int Z = 0;
				int x;
				Z = findAccountIndexByAcctNum(accnumber, accounts, SIZE + NEW, &Z);
				if (Z >= 0)
				{
					displayAccountDetailHeader();
					displayAccountDetailRecord(&accounts[Z]);
					printf("\nAre you sure you want to remove this record? ([Y]es|[N]o): ");
					x = getCharOption("YN");
					if (x == 'N')
					{
						printf("\n*** No changes made! ***\n\n");
						pauseExecution();
					}
					else
					{
						accounts[Z].number = 0;
						printf("\n*** Account Removed! ***\n\n");
						pauseExecution();
					}
				}
			}
		}
		else if (select == 4)
		{
			displayAllAccountSummaryRecords(accounts, SIZE + NEW);
			pauseExecution();
		}
		else if (select == 5)
		{
			displayAllAccountDetailRecords(accounts, SIZE + NEW);
			pauseExecution();
		}
		else
		{
			printf("### LOGGED OUT ###\n\n");
			flag = 1;
		}
	} while (flag == 0);
}

int findAccountIndexByAcctNum(int accNo, const struct Account accounts[], int max, int *Z)
{
	int n = 0;
	int i = 0;
	for (i = 0; i < max; i++)
	{
		if (accNo == accounts[i].number)
		{
			n++;
			*Z = i;
			break;
		}
		else
		{
			*Z = -1;
		}

	}
	return *Z;
}

void displayAllAccountSummaryRecords(const struct Account accounts[], int max)
{
	int i = 0;

	displayAccountSummaryHeader();
	for (i = 0; i <= max; i++)
	{
		if (accounts[i].number > 0)
		{
			displayAccountSummaryRecord(&accounts[i]);
		}
	}
	printf("\n");
}

void displayAllAccountDetailRecords(const struct Account accounts[], int max)
{
	int i = 0;

	displayAccountDetailHeader();
	for (i = 0; i <= max; i++)
	{
		if (accounts[i].number > 0)
		{
			displayAccountDetailRecord(&accounts[i]);
		}
	}
	printf("\n");
}

void pauseExecution(void)
{
	printf("<< ENTER key to Continue... >>");
	clearStandardInputBuffer();
	putchar('\n');
}
