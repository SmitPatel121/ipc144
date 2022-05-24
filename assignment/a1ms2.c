/*
    ==================================================
    Assignment #1 Milestone #2
    ==================================================
    Name   : Smit Anjaykumar Patel
    ID     : 104424213
    Email  : sapatel59@myseneca.ca
    Section: BTP100NAA
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "account.h"                                    
#include "commonHelpers.h"                              

  // ------------------------------------------------------------------
  // Function Prototypes:


  // Confirm MS1 stuff still works and grades can be applied to MS1
void commonHelpersTest(void);

// Display Account details                               
void displayAccount(const struct Account account, const struct UserLogin login, const struct Person person);

// ------------------------------------------------------------------
// Main entry point to application:

int main(void)
{
    struct Account account = { 0 };

    struct Person person = { { 0 } };

    struct UserLogin login = { { 0 } };
    // Declare other variables you may need here:
    char Consumer_type;


    printf("Assignment 1 Milestone 2\n");
    printf("=============================================\n\n");

    // ---------------------------------------------------------
    // Confirm MS1 deliverables; apply grade to MS1 accordingly
    // ---------------------------------------------------------
    commonHelpersTest();

    // ---------------------------------------------------------
    // Account Data: get user input
    // ---------------------------------------------------------
    printf("Account Data Input\n");
    printf("----------------------------------------\n");

    // Add the necessary code to get user input for each Account member:
    printf("Enter the account number: ");

    account.Number = getPositiveInteger();

    printf("Enter the account type ");

    printf("(A=Agent | C=Customer): ");

    Consumer_type = getCharOption("AC"); //using consumer_type pre defined function
    {
        if (Consumer_type == 'A'){

            account.Consumer_type = "AGENT";
        }

        if (Consumer_type == 'C')
        {
            account.Consumer_type = "CUSTOMER";
        }
    }
    printf("\n");

    // ---------------------------------------------------------
    // Person Data: get user input
    // ---------------------------------------------------------

    printf("Person Data Input\n");

    printf("----------------------------------------\n");

    // Add the necessary code to get user input for each Person member:
    // NOTE: You will need to get the CURRENT YEAR to devise the appropriate range
    // when prompting for the birth year data.  There is a function in the 
    // commonHelpers library that gives you this!

    printf("Enter the person'");

    printf("s full name (30 chars max): ");

    getCString(person.full_name, 10, 30);

    printf("Enter birth year ");
    printf("(current age must be between 18 and 110): ");

    person.year_of_birth = getIntFromRange(currentYear() - 110, currentYear() - 18);

    printf("Enter the household Income: $");

    person.household_income = getPositiveDouble();

    printf("Enter the country (30 chars max.): ");

    getCString(person.country, 2, 30);

    printf("\n");


    // ---------------------------------------------------------
    // UserLogin Data: get user input
    // ---------------------------------------------------------
    printf("User Login Data Input\n");

    printf("----------------------------------------\n");

    // Add the necessary code to get user input for each UserLogin member:
    printf("Enter user login (10 chars max): ");

    getCString(login.full_name, 6, 10);

    printf("Enter the password ");

    printf("(must be 8 chars in length): ");

    getCString(login.User_Password, 8, 8);

    printf("\n");


    // Display all the entered data
    // ---------------------------------------------------------

    // Call function to display the Account record:
    displayAccount(account, login, person);

    printf("\nAssignment #1 Milestone #2 completed!\n");
    return 0;
}

// ------------------------------------------------------------------
// Function definitions:
// Display Account details: Add the missing code!
void displayAccount(const struct Account account, const struct UserLogin login, const struct Person person)
{
    printf("Acct# Acct.Type Full Name       Birth Income      Country    Login      Password\n");

    printf("----- --------- --------------- ----- ----------- ---------- ---------- --------\n");

    // Display the respective data to align to the table header above:
    printf("%05d %-9s %-15s %5d %11.2lf %-10s %-10s %8s\n", account.Number, account.Consumer_type, person.full_name, person.year_of_birth,
        person.household_income, person.country, login.full_name, login.User_Password);

}

// Confirm MS1 stuff still works and grades can be applied to MS1

void commonHelpersTest(void)
{
    int vaue_int;
    double value_double;
    char character_value, charstring_value[7];

    // ---------------------------------------------------------------------
    // TEST #1

    printf("TEST #1 - Instructions:\n"
        "1) Enter the word 'error'  [ENTER]\n"
        "2) Enter the number '-100' [ENTER]\n"
        ":>");
    vaue_int = getInteger();

    printf("////////////////////////////////////////\n");

    printf("TEST #1 RESULT: ");

    if (vaue_int == -100)
    {
        printf("*** PASS *** \n");
    }

    else
    {
        printf("### FAILED ###\n");
    }

    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #2
    printf("TEST #2 - Instructions:\n"
        "1) Enter the number '-100' [ENTER]\n"
        "2) Enter the number '200'  [ENTER]\n"
        ":>");

    vaue_int = getPositiveInteger();

    printf("////////////////////////////////////////\n");

    printf("TEST #2 RESULT: ");

    if (vaue_int == 200)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }

    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #3
    printf("TEST #3 - Instructions:\n"
        "1) Enter the word 'error' [ENTER]\n"
        "2) Enter the number '-4'  [ENTER]\n"
        "3) Enter the number '12'  [ENTER]\n"
        "4) Enter the number '-3'  [ENTER]\n"
        ":>");
    vaue_int = getIntFromRange(-3, 11);

    printf("////////////////////////////////////////\n");

    printf("TEST #3 RESULT: ");

    if (vaue_int == -3)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #4
    printf("TEST #4 - Instructions:\n"
        "1) Enter the number '14' [ENTER]\n"
        ":>");
    vaue_int = getIntFromRange(-40, 14);

    printf("////////////////////////////////////////\n");
    printf("TEST #4 RESULT: ");
    if (vaue_int == 14)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #5
    printf("TEST #5 - Instructions:\n"
        "1) Enter the word 'error'     [ENTER]\n"
        "2) Enter the number '-150.75' [ENTER]\n"
        ":>");
    value_double = getDouble();

    printf("////////////////////////////////////////\n");
    printf("TEST #5 RESULT: ");
    if (value_double == -150.75)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #6
    printf("TEST #6 - Instructions:\n"
        "1) Enter the number '-22.11' [ENTER]\n"
        "2) Enter the number '225.55' [ENTER]\n"
        ":>");
    value_double = getPositiveDouble();

    printf("////////////////////////////////////////\n");
    printf("TEST #6 RESULT: ");
    if (value_double == 225.55)
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #7
    printf("TEST #7 - Instructions:\n"
        "1) Enter the character 'R' [ENTER]\n"
        "2) Enter the character 'p' [ENTER]\n"
        "3) Enter the character 'r' [ENTER]\n"
        ":>");
    character_value = getCharOption("qwerty");

    printf("////////////////////////////////////////\n");
    printf("TEST #7 RESULT: ");
    if (character_value == 'r')
    {
        printf("*** PASS *** \n");
    }
    else
    {
        printf("### FAILED ###\n");
    }
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #8
    printf("TEST #8: - Instructions:\n"
        "1) Enter the word 'horse'  [ENTER]\n"
        "2) Enter the word 'SENECA' [ENTER]\n"
        ":>");
    getCString(charstring_value, 6, 6);

    printf("////////////////////////////////////////\n");
    printf("TEST #8 RESULT: ");
    printf("%s (Answer: SENECA)\n", charstring_value);
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #9
    printf("TEST #9: - Instructions:\n"
        "1) Enter the words 'Seneca College' [ENTER]\n"
        "2) Enter the word 'IPC'             [ENTER]\n"
        ":>");
    getCString(charstring_value, 3, 6);

    printf("////////////////////////////////////////\n");
    printf("TEST #9 RESULT: ");
    printf("%s (Answer: IPC)\n", charstring_value);
    printf("////////////////////////////////////////\n\n");

    // ---------------------------------------------------------------------
    // TEST #10
    printf("TEST #10: - Instructions:\n"
        "1) Enter the word 'ipc'    [ENTER]\n"
        "2) Enter the word 'SCHOOL' [ENTER]\n"
        ":>");
    getCString(charstring_value, 4, 6);

    printf("////////////////////////////////////////\n");
    printf("TEST #10 RESULT: ");
    printf("%s (Answer: SCHOOL)\n", charstring_value);
    printf("////////////////////////////////////////\n\n");

}