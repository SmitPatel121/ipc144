/*
  Assignment #1 Milestone #4
  Full name - Jay Girishkumar Patel
  Student ID number - 158741199
  Seneca email address - jgpatel10@gmail.com
  Course section code - ZCC
*/
#ifndef ACCOUNTTICKETINGUI_H_
#define ACCOUNTTICKETINGUI_H_
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "commonHelpers.h"
#include "account.h"

void displayAccountSummaryHeader(void);

void displayAccountDetailHeader(void);

void displayAccountSummaryRecord(const struct Account* accounts);

void displayAccountDetailRecord(const struct Account* accounts);

void applicationStartup(struct Account accounts[], int max);

int menuLogin(const struct Account accounts[], int max);

void menuAgent(struct Account accounts[], int max, const struct Account* acc);

int findAccountIndexByAcctNum(int accNo, const struct Account accounts[], int max, int *Z);

void displayAllAccountSummaryRecords(const struct Account accounts[], int max);

void displayAllAccountDetailRecords(const struct Account accounts[], int max);

void pauseExecution(void);






#endif