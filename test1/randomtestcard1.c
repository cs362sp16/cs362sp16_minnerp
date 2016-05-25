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
	int handCount;
	int buyCount;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
		     sea_hag, tribute, smithy};

	if (argc != 2) {
		printf ("NEEDS ARGUMENT FOR SEED\n");
		return 0;
	}
	seed = atoi (argv[1]);
	PutSeed (seed);

	printf ("TESTING councilRoom card\n");
	for (i = 0; i < NUM_TESTS; i++) {

		new = newGame ();

		numPlayers = (int)(Random () * 1000000) % MAX_PLAYERS;

		// Randomly initialize game
		initializeGame (numPlayers, k, (int)(Random () * 1000000), new);

		new->deckCount[0] = (int)(Random () * 1000000) % (MAX_DECK / 3);

		new->discardCount[0] = (int)(Random () * 1000000) % (MAX_DECK / 3);
		new->handCount[0] = (int)(Random () * 1000000) % (MAX_HAND / 3);

		handCount = new->handCount[0];
		buyCount = new->numBuys;

		cardEffect (council_room, 1, 1, 1, new, 0, NULL);

		// Check new values are correct
		if (((handCount + 3) != new->handCount[0]) ||
		    ((buyCount + 1) != new->numBuys)) {
			printf ("TEST FAILED\n");
			return 0;
		}

		free (new);
	}
	printf ("TEST SUCCESSFUL\n");

	return 0;
}
