// These are like importing toolboxes into our program
#include <iostream>  // This toolbox lets us talk to the user (cin, cout)

// This means "don't make me write std:: before every command"
using namespace std;

// This is our tic-tac-toe board - think of it as a 3x3 grid
// We use numbers 1-9 to represent positions, just like a phone keypad
char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

// This function draws the board on screen
// Think of it like drawing the grid with X's and O's
void showBoard() {
    cout << "\n Tic-Tac-Toe Game \n";
    cout << "Player 1: X, Player 2: O\n\n";
    
    // Draw the top row of the board
    cout << "     |     |     \n";
    cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
    cout << "_____|_____|_____\n";
    
    // Draw the middle row of the board
    cout << "     |     |     \n";
    cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
    cout << "_____|_____|_____\n";
    
    // Draw the bottom row of the board
    cout << "     |     |     \n";
    cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
    cout << "     |     |     \n\n";
}

// This function checks if someone won the game
// It returns 1 if Player 1 (X) wins, 2 if Player 2 (O) wins, 0 if no winner yet
int checkWinner() {
    
    // Check all possible winning combinations
    // There are 8 ways to win: 3 rows, 3 columns, 2 diagonals
    
    // Check rows (horizontal lines)
    if (board[0] == board[1] && board[1] == board[2]) {
        if (board[0] == 'X') return 1;  // Player 1 wins
        if (board[0] == 'O') return 2;  // Player 2 wins
    }
    if (board[3] == board[4] && board[4] == board[5]) {
        if (board[3] == 'X') return 1;
        if (board[3] == 'O') return 2;
    }
    if (board[6] == board[7] && board[7] == board[8]) {
        if (board[6] == 'X') return 1;
        if (board[6] == 'O') return 2;
    }
    
    // Check columns (vertical lines)
    if (board[0] == board[3] && board[3] == board[6]) {
        if (board[0] == 'X') return 1;
        if (board[0] == 'O') return 2;
    }
    if (board[1] == board[4] && board[4] == board[7]) {
        if (board[1] == 'X') return 1;
        if (board[1] == 'O') return 2;
    }
    if (board[2] == board[5] && board[5] == board[8]) {
        if (board[2] == 'X') return 1;
        if (board[2] == 'O') return 2;
    }
    
    // Check diagonals (corner to corner lines)
    if (board[0] == board[4] && board[4] == board[8]) {
        if (board[0] == 'X') return 1;
        if (board[0] == 'O') return 2;
    }
    if (board[2] == board[4] && board[4] == board[6]) {
        if (board[2] == 'X') return 1;
        if (board[2] == 'O') return 2;
    }
    
    // If no one won yet, return 0
    return 0;
}

// This function checks if the board is full (tie game)
bool isBoardFull() {
    // Go through each position on the board
    for (int i = 0; i < 9; i++) {
        // If we find a number (not X or O), board is not full
        if (board[i] != 'X' && board[i] != 'O') {
            return false;  // Board is not full
        }
    }
    return true;  // Board is completely full
}

// Every C++ program starts running from this main function
int main() {
    
    // Variables to store game information
    int player = 1;        // Which player's turn (1 or 2)
    int choice;            // Which position player wants to choose (1-9)
    int winner = 0;        // Who won the game (0 = no winner yet)
    
    // Main game loop - keep playing until someone wins or board is full
    while (winner == 0 && !isBoardFull()) {
        
        // Show the current board
        showBoard();
        
        // Ask current player for their move
        cout << "Player " << player << ", enter your choice (1-9): ";
        cin >> choice;
        
        // Convert choice to array index (1-9 becomes 0-8)
        // We subtract 1 because arrays start at 0, but we show numbers 1-9
        int index = choice - 1;
        
        // Check if the choice is valid
        if (choice < 1 || choice > 9) {
            cout << "Invalid choice! Please enter 1-9.\n";
            continue;  // Skip rest of loop and ask again
        }
        
        // Check if that position is already taken
        if (board[index] == 'X' || board[index] == 'O') {
            cout << "Position already taken! Choose another.\n";
            continue;  // Skip rest of loop and ask again
        }
        
        // Place the player's mark (X or O) on the board
        if (player == 1) {
            board[index] = 'X';  // Player 1 uses X
        } else {
            board[index] = 'O';  // Player 2 uses O
        }
        
        // Check if current player won
        winner = checkWinner();
        
        // Switch to the other player for next turn
        if (player == 1) {
            player = 2;  // Switch from player 1 to player 2
        } else {
            player = 1;  // Switch from player 2 to player 1
        }
    }
    
    // Game is over - show final board
    showBoard();
    
    // Announce the result
    if (winner == 1) {
        cout << "Congratulations! Player 1 (X) wins!\n";
    } else if (winner == 2) {
        cout << "Congratulations! Player 2 (O) wins!\n";
    } else {
        cout << "It's a tie! Good game!\n";
    }
    
    // End the program successfully
    return 0;
}