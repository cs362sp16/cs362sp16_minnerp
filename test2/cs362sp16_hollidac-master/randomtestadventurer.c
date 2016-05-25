#include <stdlib.h>
#include "util.h"
#include "dominion.h"
#include <time.h>
#include <assert.h>


int main(int argc, char *argv[]){
	struct gameState game;

	int i, j, counter, kingd[10];
	int seed;


	if(!allint(argv, argc, 2)){
		return 0;
	}

	seed = atoi(argv[1]);

	srand(seed);

	for(i = 0; i < 10; i++){
		kingd[i] = rand()%27;
		if(!i)
			continue;
		for(j = i-1; j >= 0; j--){
			if(kingd[i] == kingd[j]){
				i--;
				break;
			}
		}
	}

	game.numPlayers = rand()%MAX_PLAYERS + 1;
	for(i = 0; i < treasure_map; i++){
		game.supplyCount[i] = rand()%100;
		game.embargoTokens[i] = rand()%2;
	}

	game.outpostPlayed = rand()%2;
	game.outpostTurn = rand()%2;
	game.whoseTurn = rand() % game.numPlayers;
	game.phase = rand()%4;
	game.coins = rand()%2;
	game.numActions = rand()%5+1;
	game.numBuys = rand()%5+1;

	for(i = 0; i < game.numPlayers; i++){
		game.handCount[i] = rand()%MAX_HAND;
		for(j = 0; j < game.handCount[i]; j++){
			game.hand[i][j] = rand()%(treasure_map+1);
		}
	}
	for(i = 0; i < game.numPlayers; i++){
		game.deckCount[i] = rand()%MAX_DECK;
		for(j = 0; j < game.deckCount[i]; j++){
			game.deck[i][j] = rand()%(treasure_map+1);
		}
	}
	for(i = 0; i < game.numPlayers; i++){
		game.discardCount[i] = rand()%MAX_DECK;
		for(j = 0; j < game.discardCount[i]; j++){
			game.discard[i][j] = rand()%(treasure_map+1);
		}
	}
	game.playedCardCount = rand()%MAX_DECK;
	for(j = 0; j < game.playedCardCount; j++){
		game.playedCards[j] = rand()%(treasure_map+1);
	}

	

	//Where the actual testing is
	j = 0; // using j as a counter for gold
	for(i = 0; i < game.handCount[game.whoseTurn]; i++){
		if(game.hand[game.whoseTurn][i] >3 && game.hand[game.whoseTurn][i] < 7){
			j++;
		} 
	}
	adventurer_card_f(&game);
	
	counter = 0;
	for(i = 0; i < game.handCount[game.whoseTurn]; i++){
		if(game.hand[game.whoseTurn][i] >3 && game.hand[game.whoseTurn][i] < 7){
			counter++;
		} 
	}

	assert(counter == j+2);

	

	return 0;
}
