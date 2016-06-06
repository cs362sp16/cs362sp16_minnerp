#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"


/******************************************************
 *
 * Test numHandCards
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

	initializeGame (1, k, 1, new);
	new->handCount[0] = 3;

	printf ("TESTING numHandCards\n");

	myAssert (numHandCards (new), 3);

	if (failed == 0) printf ("TEST SUCCESSFUL\n");
	
	return 0;
}
