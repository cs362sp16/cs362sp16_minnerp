#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"


/******************************************************
 *
 * Test endTurn
 *
 ******************************************************/

int failed = 0;

void myAssert (int a, int b) {
	if (a != b) {
		printf ("FAIL: %d\n", a);
		failed = 1;
	}
}

int main () {

	struct gameState *new = newGame ();
	int *k = kingdomCards (1,2,3,4,5,6,7,8,9,10);

	initializeGame (4, k, 1, new);

	printf ("TESTING endTurn\n");

	endTurn (new);
	endTurn (new);
	endTurn (new);

	myAssert (whoseTurn (new), 3);

	endTurn (new);
	endTurn (new);

	myAssert (whoseTurn (new), 1);

	if (failed == 0) printf ("TEST SUCCESSFUL\n");

	return 0;
}
