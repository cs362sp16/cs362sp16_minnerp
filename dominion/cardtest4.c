#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"


/******************************************************
 *
 * Test village card
 *
 ******************************************************/

int failed = 0;

void myAssert (int a, int b) {
	if (a != b) {
		printf ("FAIL: %d\n", b);
		failed = 1;
	}
}

int main () {

	struct gameState *new = newGame ();
	int *k = kingdomCards (1,2,3,4,5,6,7,8,9,10);
	int numCards;
	int numActions;

	initializeGame (3, k, 1, new);

	printf ("TESTING village card\n");

	new->hand[0][0] = village;
	numCards = new->handCount[0];
	numActions = new->numActions;
	playCard (0,0,0,0,new);

	// Check card has been added and old card removed
	myAssert (numCards, new->handCount[0]);

	// Check have 2 more actions
	myAssert (numActions+1, new->numActions);

	if (failed == 0) printf ("TEST SUCCESSFUL\n");
	
	return 0;
}
