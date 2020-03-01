#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <algorithm>

using namespace std;

// Structure to hold information like player ID and the cards they are holding
typedef struct player{

int playerID;
int card1;
int card2;

}playerThread;


int deck [52]; // Array to hold cards in the deck

int deckSize; // Variable to hold how many cards are currently in the deck

int winner; // Variable to hold if there is a winner and which player won

// create players
playerThread player1;
playerThread player2;
playerThread player3;

int getCard(){

int card = deck[0]; // give player a card off the top of the deck

// shift cards in deck to leave empty space in array at the end
for (int i = 0; i < deckSize - 1; i++)
    deck[i] = deck[i+1];

deckSize--; // subtract one from the number of cards currently in the deck
return card;
}

void replaceCard(int card){
    deck[deckSize] = card;
    deckSize++;
}

void printDeck(){
    cout << "Deck: ";
    for(int i = 0; i < deckSize; i++)
        cout << deck[i] << " ";

}

void *player_Thread(void* player) {

player->card2 = getCard();

//check to see if player won
if(player->card1 == player->card2){
    // if a player won end game
    cout << "PLAYER " << player->playerID << " WIN: yes\n";
    winner = player->playerID;
}

// if player didn't win continue game

cout << "PLAYER " << player->playerID << " WIN: no\n";

// discard a random card
if (rand() % 2 == 0) {
    cout << "PLAYER " << player->playerID << ": discards " << player->card1 << endl;
    replaceCard(player->card1);
    player->card1 = -1;
}
else{
     cout << "PLAYER " << player->playerID << ": discards " << player->card2 << endl;
    replaceCard(player->card2);
    player->card2 = -1;
}

// Print hand
if (player->card1 != -1)
    cout << "PLAYER " << player->playerID << " HAND: " << player->card1 <<endl;
else
    cout << "PLAYER " << player->playerID << " HAND: " << player->card2 <<endl;

printDeck();

return (void *) NULL;
}

void *player_Thread(void* player);

int main(int argc, char* argv[])
{
    srand (unsigned(time(0)));

    // Creating the threads for each player
    pthread_t* player1Thread;
    pthread_t* player2Thread;
    pthread_t* player3Thread;
    pthread_t* dealerThread;

    pthread_create(&player1Thread, NULL, player_Thread(), (void*) player1Thread);

    player_Thread(void* player1Thread)
    // initialize players
    player1.playerID = 1;
    player1.card1 = -1;
    player1.card2 = -1;

    player2.playerID = 2;
    player2.card1 = -1;
    player2.card2 = -1;

    player3.playerID = 3;
    player3.card1 = -1;
    player3.card2 = -1;

    // Variable to hold what card number is being initialized
    deckSize = 0;

    // loop to initialize the array
    for (int i = 0; i < 4; i++){
        for (int j = 1; j < 14; j++){
            deck[deckSize] = j;
            deckSize++;
        }
    }

printDeck();
random_shuffle(&deck[0], &deck[deckSize]);
cout << endl << endl;
printDeck();

    return 0;
}
