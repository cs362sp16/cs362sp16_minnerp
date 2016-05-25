#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char **argv) {
	struct gameState *g;
	int k[10];
	int i;
	int j;
	int taken;
	int player;
	int card;
	int numPlayers;
	int myPlayers[4];
	srand (atoi (argv[1]));

	g = newGame ();
	
	// Get random kingdom cards
	for (i = 0; i < 10; i++) {
		taken = 0;
		k[i] = (rand () % 20) + 7;
		for (j = 0; j < i; j++) {
			if (k[j] == k[i])
				taken = 1;
		}
		if (taken == 1)
			i--;
	} 
	
	numPlayers = (rand () % 3) + 2;

	// Initialize game with random players and seed
	initializeGame (numPlayers, k, rand (), g);

	// Play the game       
	while (!isGameOver (g)) {
		player = whoseTurn (g);

		// Print information about game
		printf ("Player %d has %d cards\n", player, g->handCount[player]);
		printf ("player %d has %d discards\n", player, g->discardCount[player]);
		printf ("Number of played cards: %d\n", g->playedCardCount);

		// Play a random card
		card = rand () % g->handCount[player];
		if (playCard (card, rand () % 5, rand () % 5, rand () % 5, g) < 0)
			printf ("Player %d unable to play card %d\n", 
				player ,g->hand[player][card]);
		else
			printf ("Player %d played card %d\n",
				player, g->hand[player][card]);

		// Buy new card
		card = rand () % 27;

		if (buyCard (card, g) < 0) 
			printf ("Player %d could not buy card %d\n", player, card);
		else
			printf ("Player %d bought card %d\n", player, card);
		
		endTurn (g);
	}
	
	getWinners (myPlayers, g);
	
	player = 0;
	for (i = 0; i < 4; i++) {
		if (myPlayers[player] < myPlayers[i])
			player = i;
	}
	printf ("Winner is %d\n", player);

	return 0;
}
