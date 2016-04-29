#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"


/******************************************************
 *
 * Test sea hag card
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
	int deckCount1;
	int deckCount2;

	initializeGame (3, k, 1, new);

	printf ("TESTING sea hag card\n");

	new->hand[0][0] = sea_hag;

	deckCount1 = new->deckCount[1];
	deckCount2 = new->deckCount[2];

	playCard (0,0,0,0,new);
	
	// Check that card count is the same
	myAssert (deckCount1, new->deckCount[1]-1);
	myAssert (deckCount2, new->deckCount[2]-1);
	
	// Check that top of deck for other players are curses
	myAssert (curse, new->deck[1][new->deckCount[1]]);
	myAssert (curse, new->deck[2][new->deckCount[2]]);

	//NOTE: Appears other players lose more than one card,
	//      should lose one card and gain curse card.

	if (failed == 0) printf ("TEST SUCCESSFUL\n");
	
	return 0;
}
