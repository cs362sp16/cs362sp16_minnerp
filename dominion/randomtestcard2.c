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
	int cardCost;
	int randCard;
	int oldCount;

	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
		     sea_hag, tribute, smithy};

	if (argc != 2) {
		printf ("NEEDS ARGUMENT FOR SEED\n");
		return 0;
	}
	seed = atoi (argv[1]);
	PutSeed (seed);

	printf ("TESTING remodel card\n");
	for (i = 0; i < NUM_TESTS; i++) {

		new = newGame ();

		numPlayers = (int)(Random () * 1000000) % MAX_PLAYERS;

		// Randomly initialize game
		initializeGame (numPlayers, k, (int)(Random () * 1000000), new);

		randCard = ((int)(Random () * 1000)) % 5;
		cardCost = handCard (new->hand[0][randCard], new);
		oldCount = new->deckCount[0];

		cardEffect (remodel, ((int)(Random () * 1000)) % 5, 1, 1, new, 0, NULL);

		// Check that new card is less or equal to 2 more than trashed card
		// Check that handcount is the same
		if ((getCost(handCard (new->hand[0][5], new)) > cardCost+2) ||
		    (oldCount != new->deckCount[0])) {
			printf ("TEST FAILED\n");
			return 0;
		}
			

		free (new);
	}
	printf ("TEST SUCCESSFUL\n");

	return 0;
}
