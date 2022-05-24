/*
	==================================================
	Workshop #5 (Part-1):
	==================================================
	Name   : Smit Anjaykumar patel
	ID     : 104424213
	Email  : sapatel59@myseneca.ca
	Section: BPT100NAA.07777.2217
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MIN_LIVES 1
#define MAX_LIVES 10
#define MIN_PATHLENGTH 10
#define MAX_PATHLENGTH 70
#define MULTIPLE 5

struct playerinfo
{
	char character;
	int lives;
	int od[MAX_PATHLENGTH];


};

struct gameinfo
{
	int pathlength;
	int bomb[MAX_PATHLENGTH];
	int treasure[MAX_PATHLENGTH];
	int move;
};

int main(void)
{
	int flot = 1, limit = 5, i = 0;

	struct playerinfo playerconfiguration = { 0,0,{0} };

	struct gameinfo gameconfiguration = { 0,{0},{0},0 };

	int mx_moves;


	printf("================================\n");

	printf("         Treasure Hunt!         \n");

	printf("================================\n");

	printf("\nPLAYER Configuration\n");

	printf("--------------------\n");

	printf("Enter a single character to represent the player: ");

	scanf("%c", &playerconfiguration.character);

	while (flot)
	{
		printf("Set the number of lives: ");
		scanf("%d", &playerconfiguration.lives);
		if (playerconfiguration.lives  < MIN_LIVES || playerconfiguration.lives > MAX_LIVES)
		{
			printf("     Must be between 1 and 10!\n");

		}
		else
		{
			printf("Player configuration set-up is complete\n");
			flot = 0;
		}
	}

	printf("\nGAME Configuration\n");
	printf("------------------\n");
	flot = 1;

	while (flot)
	{
		printf("Set the path length (a multiple of %d between %d-%d): ", MULTIPLE, MIN_PATHLENGTH, MAX_PATHLENGTH);
		scanf("%d", &gameconfiguration.pathlength);
		if (gameconfiguration.pathlength > MIN_PATHLENGTH || gameconfiguration.pathlength < MAX_PATHLENGTH)
		{
			if (gameconfiguration.pathlength % MULTIPLE == 0){
				flot = 0;
			}
			else{
				printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE, MIN_PATHLENGTH, MAX_PATHLENGTH);
			}
		}
		else{
			printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE, MIN_PATHLENGTH, MAX_PATHLENGTH);
		}
	} 

	flot = 1;

	mx_moves = (gameconfiguration.pathlength * 75) / 100;

	do
	{
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &gameconfiguration.move);
		if (gameconfiguration.move <= mx_moves)
		{
			if (gameconfiguration.move < playerconfiguration.lives)
			{

				printf("    Value must be between %d and %d\n", playerconfiguration.lives, mx_moves);
			}
			else
			{
				flot = 0;
			}
		}
		else
		{
			printf("    Value must be between %d and %d\n", playerconfiguration.lives, mx_moves);
		}
	} while (flot);


	printf("\nBOMB Placement\n");

	printf("--------------\n");

	printf("Enter the bomb positions in sets of 5 where a value\n");

	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");

	printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

	int z;
	for (i = 0; i < gameconfiguration.pathlength; i += 5)
	{
		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);

		for (z = i; z < limit; z++)
		{
			scanf("%d", &gameconfiguration.bomb[z]);
		}
		limit += 5;
	}

	printf("BOMB placement set\n");


	printf("\nTREASURE Placement\n");

	printf("------------------\n");

	printf("Enter the treasure placements in sets of 5 where a value\n");

	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");

	printf("(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");

	limit = 5;

	for (i = 0; i < gameconfiguration.pathlength; i += 5)

	{
		printf("   Positions [%2d-%2d]: ", i + 1, i + 5);

		for (z = i; z < limit; z++)
		{
			scanf("%d", &gameconfiguration.treasure[z]);
		}
		limit += 5;
	}

	printf("TREASURE placement set\n");


	printf("\nGAME configuration set-up is complete...\n");

	printf("\n------------------------------------\n");

	printf("TREASURE HUNT Configuration Settings\n");

	printf("------------------------------------\n");

	printf("Player:\n");

	printf("   Symbol     : %c\n", playerconfiguration.character);

	printf("   Lives      : %d\n", playerconfiguration.lives);

	printf("   Treasure   : [ready for gameplay]\n");

	printf("   History    : [ready for gameplay]\n");

	printf("\nGame:\n");

	printf("   Path Length: %d\n", gameconfiguration.pathlength);

	printf("   Bombs      : ");

	for (i = 0; i < gameconfiguration.pathlength; i++){
		printf("%d", gameconfiguration.bomb[i]);

	}
	printf("\n");
	printf("   Treasure   : ");
	for (i = 0; i < gameconfiguration.pathlength; i++){

		printf("%d", gameconfiguration.treasure[i]);
	}

	printf("\n\n====================================\n");

	printf("~ Get ready to play TREASURE HUNT! ~\n");

	printf("====================================\n");

	return 0;
}