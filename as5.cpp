#include <iostream>
#include <iomanip>
#include "cardDeckType.h"

using namespace std;

int main (int argc,  char * argv[]) {
	// defineing all variables to be used //
	int currentTableCard = 0;
	int cardsRemaining();
	int p1c1 = 0;
	int p1c2 = 0;
	int p1c3 = 0;
	int p2c1 = 0;
	int p2c2 = 0;
	int p2c3 = 0;
	int player1Total;
	int player2Total;	
	int tableCard_r1 = 0 ;
	int tableCard_r2 = 0;
	int tableCard_r3 = 0;
	int tableCard_r4 = 0;
	int tableCard_r5 = 0; 
	int roundNum = 0;
	// set the card deck type to set enumerated value //
	cardDeckType deck;
	// reinitializes deck cards to default, cards unshuffled //
	deck.initDeck();
	// when an argument like ./a.out d is presented the argument is greater than one and prompts the user //
	if( argc > 1 ) {

	cout << "Mateusz Bieda" << endl;
       	cout << "Prompts user for card game selection, outputs game";
	cout << "with cards played in many ways specifically selected" << endl;	
	// Game Header //
	cout << "------------------------------------------" << endl;
	cout << "Welcome to the Lunch Time Dessert 333 Game" << endl;
	cout << "------------------------------------------" << endl;
	
	cout << endl;
	// Game Mode Selection Header //
	cout << "Test Bench Menu" << endl;
	cout << "1 - Normal Game" << endl;
	cout << "2 - Duplicate Table Cards" << endl;
	cout << "3 - Tie Score 0" << endl;
	cout << "4 - Tie Score 3" << endl;
	cout << "5 - Tie Score 33" << endl;
	cout << "6 - Tie Score Other" << endl;
	cout << "Player 1 Win" << endl;
	cout << "Player 2 Win" << endl;

	} 
	// Allows the user to make a selection //
	char userInput;

	cout << endl;

	cout << "Your Selection: ";
	cin >> userInput;

	cout << endl;
	// Switch statements take user input to output desired game mode //
	switch (userInput) {
	 
	case '1':
		cout << "Normal: ";
		cout << "Starts the card deck in the standard mode";
		cout << " The shuffle is based on Fisher Yates" << endl;

	deck.setDeck(NORMAL);
		
		deck.shuffle(); 
		tableCard_r1 = currentTableCard;	
		break;

	case '2':
		cout << "Duplicate: ";
		cout << "Creates duplicate cards for each round,";
		cout << "and the cards should total to zero" << endl;
		
	deck.setDeck(DUPLICATE);
		tableCard_r2 = currentTableCard;
		break;

	case '3':
		cout << "Tie 0: " ;
		cout << "Creates a player tie that ends with both" ;
		cout << "players having a total of zero" << endl;
		
	deck.setDeck(TIE0);
		tableCard_r3 = currentTableCard;
		break;

	case '4':
		cout << "Tie 3: ";
		cout << "Creates a deck that produces a tie with" ;
		cout << "both players tied at a total of three" << endl;
		
	deck.setDeck(TIE3);
		tableCard_r4 = currentTableCard;

	break;
	
	case '5':
		cout << "Tie 33: ";
		cout << "Produces a player tie with both players";
		cout << "totaling of thirty-three" << endl;

	deck.setDeck(TIE33);
		tableCard_r5 = currentTableCard;
	break;

	case '6':
		cout << "Tie Other: ";
		cout << "Produces a player tie with both players";
		cout << "having the same value that is not zero";
		cout << "three or thirty-three" << endl;

	deck.setDeck(TIE_OTHER);

	break;
	
	case '7':
		cout << "Player 1 Win: ";
		cout << "Sets the deck to produce the player";
		cout << "1 win" << endl;
		
	deck.setDeck(PLAYER1_WIN);
	
	break;

	case '8':
		cout << "Player 2 Win: ";
		cout << "Sets the deck to produce the player" ;
		cout << "2 win" << endl;

	deck.setDeck(PLAYER2_WIN);

	break;
	// in case the user misclicks and puts something not allowed //
	default: 
		cout << "Invalid Entry" << endl;

	break;

}// sets up the deck of cards to be drawn and to be displayed//
	p1c1 = deck.drawCard();
	p1c2 = deck.drawCard();
	p1c3 = deck.drawCard();
	p2c1 = deck.drawCard();
	p2c2 = deck.drawCard();
	p2c3 = deck.drawCard();
	/* to set a limit to teh number or rounds allowed, while loop
 	creates 6 rounds of card games as demanded by the assingnment*/
	while (roundNum < 5) {
	currentTableCard = deck.drawCard();
	// adds up card totals to be output to user at end of game //
	player1Total = p1c1 + p1c2 + p1c3;

	player2Total = p2c1 + p2c2 + p2c3;
	// increases the round number to match the cards that are set out
	// in correspondence to assignment requirements //
	roundNum = roundNum + 1;

	cout << endl;

	cout << fixed;
	// creates the layout for how the game is shown to player //
	cout << left << setw(3) << "Player 1: "
	<< right << setw(3) << p1c1
	<< right << setw(3) << p1c2
	<< right << setw(3) << p1c3
	<< right << setw(3) << " Total: " 
	<< right << setw(3) << player1Total << endl;

	cout << left << setw(3) << "Player 2: "
	<< right << setw(3) << p2c1
	<< right << setw(3) << p2c2
	<< right << setw(3) << p2c3
	<< right << setw(3) << " Total: "
	<< right << setw(3) << player2Total << endl;

	cout << endl;
	// broadcasts round as well as table card number that is generated //
	cout << left << "Round" << roundNum << endl;
	cout << endl;
	cout << left << "-----------------------------" << endl;
	cout << left << "Table card is " << currentTableCard << endl;
	// if there is a duplicate the code below should remove the card
	// and set  that number space to zero //	
	if (currentTableCard == p1c1) {
		p1c1 = 0;
}
	if (currentTableCard == p1c2) {
		p1c2 = 0;
}
	if (currentTableCard == p1c3) {
		p1c3 = 0;
}
	if (currentTableCard == p2c1) {
		p2c1 = 0;
}
	if (currentTableCard == p2c2) {
		p2c2 = 0;
}
	if (currentTableCard == p2c3) {
		p2c3 = 0;
}
}
	// out puts the total points of the player from the cards added //
	cout << "Player 1's Total: " << player1Total << endl;
	cout << "Player 2's Total: " << player2Total << endl;
	if (player1Total > player2Total) {
	cout << "Game Result Player 1 gets the goodies" << endl;
	cout << endl;
	}
	if ( player2Total > player1Total) {
	cout << "Game Result Player 2 gets the goodies" << endl;
	cout << endl;
	}
	if (player2Total == player1Total){
	cout << "Game Result -TIE- You have to split the goodies" << endl;
	cout << endl;	
} 
	return 0;
}


