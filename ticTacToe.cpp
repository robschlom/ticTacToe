#include <iostream>
#include <stdio.h>

bool checkForWin(int board[]);
void printBoard(int board[]);
void printWin(bool x);
void printCat();
void printRow(int a, int b, int c);

int main (int argc, char** argv){
	int board[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};
	//Squares are left 9 keys (qweasdzxc)
	bool xTurn = true;
	while (checkForWin(board) == false){
		printBoard(board);
		if (xTurn){
			std::cout << "Place an X: ";
		}
		else{
			std::cout << "Place an O: ";
		}
		char move;
		std::cin >> move;
		if (move == 'q'){
			if (board[0] != -1){
				continue; //invalid move, space occupied
			}
			if (xTurn){
				board[0] = 0;
			}
			else{
				board[0] = 1;
			}
		}
		else if (move == 'w'){
			if (board[1] != -1){
				continue; //invalid move, space occupied
			}
			if (xTurn){
				board[1] = 0;
			}
			else{
				board[1] = 1;
			}
		}
		else if (move == 'e'){
			if (board[2] != -1){
				continue; //invalid move, space occupied
			}
			if (xTurn){
				board[2] = 0;
			}
			else{
				board[2] = 1;
			}
		}
		else if (move == 'a'){
			if (board[3] != -1){
				continue; //invalid move, space occupied
			}
			if (xTurn){
				board[3] = 0;
			}
			else{
				board[3] = 1;
			}
		}
		else if (move == 's'){
			if (board[4] != -1){
				continue; //invalid move, space occupied
			}
			if (xTurn){
				board[4] = 0;
			}
			else{
				board[4] = 1;
			}
		}
		else if (move == 'd'){
			if (board[5] != -1){
				continue; //invalid move, space occupied
			}
			if (xTurn){
				board[5] = 0;
			}
			else{
				board[5] = 1;
			}
		}
		else if (move == 'z'){
			if (board[6] != -1){
				continue; //invalid move, space occupied
			}
			if (xTurn){
				board[6] = 0;
			}
			else{
				board[6] = 1;
			}
		}
		else if (move == 'x'){
			if (board[7] != -1){
				continue; //invalid move, space occupied
			}
			if (xTurn){
				board[7] = 0;
			}
			else{
				board[7] = 1;
			}
		}
		else if (move == 'c'){
			if (board[8] != -1){
				continue; //invalid move, space occupied
			}
			if (xTurn){
				board[8] = 0;
			}
			else{
				board[8] = 1;
			}
		}
		else{
			return 0;
		}
		//printBoard(board);
		xTurn = !xTurn;
	}
	printBoard(board);
	printWin(!xTurn);
	exit(0);
}

bool checkForWin(int board[]){
	if (board[0] == board[1] && board[1] == board[2] && (board[2] == 0 || board[2] == 1)){
		return true;
	}
	else if (board[3] == board[4] && board[4] == board[5] && (board[5] == 0 || board[5] == 1)){
		return true;
	} 
	else if (board[6] == board[7] && board[7] == board[8] && (board[8] == 0 || board[8] == 1)){
		return true;
	}
	else if (board[0] == board[3] && board[3] == board[6] && (board[6] == 0 || board[6] == 1)){
		return true;
	}
	else if (board[1] == board[4] && board[4] == board[7] && (board[7] == 0 || board[7] == 1)){
		return true;
	}
	else if (board[2] == board[5] && board[5] == board[8] && (board[8] == 0 || board[8] == 1)){
		return true;
	}
	else if (board[0] == board[4] && board[4] == board[8] && (board[8] == 0 || board[8] == 1)){
		return true;
	}
	else if (board[2] == board[4] && board[4] == board[6] && (board[6] == 0 || board[6] == 1)){
		return true;
	}
	else if (board[0] != -1 && board[1] != -1 && board[2] != -1 && board[3] != -1 && board[4] != -1 && board[5] != -1 && board[6] != -1 && board[7] != -1 && board[8] != -1){
		printCat();
		exit(0);
	}
	else{
		return false;
	}
}

void printBoard(int board[]){
	printRow(board[0], board[1], board[2]);
	printRow(board[3], board[4], board[5]);
	printRow(board[6], board[7], board[8]);
}

//80 charachters in a line
void printRow(int a, int b, int c){
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	if (a == -1 && b == -1 && c == -1){//Empty row
		for (int i = 0; i < 7; i++){
			std::cout << "|                         |                          |                         |" << std::endl;
		}
	}
	//all the x&empty possibilities
	else if (a == 0 && b == -1 && c == -1){//An x and 2 emptys
		for (int i = 0; i < 3; i++){
			std::cout << "|";
			for (int j = 0; j < 9+i; j++){
				std::cout << " ";
			}
			std::cout << "\\";
			for (int k = 0; k < 5-2*i; k++){
				std::cout << " ";
			}
			std::cout << "/";
			for (int l = 0; l < 9+i; l++){
				std::cout << " ";
			}
			std::cout << "|                          |                         |" << std::endl;
		}
		std::cout << "|";
		for (int j = 0; j < 12; j++){
			std::cout << " ";
		}
		std::cout << "X";
		for (int k = 0; k < 12; k++){
			std::cout << " ";
		}
		std::cout << "|                          |                         |" << std::endl;
		for (int l = 0; l < 3; l++){
			std::cout << "|";
			for (int m = 0; m < 11-l; m++){
				std::cout << " ";
			}
			std::cout << "/";
			for (int n = 0; n < 1+2*l; n++){
				std::cout << " ";
			}
			std::cout << "\\";
			for (int o = 0; o < 11-l; o++){
				std::cout << " ";
			}
			std::cout << "|                          |                         |" << std::endl;
		}
	}
	else if (a == 0 && b == 0 && c == -1){
		for (int i = 0; i < 3; i++){
			std::cout << "|";
			for (int j = 0; j < 9+i; j++){
				std::cout << " ";
			}
			std::cout << "\\";
			for (int k = 0; k < 5-2*i; k++){
				std::cout << " ";
			}
			std::cout << "/";
			for (int l = 0; l < 9+i; l++){
				std::cout << " ";
			}
			std::cout << "|";
			//Draw first 3 lines of second x
			for (int m = 0; m < 9+i; m++){
				std::cout << " ";
			}
			std::cout << "\\";
			for (int n = 0; n < 6-2*i; n++){
				std::cout << " ";
			}
			std::cout << "/";
			for (int o = 0; o < 9+i; o++){
				std::cout << " ";
			}
			std::cout << "|                         |" << std::endl;
		}
		std::cout << "|";
		for (int j = 0; j < 12; j++){
			std::cout << " ";
		}
		std::cout << "X";
		for (int k = 0; k < 12; k++){
			std::cout << " ";
		}
		std::cout << "|";
		//Draw middle "xx" line of second x
		for (int p = 0; p < 12; p++){
			std::cout << " ";
		}
		std::cout << "XX";
		for (int q = 0; q < 12; q++){
			std::cout << " ";
		}
		std::cout << "|                         |" << std::endl;
		for (int l = 0; l < 3; l++){
			std::cout << "|";
			for (int m = 0; m < 11-l; m++){
				std::cout << " ";
			}
			std::cout << "/";
			for (int n = 0; n < 1+2*l; n++){
				std::cout << " ";
			}
			std::cout << "\\";
			for (int o = 0; o < 11-l; o++){
				std::cout << " ";
			}
			std::cout << "|";
			//Draw last 3 lines of second x
			for (int m = 0; m < 11-l; m++){
				std::cout << " ";
			}
			std::cout << "/";
			for (int n = 0; n < 2+2*l; n++){
				std::cout << " ";
			}
			std::cout << "\\";
			for (int o = 0; o < 11-l; o++){
				std::cout << " ";
			}
			std::cout << "|                         |" << std::endl;
		}
	}
	else if (a == 0 && b == 0 && c == 0){
		//Line 1
		std::cout << "|         \\     /         |";
		std::cout << "         \\      /         |";
		std::cout << "         \\     /         |";
		std::cout << std::endl;
		//Line 2
		std::cout << "|          \\   /          |";
		std::cout << "          \\    /          |";
		std::cout << "          \\   /          |";
		std::cout << std::endl;
		//Line 3
		std::cout << "|           \\ /           |";
		std::cout << "           \\  /           |";
		std::cout << "           \\ /           |";
		std::cout << std::endl;
		//Line 4
		std::cout << "|            X            |";
		std::cout << "            XX            |";
		std::cout << "            X            |";
		std::cout << std::endl;
		//Line 5
		std::cout << "|           / \\           |";
		std::cout << "           /  \\           |";
		std::cout << "           / \\           |";
		std::cout << std::endl;
		//Line 6
		std::cout << "|          /   \\          |";
		std::cout << "          /    \\          |";
		std::cout << "          /   \\          |";
		std::cout << std::endl;
		//Line 7
		std::cout << "|         /     \\         |";
		std::cout << "         /      \\         |";
		std::cout << "         /     \\         |";
		std::cout << std::endl;
	}
	else if (a == 0 && b == -1 && c == 0){
		for (int i = 0; i < 3; i++){
			std::cout << "|";
			for (int j = 0; j < 9+i; j++){
				std::cout << " ";
			}
			std::cout << "\\";
			for (int k = 0; k < 5-2*i; k++){
				std::cout << " ";
			}
			std::cout << "/";
			for (int l = 0; l < 9+i; l++){
				std::cout << " ";
			}
			std::cout << "|                          |";
			//Draw first 3 lines of second x
			for (int m = 0; m < 9+i; m++){
				std::cout << " ";
			}
			std::cout << "\\";
			for (int n = 0; n < 5-2*i; n++){
				std::cout << " ";
			}
			std::cout << "/";
			for (int o = 0; o < 9+i; o++){
				std::cout << " ";
			}
			std::cout << "|" << std::endl;
		}
		std::cout << "|";
		for (int j = 0; j < 12; j++){
			std::cout << " ";
		}
		std::cout << "X";
		for (int k = 0; k < 12; k++){
			std::cout << " ";
		}
		std::cout << "|                          |";
		//Draw middle "xx" line of second x
		for (int p = 0; p < 12; p++){
			std::cout << " ";
		}
		std::cout << "X";
		for (int q = 0; q < 12; q++){
			std::cout << " ";
		}
		std::cout << "|" << std::endl;
		for (int l = 0; l < 3; l++){
			std::cout << "|";
			for (int m = 0; m < 11-l; m++){
				std::cout << " ";
			}
			std::cout << "/";
			for (int n = 0; n < 1+2*l; n++){
				std::cout << " ";
			}
			std::cout << "\\";
			for (int o = 0; o < 11-l; o++){
				std::cout << " ";
			}
			std::cout << "|                          |";
			//Draw last 3 lines of second x
			for (int m = 0; m < 11-l; m++){
				std::cout << " ";
			}
			std::cout << "/";
			for (int n = 0; n < 1+2*l; n++){
				std::cout << " ";
			}
			std::cout << "\\";
			for (int o = 0; o < 11-l; o++){
				std::cout << " ";
			}
			std::cout << "|" << std::endl;
		}
	}
	else if (a == -1 && b == 0 && c == -1){
		for (int i = 0; i < 3; i++){
			std::cout << "|                         |";
			//Draw first 3 lines of second x
			for (int m = 0; m < 9+i; m++){
				std::cout << " ";
			}
			std::cout << "\\";
			for (int n = 0; n < 6-2*i; n++){
				std::cout << " ";
			}
			std::cout << "/";
			for (int o = 0; o < 9+i; o++){
				std::cout << " ";
			}
			std::cout << "|                         |" << std::endl;
		}
		std::cout << "|                         |";
		//Draw middle "xx" line of second x
		for (int p = 0; p < 12; p++){
			std::cout << " ";
		}
		std::cout << "XX";
		for (int q = 0; q < 12; q++){
			std::cout << " ";
		}
		std::cout << "|                         |" << std::endl;
		for (int l = 0; l < 3; l++){
			std::cout << "|                         |";
			//Draw last 3 lines of second x
			for (int m = 0; m < 11-l; m++){
				std::cout << " ";
			}
			std::cout << "/";
			for (int n = 0; n < 2+2*l; n++){
				std::cout << " ";
			}
			std::cout << "\\";
			for (int o = 0; o < 11-l; o++){
				std::cout << " ";
			}
			std::cout << "|                         |" << std::endl;
		}
	}
	else if (a == -1 && b == 0 && c == 0){
		for (int i = 0; i < 3; i++){
			std::cout << "|                         |";
			//Draw first 3 lines of second x
			for (int m = 0; m < 9+i; m++){
				std::cout << " ";
			}
			std::cout << "\\";
			for (int n = 0; n < 6-2*i; n++){
				std::cout << " ";
			}
			std::cout << "/";
			for (int o = 0; o < 9+i; o++){
				std::cout << " ";
			}
			std::cout << "|";
			//Draw first 3 lines of third x
			for (int j = 0; j < 9+i; j++){
				std::cout << " ";
			}
			std::cout << "\\";
			for (int k = 0; k < 5-2*i; k++){
				std::cout << " ";
			}
			std::cout << "/";
			for (int l = 0; l < 9+i; l++){
				std::cout << " ";
			}
			std::cout << "|" << std::endl;
		}
		std::cout << "|                         |";
		//Draw middle "xx" line of second x
		for (int p = 0; p < 12; p++){
			std::cout << " ";
		}
		std::cout << "XX";
		for (int q = 0; q < 12; q++){
			std::cout << " ";
		}
		std::cout << "|";
		for (int j = 0; j < 12; j++){
			std::cout << " ";
		}
		std::cout << "X";
		for (int k = 0; k < 12; k++){
			std::cout << " ";
		}
		std::cout << "|" << std::endl;
		for (int l = 0; l < 3; l++){
			std::cout << "|                         |";
			//Draw last 3 lines of second x
			for (int m = 0; m < 11-l; m++){
				std::cout << " ";
			}
			std::cout << "/";
			for (int n = 0; n < 2+2*l; n++){
				std::cout << " ";
			}
			std::cout << "\\";
			for (int o = 0; o < 11-l; o++){
				std::cout << " ";
			}
			std::cout << "|";
			//Draw last 3 lines of third x
			for (int m = 0; m < 11-l; m++){
				std::cout << " ";
			}
			std::cout << "/";
			for (int n = 0; n < 1+2*l; n++){
				std::cout << " ";
			}
			std::cout << "\\";
			for (int o = 0; o < 11-l; o++){
				std::cout << " ";
			}
			std::cout << "|" << std::endl;
		}
	}
	else if (a == -1 && b == -1 && c == 0){
		for (int i = 0; i < 3; i++){
			std::cout << "|                         |                          |";
			//Draw first 3 lines of third x
			for (int j = 0; j < 9+i; j++){
				std::cout << " ";
			}
			std::cout << "\\";
			for (int k = 0; k < 5-2*i; k++){
				std::cout << " ";
			}
			std::cout << "/";
			for (int l = 0; l < 9+i; l++){
				std::cout << " ";
			}
			std::cout << "|" << std::endl;
		}
		std::cout << "|                         |                          |";
		for (int j = 0; j < 12; j++){
			std::cout << " ";
		}
		std::cout << "X";
		for (int k = 0; k < 12; k++){
			std::cout << " ";
		}
		std::cout << "|" << std::endl;
		for (int l = 0; l < 3; l++){
			std::cout << "|                         |                          |";
			//Draw last 3 lines of third x
			for (int m = 0; m < 11-l; m++){
				std::cout << " ";
			}
			std::cout << "/";
			for (int n = 0; n < 1+2*l; n++){
				std::cout << " ";
			}
			std::cout << "\\";
			for (int o = 0; o < 11-l; o++){
				std::cout << " ";
			}
			std::cout << "|" << std::endl;
		}
	}
	//all the o&empty possibilities
	else if (a == 1 && b == 1 && c == 1){
		//Line 1
		std::cout<< "|          /¯¯¯\\          |";
		std::cout<< "          /¯¯¯¯\\          |";
		std::cout<< "          /¯¯¯\\          |";
		std::cout<< std::endl;
		//line 2
		std::cout<< "|         / /¯\\ \\         |";
		std::cout<< "         / /¯¯\\ \\         |";
		std::cout<< "         / /¯\\ \\         |";
		std::cout << std::endl;
		//line 3
		std::cout<< "|         | | | |         |";
		std::cout<< "         | |  | |         |";
		std::cout<< "         | | | |         |"; 
		std::cout<< std::endl;
		//line 4
		std::cout<< "|         | | | |         |";
		std::cout<< "         | |  | |         |";
		std::cout<< "         | | | |         |";
		std::cout << std::endl;
		//line 5
		std::cout<< "|         | | | |         |";
		std::cout<< "         | |  | |         |";
		std::cout<< "         | | | |         |"; 
		std::cout<< std::endl;
		//line 6
		std::cout<< "|         \\ \\_/ /         |";
		std::cout<< "         \\ \\__/ /         |";
		std::cout<< "         \\ \\_/ /         |"; 
		std::cout<< std::endl;
		//line 7
		std::cout<< "|          \\___/          |";
		std::cout<< "          \\____/          |";
		std::cout<< "          \\___/          |"; 
		std::cout<< std::endl;
	}
	else if (a == 1 && b == 1 && c == -1){
		//Line 1
		std::cout<< "|          /¯¯¯\\          |";
		std::cout<< "          /¯¯¯¯\\          |";
		std::cout<< "                         |";
		std::cout<< std::endl;
		//line 2
		std::cout<< "|         / /¯\\ \\         |";
		std::cout<< "         / /¯¯\\ \\         |";
		std::cout<< "                         |";
		std::cout << std::endl;
		//line 3
		std::cout<< "|         | | | |         |";
		std::cout<< "         | |  | |         |";
		std::cout<< "                         |"; 
		std::cout<< std::endl;
		//line 4
		std::cout<< "|         | | | |         |";
		std::cout<< "         | |  | |         |";
		std::cout<< "                         |";
		std::cout << std::endl;
		//line 5
		std::cout<< "|         | | | |         |";
		std::cout<< "         | |  | |         |";
		std::cout<< "                         |"; 
		std::cout<< std::endl;
		//line 6
		std::cout<< "|         \\ \\_/ /         |";
		std::cout<< "         \\ \\__/ /         |";
		std::cout<< "                         |"; 
		std::cout<< std::endl;
		//line 7
		std::cout<< "|          \\___/          |";
		std::cout<< "          \\____/          |";
		std::cout<< "                         |"; 
		std::cout<< std::endl;
	}
	else if (a == 1 && b == -1 && c == 1){
		//Line 1
		std::cout<< "|          /¯¯¯\\          |";
		std::cout<< "                          |";
		std::cout<< "          /¯¯¯\\          |";
		std::cout<< std::endl;
		//line 2
		std::cout<< "|         / /¯\\ \\         |";
		std::cout<< "                          |";
		std::cout<< "         / /¯\\ \\         |";
		std::cout << std::endl;
		//line 3
		std::cout<< "|         | | | |         |";
		std::cout<< "                          |";
		std::cout<< "         | | | |         |"; 
		std::cout<< std::endl;
		//line 4
		std::cout<< "|         | | | |         |";
		std::cout<< "                          |";
		std::cout<< "         | | | |         |";
		std::cout << std::endl;
		//line 5
		std::cout<< "|         | | | |         |";
		std::cout<< "                          |";
		std::cout<< "         | | | |         |"; 
		std::cout<< std::endl;
		//line 6
		std::cout<< "|         \\ \\_/ /         |";
		std::cout<< "                          |";
		std::cout<< "         \\ \\_/ /         |"; 
		std::cout<< std::endl;
		//line 7
		std::cout<< "|          \\___/          |";
		std::cout<< "                          |";
		std::cout<< "          \\___/          |"; 
		std::cout<< std::endl;
	}
	else if (a == 1 && b == -1 && c == -1){
		//Line 1
		std::cout<< "|          /¯¯¯\\          |";
		std::cout<< "                          |";
		std::cout<< "                         |";
		std::cout<< std::endl;
		//line 2
		std::cout<< "|         / /¯\\ \\         |";
		std::cout<< "                          |";
		std::cout<< "                         |";
		std::cout << std::endl;
		//line 3
		std::cout<< "|         | | | |         |";
		std::cout<< "                          |";
		std::cout<< "                         |"; 
		std::cout<< std::endl;
		//line 4
		std::cout<< "|         | | | |         |";
		std::cout<< "                          |";
		std::cout<< "                         |";
		std::cout << std::endl;
		//line 5
		std::cout<< "|         | | | |         |";
		std::cout<< "                          |";
		std::cout<< "                         |"; 
		std::cout<< std::endl;
		//line 6
		std::cout<< "|         \\ \\_/ /         |";
		std::cout<< "                          |";
		std::cout<< "                         |"; 
		std::cout<< std::endl;
		//line 7
		std::cout<< "|          \\___/          |";
		std::cout<< "                          |";
		std::cout<< "                         |"; 
		std::cout<< std::endl;
	}
	else if (a == -1 && b == 1 && c == 1){
		//Line 1
		std::cout<< "|                         |";
		std::cout<< "          /¯¯¯¯\\          |";
		std::cout<< "          /¯¯¯\\          |";
		std::cout<< std::endl;
		//line 2
		std::cout<< "|                         |";
		std::cout<< "         / /¯¯\\ \\         |";
		std::cout<< "         / /¯\\ \\         |";
		std::cout << std::endl;
		//line 3
		std::cout<< "|                         |";
		std::cout<< "         | |  | |         |";
		std::cout<< "         | | | |         |"; 
		std::cout<< std::endl;
		//line 4
		std::cout<< "|                         |";
		std::cout<< "         | |  | |         |";
		std::cout<< "         | | | |         |";
		std::cout << std::endl;
		//line 5
		std::cout<< "|                         |";
		std::cout<< "         | |  | |         |";
		std::cout<< "         | | | |         |"; 
		std::cout<< std::endl;
		//line 6
		std::cout<< "|                         |";
		std::cout<< "         \\ \\__/ /         |";
		std::cout<< "         \\ \\_/ /         |"; 
		std::cout<< std::endl;
		//line 7
		std::cout<< "|                         |";
		std::cout<< "          \\____/          |";
		std::cout<< "          \\___/          |"; 
		std::cout<< std::endl;
	}
	else if (a == -1 && b == 1 && c == -1){
		//Line 1
		std::cout<< "|                         |";
		std::cout<< "          /¯¯¯¯\\          |";
		std::cout<< "                         |";
		std::cout<< std::endl;
		//line 2
		std::cout<< "|                         |";
		std::cout<< "         / /¯¯\\ \\         |";
		std::cout<< "                         |";
		std::cout << std::endl;
		//line 3
		std::cout<< "|                         |";
		std::cout<< "         | |  | |         |";
		std::cout<< "                         |"; 
		std::cout<< std::endl;
		//line 4
		std::cout<< "|                         |";
		std::cout<< "         | |  | |         |";
		std::cout<< "                         |";
		std::cout << std::endl;
		//line 5
		std::cout<< "|                         |";
		std::cout<< "         | |  | |         |";
		std::cout<< "                         |"; 
		std::cout<< std::endl;
		//line 6
		std::cout<< "|                         |";
		std::cout<< "         \\ \\__/ /         |";
		std::cout<< "                         |"; 
		std::cout<< std::endl;
		//line 7
		std::cout<< "|                         |";
		std::cout<< "          \\____/          |";
		std::cout<< "                         |"; 
		std::cout<< std::endl;
	}
	else if (a == -1 && b == -1 && c == 1){
		//Line 1
		std::cout<< "|                         |";
		std::cout<< "                          |";
		std::cout<< "          /¯¯¯\\          |";
		std::cout<< std::endl;
		//line 2
		std::cout<< "|                         |";
		std::cout<< "                          |";
		std::cout<< "         / /¯\\ \\         |";
		std::cout << std::endl;
		//line 3
		std::cout<< "|                         |";
		std::cout<< "                          |";
		std::cout<< "         | | | |         |"; 
		std::cout<< std::endl;
		//line 4
		std::cout<< "|                         |";
		std::cout<< "                          |";
		std::cout<< "         | | | |         |";
		std::cout << std::endl;
		//line 5
		std::cout<< "|                         |";
		std::cout<< "                          |";
		std::cout<< "         | | | |         |"; 
		std::cout<< std::endl;
		//line 6
		std::cout<< "|                         |";
		std::cout<< "                          |";
		std::cout<< "         \\ \\_/ /         |"; 
		std::cout<< std::endl;
		//line 7
		std::cout<< "|                         |";
		std::cout<< "                          |";
		std::cout<< "          \\___/          |"; 
		std::cout<< std::endl;
	}
	//all the x&o possibilities
	else if (a == 0 && b == 0 && c == 1){
		//Line 1
		std::cout << "|         \\     /         |";
		std::cout << "         \\      /         |";
		std::cout<< "          /¯¯¯\\          |";
		std::cout << std::endl;
		//Line 2
		std::cout << "|          \\   /          |";
		std::cout << "          \\    /          |";
		std::cout<< "         / /¯\\ \\         |";
		std::cout << std::endl;
		//Line 3
		std::cout << "|           \\ /           |";
		std::cout << "           \\  /           |";
		std::cout<< "         | | | |         |";
		std::cout << std::endl;
		//Line 4
		std::cout << "|            X            |";
		std::cout << "            XX            |";
		std::cout<< "         | | | |         |";
		std::cout << std::endl;
		//Line 5
		std::cout << "|           / \\           |";
		std::cout << "           /  \\           |";
		std::cout<< "         | | | |         |";
		std::cout << std::endl;
		//Line 6
		std::cout << "|          /   \\          |";
		std::cout << "          /    \\          |";
		std::cout<< "         \\ \\_/ /         |";
		std::cout << std::endl;
		//Line 7
		std::cout << "|         /     \\         |";
		std::cout << "         /      \\         |";
		std::cout<< "          \\___/          |";
		std::cout << std::endl;	
	}
	else if (a == 0 && b == 1 && c == 0){
		//Line 1
		std::cout << "|         \\     /         |";
		std::cout<< "          /¯¯¯¯\\          |";
		std::cout << "         \\     /         |";
		std::cout << std::endl;
		//Line 2
		std::cout << "|          \\   /          |";
		std::cout<< "         / /¯¯\\ \\         |";
		std::cout << "          \\   /          |";
		std::cout << std::endl;
		//Line 3
		std::cout << "|           \\ /           |";
		std::cout<< "         | |  | |         |";
		std::cout << "           \\ /           |";
		std::cout << std::endl;
		//Line 4
		std::cout << "|            X            |";
		std::cout<< "         | |  | |         |";
		std::cout << "            X            |";
		std::cout << std::endl;
		//Line 5
		std::cout << "|           / \\           |";
		std::cout<< "         | |  | |         |";
		std::cout << "           / \\           |";
		std::cout << std::endl;
		//Line 6
		std::cout << "|          /   \\          |";
		std::cout<< "         \\ \\__/ /         |";
		std::cout << "          /   \\          |";
		std::cout << std::endl;
		//Line 7
		std::cout << "|         /     \\         |";
		std::cout<< "          \\____/          |";
		std::cout << "         /     \\         |";
		std::cout << std::endl;	
	}
	else if (a == 0 && b == 1 && c == 1){
		//Line 1
		std::cout << "|         \\     /         |";
		std::cout<< "          /¯¯¯¯\\          |";
		std::cout<< "          /¯¯¯\\          |";
		std::cout<< std::endl;
		//line 2
		std::cout << "|          \\   /          |";
		std::cout<< "         / /¯¯\\ \\         |";
		std::cout<< "         / /¯\\ \\         |";
		std::cout << std::endl;
		//line 3
		std::cout << "|           \\ /           |";
		std::cout<< "         | |  | |         |";
		std::cout<< "         | | | |         |"; 
		std::cout<< std::endl;
		//line 4
		std::cout << "|            X            |";
		std::cout<< "         | |  | |         |";
		std::cout<< "         | | | |         |";
		std::cout << std::endl;
		//line 5
		std::cout << "|           / \\           |";
		std::cout<< "         | |  | |         |";
		std::cout<< "         | | | |         |"; 
		std::cout<< std::endl;
		//line 6
		std::cout << "|          /   \\          |";
		std::cout<< "         \\ \\__/ /         |";
		std::cout<< "         \\ \\_/ /         |"; 
		std::cout<< std::endl;
		//line 7
		std::cout << "|         /     \\         |";
		std::cout<< "          \\____/          |";
		std::cout<< "          \\___/          |"; 
		std::cout<< std::endl;	
	}
	else if (a == 1 && b == 0 && c == 0){
		//Line 1
		std::cout<< "|          /¯¯¯\\          |";
		std::cout << "         \\      /         |";
		std::cout << "         \\     /         |";
		std::cout<< std::endl;
		//line 2
		std::cout<< "|         / /¯\\ \\         |";
		std::cout << "          \\    /          |";
		std::cout << "          \\   /          |";
		std::cout << std::endl;
		//line 3
		std::cout<< "|         | | | |         |";
		std::cout << "           \\  /           |";
		std::cout << "           \\ /           |";
		std::cout<< std::endl;
		//line 4
		std::cout<< "|         | | | |         |";
		std::cout << "            XX            |";
		std::cout << "            X            |";
		std::cout << std::endl;
		//line 5
		std::cout<< "|         | | | |         |";
		std::cout << "           /  \\           |";
		std::cout << "           / \\           |"; 
		std::cout<< std::endl;
		//line 6
		std::cout<< "|         \\ \\_/ /         |";
		std::cout << "          /    \\          |";
		std::cout << "          /   \\          |"; 
		std::cout<< std::endl;
		//line 7
		std::cout<< "|          \\___/          |";
		std::cout << "         /      \\         |";
		std::cout << "         /     \\         |"; 
		std::cout<< std::endl;
	}
	else if (a == 1 && b == 0 && c == 1){//OXO
		//Line 1
		std::cout<< "|          /¯¯¯\\          |";
		std::cout << "         \\      /         |";
		std::cout<< "          /¯¯¯\\          |";
		std::cout<< std::endl;
		//line 2
		std::cout<< "|         / /¯\\ \\         |";
		std::cout << "          \\    /          |";
		std::cout<< "         / /¯\\ \\         |";
		std::cout << std::endl;
		//line 3
		std::cout<< "|         | | | |         |";
		std::cout << "           \\  /           |";
		std::cout<< "         | | | |         |"; 
		std::cout<< std::endl;
		//line 4
		std::cout<< "|         | | | |         |";
		std::cout << "            XX            |";
		std::cout<< "         | | | |         |";
		std::cout << std::endl;
		//line 5
		std::cout<< "|         | | | |         |";
		std::cout << "           /  \\           |";
		std::cout<< "         | | | |         |"; 
		std::cout<< std::endl;
		//line 6
		std::cout<< "|         \\ \\_/ /         |";
		std::cout << "          /    \\          |";
		std::cout<< "         \\ \\_/ /         |"; 
		std::cout<< std::endl;
		//line 7
		std::cout<< "|          \\___/          |";
		std::cout << "         /      \\         |";
		std::cout<< "          \\___/          |"; 
		std::cout<< std::endl;	
	}
	else if (a == 1 && b == 1 && c == 0){//OOX
		//Line 1
		std::cout<< "|          /¯¯¯\\          |";
		std::cout<< "          /¯¯¯¯\\          |";
		std::cout << "         \\     /         |";
		std::cout<< std::endl;
		//line 2
		std::cout<< "|         / /¯\\ \\         |";
		std::cout<< "         / /¯¯\\ \\         |";
		std::cout << "          \\   /          |";
		std::cout << std::endl;
		//line 3
		std::cout<< "|         | | | |         |";
		std::cout<< "         | |  | |         |";
		std::cout << "           \\ /           |"; 
		std::cout<< std::endl;
		//line 4
		std::cout<< "|         | | | |         |";
		std::cout<< "         | |  | |         |";
		std::cout << "            X            |";
		std::cout << std::endl;
		//line 5
		std::cout<< "|         | | | |         |";
		std::cout<< "         | |  | |         |";
		std::cout << "           / \\           |"; 
		std::cout<< std::endl;
		//line 6
		std::cout<< "|         \\ \\_/ /         |";
		std::cout<< "         \\ \\__/ /         |";
		std::cout << "          /   \\          |"; 
		std::cout<< std::endl;
		//line 7
		std::cout<< "|          \\___/          |";
		std::cout<< "          \\____/          |";
		std::cout << "         /     \\         |"; 
		std::cout<< std::endl;
	}
	//remaining x,o,empty possibliities
	else if (a == -1 && b == 0 && c ==1){//-XO
		//Line 1
		std::cout<< "|                         |";
		std::cout << "         \\      /         |";
		std::cout<< "          /¯¯¯\\          |";
		std::cout<< std::endl;
		//line 2
		std::cout<< "|                         |";
		std::cout << "          \\    /          |";
		std::cout<< "         / /¯\\ \\         |";
		std::cout << std::endl;
		//line 3
		std::cout<< "|                         |";
		std::cout << "           \\  /           |";
		std::cout<< "         | | | |         |"; 
		std::cout<< std::endl;
		//line 4
		std::cout<< "|                         |";
		std::cout << "            XX            |";
		std::cout<< "         | | | |         |";
		std::cout << std::endl;
		//line 5
		std::cout<< "|                         |";
		std::cout << "           /  \\           |";
		std::cout<< "         | | | |         |"; 
		std::cout<< std::endl;
		//line 6
		std::cout<< "|                         |";
		std::cout << "          /    \\          |";
		std::cout<< "         \\ \\_/ /         |"; 
		std::cout<< std::endl;
		//line 7
		std::cout<< "|                         |";
		std::cout << "         /      \\         |";
		std::cout<< "          \\___/          |"; 
		std::cout<< std::endl;	
	}
	//TO DO
	else if (a == 0 && b == 1 && c == -1){//XO-
		//Line 1
		std::cout << "|         \\     /         |";
		std::cout<< "          /¯¯¯¯\\          |";
		std::cout<< "                         |";
		std::cout<< std::endl;
		//line 2
		std::cout << "|          \\   /          |";
		std::cout<< "         / /¯¯\\ \\         |";
		std::cout<< "                         |";
		std::cout << std::endl;
		//line 3
		std::cout << "|           \\ /           |";
		std::cout<< "         | |  | |         |";
		std::cout<< "                         |"; 
		std::cout<< std::endl;
		//line 4
		std::cout << "|            X            |";
		std::cout<< "         | |  | |         |";
		std::cout<< "                         |";
		std::cout << std::endl;
		//line 5
		std::cout << "|           / \\           |";
		std::cout<< "         | |  | |         |";
		std::cout<< "                         |"; 
		std::cout<< std::endl;
		//line 6
		std::cout << "|          /   \\          |";
		std::cout<< "         \\ \\__/ /         |";
		std::cout<< "                         |"; 
		std::cout<< std::endl;
		//line 7
		std::cout << "|         /     \\         |";
		std::cout<< "          \\____/          |";
		std::cout<< "                         |"; 
		std::cout<< std::endl;
	}
	else if (a == 1 && b == -1 && c ==0){//O-X
		//Line 1
		std::cout<< "|          /¯¯¯\\          |";
		std::cout<< "                          |";
		std::cout << "         \\     /         |";
		std::cout<< std::endl;
		//line 2
		std::cout<< "|         / /¯\\ \\         |";
		std::cout<< "                          |";
		std::cout << "          \\   /          |";
		std::cout << std::endl;
		//line 3
		std::cout<< "|         | | | |         |";
		std::cout<< "                          |";
		std::cout << "           \\ /           |"; 
		std::cout<< std::endl;
		//line 4
		std::cout<< "|         | | | |         |";
		std::cout<< "                          |";
		std::cout << "            X            |";
		std::cout << std::endl;
		//line 5
		std::cout<< "|         | | | |         |";
		std::cout<< "                          |";
		std::cout << "           / \\           |"; 
		std::cout<< std::endl;
		//line 6
		std::cout<< "|         \\ \\_/ /         |";
		std::cout<< "                          |";
		std::cout << "          /   \\          |"; 
		std::cout<< std::endl;
		//line 7
		std::cout<< "|          \\___/          |";
		std::cout<< "                          |";
		std::cout << "         /     \\         |"; 
		std::cout<< std::endl;
	}
	else if (a == -1 && b == 1 && c == 0){//-OX
		//Line 1
		std::cout<< "|                         |";
		std::cout<< "          /¯¯¯¯\\          |";
		std::cout << "         \\     /         |";
		std::cout << std::endl;
		//Line 2
		std::cout<< "|                         |";
		std::cout<< "         / /¯¯\\ \\         |";
		std::cout << "          \\   /          |";
		std::cout << std::endl;
		//Line 3
		std::cout<< "|                         |";
		std::cout<< "         | |  | |         |";
		std::cout << "           \\ /           |";
		std::cout << std::endl;
		//Line 4
		std::cout<< "|                         |";
		std::cout<< "         | |  | |         |";
		std::cout << "            X            |";
		std::cout << std::endl;
		//Line 5
		std::cout<< "|                         |";
		std::cout<< "         | |  | |         |";
		std::cout << "           / \\           |";
		std::cout << std::endl;
		//Line 6
		std::cout<< "|                         |";
		std::cout<< "         \\ \\__/ /         |";
		std::cout << "          /   \\          |";
		std::cout << std::endl;
		//Line 7
		std::cout<< "|                         |";
		std::cout<< "          \\____/          |";
		std::cout << "         /     \\         |";
		std::cout << std::endl;
	}
	else if (a == 1 && b == 0 && c == -1){//OX-
		//Line 1
		std::cout<< "|          /¯¯¯\\          |";
		std::cout << "         \\      /         |";
		std::cout<< "                         |";
		std::cout<< std::endl;
		//line 2
		std::cout<< "|         / /¯\\ \\         |";
		std::cout << "          \\    /          |";
		std::cout<< "                         |";
		std::cout << std::endl;
		//line 3
		std::cout<< "|         | | | |         |";
		std::cout << "           \\  /           |";
		std::cout<< "                         |";
		std::cout<< std::endl;
		//line 4
		std::cout<< "|         | | | |         |";
		std::cout << "            XX            |";
		std::cout<< "                         |";
		std::cout << std::endl;
		//line 5
		std::cout<< "|         | | | |         |";
		std::cout << "           /  \\           |";
		std::cout<< "                         |"; 
		std::cout<< std::endl;
		//line 6
		std::cout<< "|         \\ \\_/ /         |";
		std::cout << "          /    \\          |";
		std::cout<< "                         |";
		std::cout<< std::endl;
		//line 7
		std::cout<< "|          \\___/          |";
		std::cout << "         /      \\         |";
		std::cout<< "                         |"; 
		std::cout<< std::endl;
	}
	else if (a == 0 && b == -1 && c == 1){//X-O
		//Line 1
		std::cout << "|         \\     /         |";
		std::cout<< "                          |";
		std::cout<< "          /¯¯¯\\          |";
		std::cout<< std::endl;
		//line 2
		std::cout << "|          \\   /          |";
		std::cout<< "                          |";
		std::cout<< "         / /¯\\ \\         |";
		std::cout << std::endl;
		//line 3
		std::cout << "|           \\ /           |";
		std::cout<< "                          |";
		std::cout<< "         | | | |         |"; 
		std::cout<< std::endl;
		//line 4
		std::cout << "|            X            |";
		std::cout<< "                          |";
		std::cout<< "         | | | |         |";
		std::cout << std::endl;
		//line 5
		std::cout << "|           / \\           |";
		std::cout<< "                          |";
		std::cout<< "         | | | |         |"; 
		std::cout<< std::endl;
		//line 6
		std::cout << "|          /   \\          |";
		std::cout<< "                          |";
		std::cout<< "         \\ \\_/ /         |"; 
		std::cout<< std::endl;
		//line 7
		std::cout << "|         /     \\         |";
		std::cout<< "                          |";
		std::cout<< "          \\___/          |"; 
		std::cout<< std::endl;
	}
	else{
		std::cout << "Unexpected move" << std::endl;
	}
}

void printCat(){
	printRow(0,1,0);
	std::cout << "--------------------------------------------------------------------------------" << std::endl;
	std::cout << "|                                                                              |" << std::endl;
	std::cout << "|                                                                              |" << std::endl;
	std::cout << "|                                                                              |" << std::endl;
	std::cout << "|                                  Cat's Game                                  |" << std::endl;
	std::cout << "|                                                                              |" << std::endl;
	std::cout << "|                                                                              |" << std::endl;
	std::cout << "|                                                                              |" << std::endl;
	printRow(1,0,1);
}

void printWin(bool x){
	if (x){
		printRow(0,0,0);
		std::cout << "--------------------------------------------------------------------------------" << std::endl;
		std::cout << "|                                                                              |" << std::endl;
		std::cout << "|                                                                              |" << std::endl;
		std::cout << "|                                                                              |" << std::endl;
		std::cout << "|                                    X Wins                                    |" << std::endl;
		std::cout << "|                                                                              |" << std::endl;
		std::cout << "|                                                                              |" << std::endl;
		std::cout << "|                                                                              |" << std::endl;
		printRow(0,0,0);
	}
	else{
		printRow(1,1,1);
		std::cout << "--------------------------------------------------------------------------------" << std::endl;
		std::cout << "|                                                                              |" << std::endl;
		std::cout << "|                                                                              |" << std::endl;
		std::cout << "|                                                                              |" << std::endl;
		std::cout << "|                                    O Wins                                    |" << std::endl;
		std::cout << "|                                                                              |" << std::endl;
		std::cout << "|                                                                              |" << std::endl;
		std::cout << "|                                                                              |" << std::endl;
		printRow(1,1,1);	
	}
}