/*
	==================================================
	Workshop #3 (Part-1):
	==================================================
	Name   : Smit Anjaykumar Patel
	ID     : 104424213
	Email  : sapatel59@myseneca.ca
	Section: BTP100NAA.07777.2217
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MIN_YEAR 2010
#define MAX_YEAR 2021

int main(void)
{
	const int JAN = 1; //declaring unmodifiable integer variable

	const int DEC = 12;

	int year = 0; //declaring year and month
        int month = 00;
	

	printf("General Well-being Log\n");
	printf("======================\n");

	

	

	
	do //using do while to apply conditions
	{	
		printf("Set the year and month for the well-being log (YYYY MM): ");

		scanf("%d %d", &year, &month);
		
		if ((year < 2010 || year >2021) && (month < 1 || month >12))
		{
			printf("   ERROR: The year must be between 2010 and 2021 inclusive\n   ERROR: Jan.(1) - Dec.(12)\n");
		}

		else if (year < 2010 || year>2021)
		{
			printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
		}

		else if (month < 1 || month > 12)
		{
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}

		
	}while (2010 > year || year > 2021 ||  month < JAN || month > DEC);
	 
	printf("\n*** Log date set! ***\n");

	if(month==1)      //using if else for printing month alphabatical
    {
        printf("\nLog starting date: %d-JAN-01",year);
    }
    
    else if (month==2)

    {
        printf("\nLog starting date: %d-FEB-01",year);
    }

    else if (month==3)
    {
        printf("\nLog starting date: %d-MAR-01",year);
    }

    else if (month==4)
    {
        printf("\nLog starting date: %d-APR-01",year);
    }

    else if (month==5)
    {
        printf("\nLog starting date: %d-MAY-01",year);
    }

    else if (month==6)
    {    
        printf("\nLog starting date: %d-JUN-01",year);
    }

    else if (month==7)
    {
        printf("\nLog starting date: %d-JUL-01",year);
    }

    else if (month==8)
    {
        printf("\nLog starting date: %d-AUG-01",year);
    }

    else if (month==9)
    {
        printf("\nLog starting date: %d-SEP-01",year);
    }

    else if (month==10)
    {
        printf("\nLog starting date: %d-OCT-01",year);
    }

    else if (month==11)
    {
        printf("\nLog starting date: %d-NOV-01",year);
    }

    else
    {
        printf("\nLog starting date: %d-DEC-01",year);
    }		
	return 0;


}
