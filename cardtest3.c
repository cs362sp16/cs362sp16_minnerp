#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"


/******************************************************
 *
 * Test adventurer
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
	int i;

	initializeGame (3, k, 1, new);

	printf ("TESTING adventurer card\n");

	myAssert (5, new->deckCount[0]);

	new->hand[0][0] = adventurer;
	for (i = 0; i < 10; i++)
		new->deck[0][i] = outpost;
	new->deck[0][2] = copper;
	new->deck[0][4] = gold;

	playCard (0,0,0,0,new);

	//Check that deck[3] removed, and 2 and 4 added to hand
	myAssert (2, new->deckCount[0]);

	if (failed == 0) printf ("TEST SUCCESSFUL\n");
	
	return 0;
}
