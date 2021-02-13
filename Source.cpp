#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void playerInput();
void bettingMenu();
void playerSelect();
bool gameoverCheck();
bool roundoverCheck();
void displayTable();
void shuffleCards();
void initiateCards();
void calculatePoints();
void dealerTurn();
void playerTurn();

int ranslow1 = 50000000;
int playerAce = 0;
int dealerAce = 0;
int roundCount = 1;
int ranslow2 = 9;
int deckPosition = 0;
int bettingChoice = 1;
int playersHandPosition = 0;
int dealersHandPosition = 0;
int playersPoints = 0;
int dealersPoints = 0;
int bet = 10;
int *realDeckArr;
int playersHand[21];
int dealersHand[21];
int money = 10;
int decks = 1;
int ran;
int cards;
int tempArr;
bool skip = false;
bool gameover = false;
bool roundover = false;
string clear = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

int main(){
	srand(time(0));
	for (int i = 0; i < 21; i++){
		playersHand[i] = 0;
		dealersHand[i] = 0;
	}
	cout << clear;
	bool quitChoice = false;
	do {
		realDeckArr = 0;
		int mainMenuChoice = 1;
		do{
			cout << clear;
			if (money == -1){
				money = 10;
				roundCount = 1;
			}
			cout << "			---Blackjack Simulator---" << endl;
			cout << "1. Play" << endl;
			cout << "2. About" << endl;
			cout << "3. Quit" << endl;
			cout << "4. Delay Settings" << endl;
			if (mainMenuChoice < 1 || mainMenuChoice > 4)
				cout << "Error: not a menu choice!" << endl;
			cout << ": ";
			cin >> mainMenuChoice;
			cin.ignore(100000, '\n');
		} while (mainMenuChoice < 1 || mainMenuChoice > 4);

		switch (mainMenuChoice){

		case 1:{
			cout << clear;
			playerInput();
			initiateCards();
			playerSelect();
			delete[] realDeckArr;
			break;
		}

		case 2:{
			cout << clear;
			cout << "           ---About---" << endl;
			cout << "This blackjack simulator was made" << endl;
			cout << "Hunter Boleman on April 21st 2015." << endl;
			cout << "  As final Project for CSCI 1081" << endl;
			cout << "   Century College Minnesota." << endl;
			cout << "-----------------------------------" << endl;
			cout << "Press enter to return to main menu...";
			cin.get();
			break;
		}

		case 3:{
			cout << clear;
			int quitMenuChoice = 2;
			do{
				cout << "Are You sure you want to quit?" << endl;
				cout << "1. Yes" << endl;
				cout << "2. No" << endl;
				if (quitMenuChoice < 1 || quitMenuChoice > 2)
					cout << "Error: not a menu choice!" << endl;
				cout << ": ";
				cin >> quitMenuChoice;
				cin.ignore(100000, '\n');
			} while (quitMenuChoice < 1 || quitMenuChoice > 2);

			switch (quitMenuChoice){
			case 1:{
				quitChoice = true;
				cout << "Bye!";
				break;
			}
			case 2:{
				quitChoice = false;
				break;
			}
			}
			if (quitChoice == true)
				return 0;
			break;
		}
		case 4:{
			do{
				cout << clear;
				cout << "The current delay setting is: " << ranslow1 << endl;
				cout << "Please enter new setting to slow or speed up pauses in the game." << endl;
				if (ranslow1 < 0)
					cout << "Error: value must be 0 or greater." << endl;
				cout << ": ";
				cin >> ranslow1;
				cin.ignore(100000, '\n');
			} while (ranslow1 < 0);
			cout << clear;
			cout << "TEST" << endl << endl;
			for (int i = 0; i < ranslow1; i++){
				ran = rand() % (ranslow2);
			}
			cout << "TEST" << endl << endl;
			for (int i = 0; i < ranslow1; i++){
				ran = rand() % (ranslow2);
			}
			cout << "TEST" << endl << endl;
			for (int i = 0; i < ranslow1; i++){
				ran = rand() % (ranslow2);
			}
			cout << "\nPress enter to return to the Main Menu.";
			cin.get();
			break;
		}


		}
	} while (quitChoice != true);
}

void initiateCards(){
	cout << "Initializing Deck..." << endl;
	cards = (decks * 52);
	realDeckArr = new int[cards];
	for (int i = 0, j = 0; i < decks; i++){
		*(realDeckArr + j) = 88;
		j++;
		*(realDeckArr + j) = 88;
		j++;
		*(realDeckArr + j) = 88;
		j++;
		*(realDeckArr + j) = 88;
		j++;
		*(realDeckArr + j) = 2;
		j++;
		*(realDeckArr + j) = 2;
		j++;
		*(realDeckArr + j) = 2;
		j++;
		*(realDeckArr + j) = 2;
		j++;
		*(realDeckArr + j) = 3;
		j++;
		*(realDeckArr + j) = 3;
		j++;
		*(realDeckArr + j) = 3;
		j++;
		*(realDeckArr + j) = 3;
		j++;
		*(realDeckArr + j) = 4;
		j++;
		*(realDeckArr + j) = 4;
		j++;
		*(realDeckArr + j) = 4;
		j++;
		*(realDeckArr + j) = 4;
		j++;
		*(realDeckArr + j) = 5;
		j++;
		*(realDeckArr + j) = 5;
		j++;
		*(realDeckArr + j) = 5;
		j++;
		*(realDeckArr + j) = 5;
		j++;
		*(realDeckArr + j) = 6;
		j++;
		*(realDeckArr + j) = 6;
		j++;
		*(realDeckArr + j) = 6;
		j++;
		*(realDeckArr + j) = 6;
		j++;
		*(realDeckArr + j) = 7;
		j++;
		*(realDeckArr + j) = 7;
		j++;
		*(realDeckArr + j) = 7;
		j++;
		*(realDeckArr + j) = 7;
		j++;
		*(realDeckArr + j) = 8;
		j++;
		*(realDeckArr + j) = 8;
		j++;
		*(realDeckArr + j) = 8;
		j++;
		*(realDeckArr + j) = 8;
		j++;
		*(realDeckArr + j) = 9;
		j++;
		*(realDeckArr + j) = 9;
		j++;
		*(realDeckArr + j) = 9;
		j++;
		*(realDeckArr + j) = 9;
		j++;
		*(realDeckArr + j) = 10;
		j++;
		*(realDeckArr + j) = 10;
		j++;
		*(realDeckArr + j) = 10;
		j++;
		*(realDeckArr + j) = 10;
		j++;
		*(realDeckArr + j) = 21;
		j++;
		*(realDeckArr + j) = 21;
		j++;
		*(realDeckArr + j) = 21;
		j++;
		*(realDeckArr + j) = 21;
		j++;
		*(realDeckArr + j) = 31;
		j++;
		*(realDeckArr + j) = 31;
		j++;
		*(realDeckArr + j) = 31;
		j++;
		*(realDeckArr + j) = 31;
		j++;
		*(realDeckArr + j) = 41;
		j++;
		*(realDeckArr + j) = 41;
		j++;
		*(realDeckArr + j) = 41;
		j++;
		*(realDeckArr + j) = 41;
		j++;
	}
	cout << "Done." << endl << endl;
	shuffleCards();
}

void playerInput(){
	money = 15;
	do{
		cout << clear;
		cout << "          ---Money Input---" << endl;
		cout << "How much money will you be playing with?" << endl;
		if (money < 10 || money > 1000000){
			cout << "Error: must spend atleast $10, and" << endl;
			cout << "no more than $1,000,000." << endl;
		}
		cout << "$: ";
		cin >> money;
		cin.ignore(100000, '\n');
	} while (money < 10 || money > 1000000);

	do{
		cout << clear;
		cout << "          ---Number of Decks---" << endl;
		cout << "How many decks would you like to play with?" << endl;
		if (decks < 1 || decks > 1000000)
			cout << "Error: must be between 1 and 1,000,000 decks." << endl;
		cout << ": ";
		cin >> decks;
		cin.ignore(100000, '\n');
	} while (decks < 1 || decks > 1000000);
}

void playerSelect(){
	do{
		bet = 1;
		do{
			cout << clear;
			cout << "Current Holdings $:" << money << "." << endl;
			cout << "How much would you like to bet in round " << roundCount << "?" << endl;
			cout << "(Bet 0 to leave)" << endl;
			if (bet > 1000000 || bet < 0)
				cout << "Error: Bet must be between $1 and $1,000,000." << endl;
			if (money < bet)
				cout << "Error: You don't have enough money!" << endl;
			cout << "$: ";
			cin >> bet;
			cin.ignore(100000, '\n');
		} while (bet > 1000000 || bet < 0 || ((money - bet) < 0));
		if (bet != 0)
			money = money - bet;
		roundCount++;

		if (bet == 0){
			cout << clear;
			cout << "You left with $: " << money << "." << endl;
			money = -1;
			cin.get();
		}

		if (roundoverCheck() == false)
			playerTurn();
		if (roundoverCheck() == false)
			dealerTurn();

		cout << clear;
		displayTable();
		cout << endl << endl;

		cout << "Dealers Points: " << dealersPoints << endl;
		cout << "Players Points: " << playersPoints << endl << endl;

		if (dealersPoints == playersPoints){
			cout << "Draw!";
			money = money + bet;
		}
		else if (playersPoints == 21 && dealersPoints != 21){
			cout << "You Win!";
			money = money + (bet * 1.5);
		}
		else if (playersPoints != 21 && dealersPoints == 21){
			cout << "Dealer Wins!";
			bet = 0;
		}
		else if (playersPoints > 21 && dealersPoints <= 21){
			cout << "You Bust!";
			bet = 0;
		}
		else if (dealersPoints > 21 && playersPoints <= 21){
			cout << "You Win!";
			money = money + (bet * 2);
		}
		else if (dealersPoints < 21 && playersPoints < 21){
			if (dealersPoints > playersPoints){
				cout << "Dealer Wins!";
				bet = 0;
			}
			if (playersPoints > dealersPoints){
				cout << "You Win!";
				money = money + (bet * 2);
			}
		}
		if (money > 0){
			cout << "\nYour current holdings: $" << money;
			cout << endl << "Press enter to continue..." << endl;
			cin.get();
		}
		if (money == 0){
			money = -1;
			cout << "\nYou have no money." << endl;
			cout << "You made it to round " << roundCount << "." << endl;
			cout << endl << "Press enter to return to the main menu..." << endl;
			cin.get();
		}

		if (deckPosition > (cards / 2.0))
			shuffleCards();
		for (int i = 0; i < 21; i++){
			playersHand[i] = 0;
			dealersHand[i] = 0;
		}
		playersHandPosition = 0;
		dealersHandPosition = 0;
	} while (gameoverCheck() == false);
}

bool roundoverCheck(){
	calculatePoints();
	if (playersPoints > 20 || dealersPoints > 20)
		return true;
	if (playersPoints < 21 && dealersPoints < 21)
		return false;
	return 0;
}

bool gameoverCheck(){
	if (money < 0)
		return true;
	if (money >= 0)
		return false;
	return 0;
}

void displayTable(){
	calculatePoints();
	cout << clear;
	cout << "Dealer:" << endl;
	cout << "Cards: " << endl;
	for (int i = 0; i < 20; i++){
		if (*(dealersHand + i) == 88)
			cout << "A, ";
		if (*(dealersHand + i) == 2)
			cout << "2, ";
		if (*(dealersHand + i) == 3)
			cout << "3, ";
		if (*(dealersHand + i) == 4)
			cout << "4, ";
		if (*(dealersHand + i) == 5)
			cout << "5, ";
		if (*(dealersHand + i) == 6)
			cout << "6, ";
		if (*(dealersHand + i) == 7)
			cout << "7, ";
		if (*(dealersHand + i) == 8)
			cout << "8, ";
		if (*(dealersHand + i) == 9)
			cout << "9, ";
		if (*(dealersHand + i) == 10)
			cout << "10, ";
		if (*(dealersHand + i) == 21)
			cout << "K, ";
		if (*(dealersHand + i) == 31)
			cout << "Q, ";
		if (*(dealersHand + i) == 41)
			cout << "J, ";
	}
	cout << endl << endl << endl;
	cout << "Player:" << endl;
	cout << "Cards: " << endl;
	for (int i = 0; i < 21; i++){
		if (*(playersHand + i) == 88)
			cout << "A, ";
		if (*(playersHand + i) == 2)
			cout << "2, ";
		if (*(playersHand + i) == 3)
			cout << "3, ";
		if (*(playersHand + i) == 4)
			cout << "4, ";
		if (*(playersHand + i) == 5)
			cout << "5, ";
		if (*(playersHand + i) == 6)
			cout << "6, ";
		if (*(playersHand + i) == 7)
			cout << "7, ";
		if (*(playersHand + i) == 8)
			cout << "8, ";
		if (*(playersHand + i) == 9)
			cout << "9, ";
		if (*(playersHand + i) == 10)
			cout << "10, ";
		if (*(playersHand + i) == 21)
			cout << "K, ";
		if (*(playersHand + i) == 31)
			cout << "Q, ";
		if (*(playersHand + i) == 41)
			cout << "J, ";
	}
	cout << endl << endl << endl << endl;
}

void shuffleCards(){
	cout << clear;
	cout << "Shuffling Cards..." << endl;
	int loop10 = 0;
	int temp;
	deckPosition = 0;
	for (int loop = 0; loop < 100; loop++, loop10++){
		if (decks >= 300000){
			cout << clear;
			cout << "Shuffling Cards..." << endl;
			cout << loop << "% Complete." << endl;
		}
		if (decks < 300000 && loop10 >= 10){
			loop10 = 0;
			cout << clear;
			cout << "Shuffling Cards..." << endl;
			cout << loop << "% Complete." << endl;
		}
		for (int i = 0; i < cards; i++){
			ran = rand() % (cards);
			temp = *(realDeckArr + i);
			*(realDeckArr + i) = *(realDeckArr + ran);
			*(realDeckArr + ran) = temp;
		}
	}
	cout << "Done." << endl;
}

void calculatePoints(){
	playersPoints = 0;
	dealersPoints = 0;
	playerAce = 0;
	dealerAce = 0;
	for (int i = 0; i < 21; i++){
		if (playersHand[i] == 2)
			playersPoints = playersPoints + 2;
		else if (playersHand[i] == 3)
			playersPoints = playersPoints + 3;
		else if (playersHand[i] == 4)
			playersPoints = playersPoints + 4;
		else if (playersHand[i] == 5)
			playersPoints = playersPoints + 5;
		else if (playersHand[i] == 6)
			playersPoints = playersPoints + 6;
		else if (playersHand[i] == 7)
			playersPoints = playersPoints + 7;
		else if (playersHand[i] == 8)
			playersPoints = playersPoints + 8;
		else if (playersHand[i] == 9)
			playersPoints = playersPoints + 9;
		else if (playersHand[i] == 10)
			playersPoints = playersPoints + 10;
		else if (playersHand[i] == 21)
			playersPoints = playersPoints + 10;
		else if (playersHand[i] == 31)
			playersPoints = playersPoints + 10;
		else if (playersHand[i] == 41)
			playersPoints = playersPoints + 10;
		else if (playersHand[i] == 88){
			playerAce++;
		}
	}
		for (int i = 0; i < playerAce; i++){
			if ((playersPoints + 11) > 21)
				playersPoints = playersPoints + 1;
			else if ((playersPoints + 11) < 21)
				playersPoints = playersPoints + 11;
	}

		for (int i = 0; i < 21; i++){
			if (dealersHand[i] == 2)
				dealersPoints = dealersPoints + 2;
			if (dealersHand[i] == 3)
				dealersPoints = dealersPoints + 3;
			if (dealersHand[i] == 4)
				dealersPoints = dealersPoints + 4;
			if (dealersHand[i] == 5)
				dealersPoints = dealersPoints + 5;
			if (dealersHand[i] == 6)
				dealersPoints = dealersPoints + 6;
			if (dealersHand[i] == 7)
				dealersPoints = dealersPoints + 7;
			if (dealersHand[i] == 8)
				dealersPoints = dealersPoints + 8;
			if (dealersHand[i] == 9)
				dealersPoints = dealersPoints + 9;
			if (dealersHand[i] == 10)
				dealersPoints = dealersPoints + 10;
			if (dealersHand[i] == 21)
				dealersPoints = dealersPoints + 10;
			if (dealersHand[i] == 31)
				dealersPoints = dealersPoints + 10;
			if (dealersHand[i] == 41)
				dealersPoints = dealersPoints + 10;
			else if (dealersHand[i] == 88){
				dealerAce++;
			}
		}
		for (int i = 0; i < dealerAce; i++){
			if ((dealersPoints + 11) > 21)
				dealersPoints = dealersPoints + 1;
			else if ((dealersPoints + 11) < 21)
				dealersPoints = dealersPoints + 11;
	}
}

void dealerTurn(){
	if (gameoverCheck() == false){
		do{
			displayTable();
			calculatePoints();
			dealersHand[dealersHandPosition] = *(realDeckArr + deckPosition);
			dealersHandPosition++;
			deckPosition++;
			displayTable();
			for (int i = 0; i < ranslow1; i++){
				ran = rand() % (ranslow2);
			}
			calculatePoints();
			displayTable();
		} while (dealersPoints <= 16);
	}
}

void playerTurn(){
	if (gameoverCheck() == false){
		displayTable();
		for (int i = 0; i < ranslow1; i++){
			ran = rand() % (ranslow2);
		}
		playersHand[playersHandPosition] = *(realDeckArr + deckPosition);
		playersHandPosition++;
		deckPosition++;
		displayTable();
		for (int i = 0; i < ranslow1; i++){
			ran = rand() % (ranslow2);
		}
		displayTable();
		dealersHand[dealersHandPosition] = *(realDeckArr + deckPosition);
		dealersHandPosition++;
		deckPosition++;
		displayTable();
		for (int i = 0; i < ranslow1; i++){
			ran = rand() % (ranslow2);
		}
		displayTable();
		playersHand[playersHandPosition] = *(realDeckArr + deckPosition);
		playersHandPosition++;
		deckPosition++;
		if (playersPoints != 21)
			bettingMenu();
	}
}

void bettingMenu(){
	do{
		if (playersPoints < 21){
			do{
				displayTable();
				cout << "1. Hit     or     2. Stand" << endl;
				if (bettingChoice < 1 || bettingChoice > 2)
					cout << "Error: Invalid choice. Hit, or Stand." << endl;
				cout << ": ";
				cin >> bettingChoice;
				cin.ignore(100000, '\n');
			} while (bettingChoice < 1 || bettingChoice > 2);

			switch (bettingChoice){

			case 1:{
				playersHand[playersHandPosition] = realDeckArr[deckPosition];
				playersHandPosition++;
				deckPosition++;
				displayTable();
				break;
			}

			case 2:{
				break;
			}
			}
		}

	} while (bettingChoice == 1 && roundoverCheck() == false);


}