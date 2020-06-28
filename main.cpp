// Robert Johnson

#include <iostream>
#include <string>

// Object Oriented use of the game
class game {
	// Class variables for the game
private: 
	char board[3][3];
	size_t guessed;
	bool play_one_turn;
	bool game_over;
	std::string winner;
	
	
public:
	
	// Constructor for initialization
	game() {
		guessed = 0;
		game_over = false;
		play_one_turn = true;
		winner = "";
		for (size_t i = 0; i < 3; ++i){
			for (size_t j = 0; j < 3; ++j) {
				board[i][j] = ' ';
			}
		}
	}
	
	// Print the board with separations, blank spaces, and X's or O's
	void print_board() {
		for (size_t i = 0; i < 3; ++i){
			std::cout << "|";
			for (size_t j = 0; j < 3; ++j) {
				std::cout << board[i][j] << "|";
			}
			std::cout << "\n";
		}
	}
	
	// Method for getting the chosen location for alternating players
	void get_choice() {
		if (play_one_turn) std::cout <<"Player 1: ";
		else	std::cout <<"Player 2: ";
		
		std::cout << "Enter row (space) column of the square you choose for your turn: ";
		int row, col;
		
		std::cin >> row >> col;
		
		// Prevent the users from guessing a repeated location
		while (board[row][col] == 'X' || board[row][col] == 'O') {
			std::cout << "That's already been chosen. Try another: ";
			std::cin >> row >> col;
		}
		
		if (play_one_turn)	board[row][col] = 'X';
		else	board[row][col] = 'O';
		
		// Keep track of how many have been guessed (max of 9), and invert player turn
		++guessed;
		play_one_turn = !play_one_turn;
	}
	
	// Check if 9 guesses, or any three-in-a-row possibilities
	void check_end_condition() {
		if (guessed > 8) {
			game_over = true;
			winner = "Cat";
		}
		
		else if (board[0][0] == board[0][1] && board[0][0] == board[0][2]){
			if (board[0][0] == 'X') {
				winner = "Player 1";
				game_over = true;
			}
			else if (board[0][0] == 'O') {
				winner = "Player 2";
				game_over = true;
			}
		}
		else if (board[1][0] == board[1][1] && board[1][0] == board[1][2]){
			if (board[1][0] == 'X') {
				winner = "Player 1";
				game_over = true;
			}
			else if (board[1][0] == 'O') {
				winner = "Player 2";
				game_over = true;
			}
		}
		else if (board[2][0] == board[2][1] && board[2][0] == board[2][2]){
			if (board[2][0] == 'X') {
				winner = "Player 1";
				game_over = true;
			}
			else if (board[2][0] == 'O') {
				winner = "Player 2";
				game_over = true;
			}
		}
		else if (board[0][0] == board[1][1] && board[0][0] == board[2][2]){
			if (board[0][0] == 'X') {
				winner = "Player 1";
				game_over = true;
			}
			else if (board[0][0] == 'O') {
				winner = "Player 2";
				game_over = true;
			}
		}
		else if (board[0][2] == board[1][1] && board[0][2] == board[2][0]){
			if (board[0][2] == 'X') {
				winner = "Player 1";
				game_over = true;
			}
			else if (board[0][2] == 'O') {
				winner = "Player 2";
				game_over = true;
			}
		}
		
		// Display the winner or 'Cat' if a tie game
		if (game_over) {
			std::cout << winner << " wins!\n";
		}
	}
	
	bool get_game_over() { return game_over;}
};

int main()
{
	game t;
	
	t.print_board();
	
	// Game loop
	while (!t.get_game_over()) {
		t.get_choice();
		t.print_board();
		t.check_end_condition();
	}
	
	// CodeLite started auto closing console window, added this to make sure that victories were working.
	system("pause");
	return 0;
}
