#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <conio.h>
using namespace std;

void drawBox(char *spaces);
void players(char *spaces, char player);
void computers (char *spaces, char computer);
bool showWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);
int main() {
	char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	char player = 'O';
	char computer = 'X';
	bool running = true;
	
	drawBox(spaces);
	
	while (running) {
		players(spaces, player);
		drawBox(spaces);
		if (showWinner(spaces, player, computer)) {
			running = false;
			break;
		} else if (checkTie(spaces)) {
			running = false;
			break;
		}
		
		computers(spaces, computer);
		drawBox(spaces);
		if (showWinner(spaces, player, computer)) {
			running = false;
			break;
		} else if (checkTie(spaces)) {
			running = false;
			break;
		}
	}
}

void drawBox(char *spaces) {
	system("clear");
	cout<<"     |     |     "<< '\n';
	cout<<"  "<< spaces[0] <<"  |  "<< spaces[1] <<"  |  "<< spaces[2] <<"    "<< '\n';
	cout<<"_____|_____|_____"<<'\n';
	cout<<"     |     |     "<< '\n';
	cout<<"  "<< spaces[3] <<"  |  "<< spaces[4] <<"  |  "<< spaces[5] <<"    "<< '\n';
	cout<<"_____|_____|_____"<<'\n';
	cout<<"     |     |     "<< '\n';
	cout<<"  "<< spaces[6] <<"  |  "<< spaces[7] <<"  |  "<< spaces[8] <<"    "<< '\n';
}

void players(char *spaces, char player) {
	int number;
	do {
		cout<<"Enter the tile to insert 'O' (1-9): ";
		cin>>number;
		number--;
	
	if (spaces[number] == ' ') {
		spaces[number] = player;
		break;
	}
	} while (number >= 0 || number <= 8);
	
}

void computers(char *spaces, char computer) {
	int number;
	srand(time(0));
	
	while (true) {
		number = rand() % 9;
		
		if (spaces[number] == ' ') {
			spaces[number] = computer;
			break;
		}
	}
}

bool showWinner (char *spaces, char player, char computer) {
	if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])) {
		spaces[0] == player ? cout<<"Player Wins!!\n" : cout<<"Player Lose!!\n";
	} else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])) {
		spaces[3] == player ? cout<<"Player Wins!!\n" : cout<<"Player Lose!!\n";
	} else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])) {
		spaces[6] == player ? cout<<"Player Wins!!\n" : cout<<"Player Lose!!\n";
	} else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])) {
		spaces[0] == player ? cout<<"Player Wins!!\n" : cout<<"Player Lose!!\n";
	} else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])) {
		spaces[1] == player ? cout<<"Player Wins!!\n" : cout<<"Player Lose!!\n";
	} else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])) {
		spaces[2] == player ? cout<<"Player Wins!!\n" : cout<<"Player Lose!!\n";
	} else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])) {
		spaces[0] == player ? cout<<"Player Wins!!\n" : cout<<"Player Lose!!\n";
	} else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])) {
		spaces[2] == player ? cout<<"Player Wins!!\n" : cout<<"Player Lose!!\n";
	} else {
		return false;
	}
	return true;
}

bool checkTie(char *spaces) {
	for (int i = 0; i<9; i++) {
		if (spaces[i] == ' ') {
			return false;
		}
	}
	cout<<"The game is Tie!!\n";
	return true;
}