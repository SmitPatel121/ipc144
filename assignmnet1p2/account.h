/*
  Assignment #1 Milestone #4
  Full name - Jay Girishkumar Patel
  Student ID number - 158741199
  Seneca email address - jgpatel10@gmail.com
  Course section code - ZCC
*/

#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#define _CRT_SECURE_NO_WARNINGS

struct Demographic
{
	int birthyear;
	double income;
	char country[31];
}demo;

struct UserLogin
{
	char name[31];
	char username[11];
	char password[9];
}userlog;

struct Account
{
	int number;
	char type;
	struct UserLogin userlog;
	struct Demographic demo;
};

void getAccount(struct Account* account);

void getUserLogin(struct Account* account);

void getDemographic(struct Account* account);

void updateAccount(struct Account* account);

void updateUserLogin(struct Account* account);

void updateDemographic(struct Account* account);





#endif