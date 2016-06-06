#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"


/******************************************************
 *
 * Test isGameOver
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

	initializeGame (4, k, 1, new);

	printf ("TESTING isGameOver\n");

	//Test game not over
	myAssert (isGameOver (new), 0);

	//Test all province cards taken
	new->supplyCount[province] = 0;
	myAssert (isGameOver (new), 1);

	//Test 3 supply piles empty
	new->supplyCount[2] = 0;
	new->supplyCount[4] = 0;
	new->supplyCount[7] = 0;

	myAssert (isGameOver (new), 1);

	if (failed == 0) printf ("TEST SUCCESSFUL\n");

	return 0;
}
