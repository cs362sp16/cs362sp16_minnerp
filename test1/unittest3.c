#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"


/******************************************************
 *
 * Test updateCoins
 *
 ******************************************************/

int failed = 0;

void myAssert (int a, int b) {
	if (a != b) {
		printf ("FAIL, num=%d\n", a);
		failed = 1;
	}
}

int main () {

	struct gameState *new = newGame ();
	int *k = kingdomCards (1,2,3,4,5,6,7,8,9,10);

	initializeGame (4, k, 1, new);

	printf ("TESTING updateCoins\n");

	new->coins = 4;
	new->hand[0][0] = copper;
	new->hand[0][1] = silver;
	new->hand[0][2] = gold;
	new->hand[0][3] = copper;
	new->hand[0][4] = copper;

	updateCoins (0, new, 0);

	myAssert (new->coins, 8);

	if (failed == 0) printf ("TEST SUCCESSFUL\n");

	return 0;
}
