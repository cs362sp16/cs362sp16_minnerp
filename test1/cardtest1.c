#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"


/******************************************************
 *
 * Test smithy card
 *
 ******************************************************/

int failed = 0;

void myAssert (int a, int b) {
	if (a != b) {
		printf ("FAIL\n");
		failed = 1;
	}
}

int main () {

	struct gameState *new = newGame ();
	int *k = kingdomCards (1,2,3,4,5,6,7,8,9,10);
	int numcards;

	initializeGame (4, k, 1, new);

	printf ("TESTING smithy card\n");

	new->hand[0][0] = smithy;
	numcards = new->handCount[0];
	playCard (0,0,0,0,new);
	
	//Check smithy removed, and three more cards added
	myAssert (new->handCount[0], numcards+2);
	

	if (failed == 0) printf ("TEST SUCCESSFUL\n");
	
	return 0;
}
