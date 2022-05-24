/*
	==================================================
	Workshop #3 (Part-2):
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
#define LOG_DAYS 3 

int main(void)
{
	const int JAN = 1;          //declaring unmodifiable integer variable

	const int DEC = 12;

	int year = 0;                   //declaring year and month
	int month = 00;
	float morningrating, eveningrating, morningtotal=0, eveningtotal=0 , sum,averageM,averageE,averageT;        //declaring float variables 
	int i ;

	printf("General Well-being Log\n");
	printf("======================\n");






	do           //using do while to apply conditions
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


	} while (2010 > year || year > 2021 || month < JAN || month > DEC);

	printf("\n*** Log date set! ***\n");

	for (i = 1; i <= LOG_DAYS; i++)               //using for loop and initialiasing i=1 and then ingreamenting 1 in every operation and setting condition for i
	 {
		   
	    if(month==1)      //using switch statement to conevrt numerical month to alphabatical form 
    	     {       
	       printf("\n%d-JAN-0%d",year,i);
    	     }
    
    	    else if (month==2)

    	    {
       	       printf("\n%d-FEB-0%d",year,i);
    	    }

    	else if (month==3)
    	{
          printf("\n%d-MAR-0%d",year,i);
    	}

    	else if (month==4)
    	{
          printf("\n%d-APR-0%d",year,i);
    	}

    	else if (month==5)
    	{
         printf("\n%d-MAY-0%d",year,i);
    	}

    	else if (month==6)
    	{    
         printf("\n%d-JUN-0%d",year,i);
    	}

    	else if (month==7)
    	{
         printf("\n%d-JUL-0%d",year,i);
    	}

    	else if (month==8)
    	{
         printf("\n%d-AUG-0%d",year,i);
    	}

    	else if (month==9)
    	{
         printf("\n%d-SEP-0%d",year,i);
    	}

    	else if (month==10)
    	{
         printf("\n%d-OCT-0%d",year,i);
    	}

    	else if (month==11)
    	{
         printf("\n%d-NOV-0%d",year,i);
    	}

    	else
    	{
         printf("\n%d-DEC-0%d",year,i);
    	}


		printf("\n   Morning rating (0.0-5.0): ");
		scanf("%f", &morningrating);

		while (morningrating < 0.0 || morningrating>5.0)                      // using nested loop 
		{
			printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!");
			printf("\n   Morning rating (0.0-5.0): ");
			scanf("%f", &morningrating);
		} 
		morningtotal = morningtotal + morningrating;                      //getting different values of morningtotal

		printf("   Evening rating (0.0-5.0): ");
		scanf("%f", &eveningrating);

		while (eveningrating < 0.0 || eveningrating>5.0)
		{
			printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!");
			printf("\n   Evening rating (0.0-5.0): ");
			scanf("%f", &eveningrating);
		} 
		
		eveningtotal = eveningtotal + eveningrating;                           //getting different values of eveningtotal

	}

	printf("\nSummary\n");
	printf("=======\n");
	printf("Morning total rating: %0.3f\n", morningtotal);
	printf("Evening total rating: %0.3f\n", eveningtotal);
	printf("----------------------------\n");
	
	sum = morningtotal + eveningtotal ;
	printf("Overall total rating: %0.3f\n",sum);

	averageM = morningtotal/3 ;
	printf("\nAverage morning rating:  %.1f\n",averageM);

	averageE = eveningtotal/3 ;
	printf("Average evening rating:  %.1f\n",averageE);

	printf("----------------------------\n");
	averageT = sum/6 ;

	printf("Average overall rating:  %.1f\n",averageT);

	
	return 0;

}
