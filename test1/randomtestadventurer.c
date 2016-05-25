#include <stdio.h>
#include <stdlib.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

/******************************************************
 *
 * Test adventure card
 *
 *****************************************************/

#define NUM_TESTS 10

int main (int argc, char* argv[]) {
	
	struct gameState *new;
	int numPlayers;
	int i;
	long seed;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
		     sea_hag, tribute, smithy};

	if (argc != 2) {
		printf ("NEEDS ARGUMENT FOR SEED\n");
		return 0;
	}
	seed = atoi (argv[1]);
	PutSeed (seed);

	printf ("TESTING adventure card\n");
	for (i = 0; i < NUM_TESTS; i++) {

		new = newGame ();

		numPlayers = (int)(Random () * 1000000) % MAX_PLAYERS;

		// Randomly initialize game
		initializeGame (numPlayers, k, (int)(Random () * 1000000), new);

		cardEffect (adventurer, 1, 1, 1, new, 0, NULL);

		free (new);
	}
	printf ("TEST SUCCESSFUL\n");

	return 0;
}
