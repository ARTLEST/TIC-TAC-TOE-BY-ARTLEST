#include <iostream>   // Toolbox for input/output (cin, cout)
#include <cstdlib>    // Toolbox for random numbers (rand, srand)
#include <ctime>      // Toolbox to get current time (used to make AI less predictable)

using namespace std;

// This is our tic-tac-toe board - a simple 3x3 grid
// Each cell starts with a number (1 to 9) to show available positions
char board[9] = {'1','2','3','4','5','6','7','8','9'};

// This function draws the current board on screen
void showBoard() {
    cout << "\n Tic-Tac-Toe Game \n";
    cout << "Player 1: X, AI: O\n\n";
    
    // Draw the top row
    cout << "     |     |     \n";
    cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
    cout << "_____|_____|_____\n";

    // Draw the middle row
    cout << "     |     |     \n";
    cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
    cout << "_____|_____|_____\n";

    // Draw the bottom row
    cout << "     |     |     \n";
    cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
    cout << "     |     |     \n\n";
}

// This function checks if someone has won the game
// It returns 1 if Player 1 wins, 2 if AI wins, 0 if no winner yet
int checkWinner() {
    // All possible winning lines - 3 rows, 3 columns, 2 diagonals
    int lines[8][3] = {
        {0,1,2},{3,4,5},{6,7,8}, // rows
        {0,3,6},{1,4,7},{2,5,8}, // columns
        {0,4,8},{2,4,6}          // diagonals
    };

    // Check each line for 3 same symbols (either all X or all O)
    for (int i = 0; i < 8; i++) {
        int a = lines[i][0];
        int b = lines[i][1];
        int c = lines[i][2];

        if (board[a] == board[b] && board[b] == board[c]) {
            if (board[a] == 'X') return 1;  // Player 1 wins
            if (board[a] == 'O') return 2;  // AI wins
        }
    }

    return 0;  // No winner yet
}

// This function checks if the board is full (tie game)
bool isBoardFull() {
    for (int i = 0; i < 9; i++) {
        // If any cell is still a number, the board is not full
        if (board[i] != 'X' && board[i] != 'O') {
            return false;
        }
    }
    return true;  // No empty spots left
}

// This function chooses a random valid move for the AI
int getAIMove() {
    int options[9];  // To store available positions
    int count = 0;   // How many positions are available

    // Go through the board and find empty spots
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            options[count++] = i;  // Add index to options
        }
    }

    // Pick a random index from the list of available spots
    int randomIndex = rand() % count;
    return options[randomIndex];
}

// Every C++ program starts from the main function
int main() {
    srand(time(0));  // Seed the random number generator (makes AI moves random each time)

    int player = 1;     // 1 = Human, 2 = AI
    int choice;         // Player's move (1 to 9)
    int winner = 0;     // Who won (0 = no one yet)

    // Keep playing until someone wins or the board is full
    while (winner == 0 && !isBoardFull()) {
        // Show the board at the start of each turn
        showBoard();

        if (player == 1) {
            // Player 1's turn (the human)
            cout << "Player 1, enter your choice (1-9): ";
            cin >> choice;

            int index = choice - 1;  // Convert to array index (0-8)

            // Check if input is valid
            if (choice < 1 || choice > 9) {
                cout << "Invalid choice! Enter a number between 1 and 9.\n";
                continue;  // Skip the rest and ask again
            }

            // Check if spot is already taken
            if (board[index] == 'X' || board[index] == 'O') {
                cout << "That spot is already taken! Try another.\n";
                continue;  // Skip the rest and ask again
            }

            // Place X on the board for Player 1
            board[index] = 'X';
        } else {
            // AI's turn (Player 2)
            cout << "AI is thinking...\n";

            int aiMove = getAIMove();  // Get a random valid move
            board[aiMove] = 'O';       // Place O on the board
        }

        // Check if someone won after this move
        winner = checkWinner();

        // Switch turns: 1 → 2, or 2 → 1
        if (player == 1) {
            player = 2;  // Human → AI
        } else {
            player = 1;  // AI → Human
        }
    }

    // Show the final board
    showBoard();

    // Print the result
    if (winner == 1) {
        cout << "Congratulations! Player 1 (X) wins!\n";
    } else if (winner == 2) {
        cout << "AI (O) wins! Better luck next time.\n";
    } else {
        cout << "It's a tie! Good game!\n";
    }

    // End of program
    return 0;
}
