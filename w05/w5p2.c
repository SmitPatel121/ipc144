/*
	==================================================
	Workshop #5 (Part-2):
	==================================================
	Name   : Smit Anjaykumar patel
	ID     : 104424213
	Email  : sapatel59@myseneca.ca
	Section: BPT100NAA.07777.2217
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MIN_lIVES 1 //declaring minimum number of lives

#define MAX_LIVES 10

#define MIN_PATH_LENGTH 10 //declaring minimum number of path length

#define MAX_PATH_LENGTH 70

#define MULTIPLE 5

struct PlayerInfo {   //declaring  PlayerInfo structure
	int lives;

	char character_symbol;

	int Number_treasure;

	char history[MAX_PATH_LENGTH];
};

struct GameInfo {  //declaring structure information of Gameinfo
	int move;

	int PathLength;

	char bomb[MAX_PATH_LENGTH];

	char Treasure[MAX_PATH_LENGTH];
};

int main(void)
{
	printf("================================\n");
	printf("         Treasure Hunt!         ");

	printf("\n================================\n");
	printf("\n");
	struct PlayerInfo player;
	player.Number_treasure = 0;

	struct GameInfo game;
	printf("PLAYER Configuration\n");
	printf("--------------------\n");
	printf("Enter a single character to represent the player: ");

	scanf(" %c", &player.character_symbol);
	int flow = 1;
	while (flow)
	{

		printf("Set the number of lives: ");
		scanf("%d", &player.lives);
		flow = player.lives<MIN_lIVES || player.lives>MAX_LIVES;
		if (flow)

		{
			printf("     Must be between 1 and 10!\n");
		}
	}
	printf("Player configuration set-up is complete\n");
	printf("\n");
	printf("GAME Configuration\n");
	printf("------------------\n");
	int k = 1, e = 1;


	while (k){
		printf("Set the path length (a multiple of 5 between 10-70): ");

		scanf("%d", &game.PathLength);

		k = game.PathLength % MULTIPLE != 0 || game.PathLength<MIN_PATH_LENGTH || game.PathLength>MAX_PATH_LENGTH;

		if (k){

			printf("     Must be a multiple of 5 and between 10-70!!!\n");
		}
	}
	int MIN_MOVES = player.lives; 

	int MAX_MOVES;

	MAX_MOVES = 0.75 * game.PathLength;

	while (e){
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &game.move);



		e = game.move<MIN_MOVES || game.move>MAX_MOVES;
		if (e){
			printf("    Value must be between %d and %d\n", MIN_MOVES,
				MAX_MOVES);
		}
	}
	printf("\n");

	printf("BOMB Placement\n");

	printf("--------------\n");

	printf("Enter the bomb positions in sets of 5 where a value\n");

	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");

	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",

		game.PathLength);

	int i, j;

	for (i = 0; i < game.PathLength; i += MULTIPLE)
	{

		printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE);
		for (j = 0; j < MULTIPLE; j++)

		{


			scanf(" %c", &game.bomb[i + j]);

		}

	}

	printf("BOMB placement set\n");

	printf("\n");

	printf("TREASURE Placement\n");

	printf("------------------\n");

	printf("Enter the treasure placements in sets of 5 where a value\n");

	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");

	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n",

		game.PathLength);

	for (i = 0; i < game.PathLength; i += MULTIPLE)

	{

		printf("   Positions [%2d-%2d]: ", i + 1, i + MULTIPLE);

		for (j = 0; j < MULTIPLE; j++)

		{

			scanf(" %c", &game.Treasure[i + j]);

		}

	}


	printf("TREASURE placement set\n");

	printf("\n");

	printf("GAME configuration set-up is complete...\n");

	printf("\n");

	printf("------------------------------------\n");

	printf("TREASURE HUNT Configuration Settings\n");

	printf("------------------------------------\n");

	printf("Player:\n");

	printf("   Symbol     : %c\n", player.character_symbol);

	printf("   Lives      : %d\n", player.lives);

	printf("   Treasure   : [ready for gameplay]\n");

	printf("   History    : [ready for gameplay]\n");

	printf("\n");
	printf("Game:\n");

	printf("   Path Length: %d\n", game.PathLength);

	printf("   Bombs      : ");

	for (i = 0; i < game.PathLength; i++)
	{

		printf("%c", game.bomb[i]);

	}

	printf("\n");

	printf("   Treasure   : ");

	for (i = 0; i < game.PathLength; i++)

	{

		printf("%c", game.Treasure[i]);

	}

	printf("\n");

	printf("\n");

	for (j = 0; j < game.PathLength; j++)

	{

		player.history[j] = '-';

	}

	printf("====================================\n");

	printf("~ Get ready to play TREASURE HUNT! ~\n");

	printf("====================================\n");

	printf("\n");

	printf(" ");

	int n = 0, nextmove = 1, a;

	do{     //applying loop so the game can start 
		a = 1;

		if (n == 0);

		else if (n == 1) {

			printf(" ");
			printf(" ");

			printf("%c", player.character_symbol);

			for (i = n; i < game.PathLength; i++)

			{

				printf(" ");

			}

			printf("\n");

			printf(" ");

		}

		else {

			printf(" ");



			for (i = 1; i < n; i++)

			{

				printf(" ");

			}

			printf(" ");

			printf("%c", player.character_symbol);

			for (i = n; i < game.PathLength; i++)

			{

				printf(" ");



			}

			printf("\n");

			printf(" ");

		}

		printf(" ");

		for (i = 0; i < game.PathLength; i++)

		{

			printf("%c", player.history[i]);

		}

		printf("\n");

		printf("  ");



		for (j = 0; j < game.PathLength; j += 10)

		{

			printf("|||||||||%d", a);

			a++;

		}

		printf("\n");

		printf("  ");



		for (i = 0; i < game.PathLength; i += 10)

		{

			printf("1234567890");

		}

		printf("\n");

		printf("+---------------------------------------------------+\n");

		printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n",

			player.lives, player.Number_treasure, game.move);

		printf("+---------------------------------------------------+\n");

		do

		{

			printf("Next Move [1-%d]: ", game.PathLength);

			scanf("%d", &n);

			nextmove = n < 1 || n > game.PathLength;

			if (nextmove)

				printf("  Out of Range!!!\n");

		} while (nextmove);

		printf("\n");

		if ((player.history[n - 1] == '.') || (player.history[n - 1] ==

			'&')

			|| (player.history[n - 1] == '$') || (player.history[n - 1]

				== '!'))

		{

			printf("===============> Dope! You've been here before!\n");

		}

		else if ((game.bomb[n - 1] == '1') && (game.Treasure[n - 1] ==

			'1')) {

			printf("===============> [&] !!! BOOOOOM !!! [&]\n");

			printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");

			player.lives--;

			game.move--;

			player.Number_treasure++;

			player.history[n - 1] = '&';

		}

		else if (game.bomb[n - 1] == '1') {

			printf("===============> [!] !!! BOOOOOM !!! [!]\n");

			player.lives--;



			game.move--;

			player.history[n - 1] = '!';

		}

		else if (game.Treasure[n - 1] == '1') {

			printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");

			game.move--;

			player.Number_treasure++;

			player.history[n - 1] = '$';

		}

		else {

			printf("===============> [.] ...Nothing found here... [.]\n");

			game.move--;

			player.history[n - 1] = '.';

		}

		printf("\n");

		if (game.move == 0)printf("No more MOVES remaining!\n\n");

		if (player.lives == 0)printf("No more LIVES remaining!\n\n");

	} while ((player.lives != 0) && (game.move != 0));

	a = 1;

	if (n == 0);

	else if (n == 1) {

		printf(" ");

		printf("%c", player.character_symbol);

		for (i = n; i < game.PathLength; i++)

		{

			printf(" ");

		}

		printf("\n");

	}

	else {

		printf(" ");

		for (i = 1; i < n; i++)

		{

			printf(" ");

		}

		printf(" ");

		printf("%c", player.character_symbol);

		for (i = n; i < game.PathLength; i++)

		{

			printf(" ");

		}

		printf("\n");

		printf(" ");

	}

	printf(" ");

	for (i = 0; i < game.PathLength; i++)

	{

		printf("%c", player.history[i]);

	}

	printf("\n");

	printf("  ");

	for (j = 0; j < game.PathLength; j += 10)

	{

		printf("|||||||||%d", a);

		a++;

	}

	printf("\n");

	printf("  ");

	for (i = 0; i < game.PathLength; i += 10)

	{

		printf("1234567890");

	}

	printf("\n");

	printf("+---------------------------------------------------+\n");

	printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n",

		player.lives, player.Number_treasure, game.move);

	printf("+---------------------------------------------------+\n");

	printf("\n");

	printf("##################\n");

	printf("#   Game over!   #\n");

	printf("##################\n");

	printf("\n");

	printf("You should play again and try to beat your score!\n");//succesfully completed the code

	return 0;



}