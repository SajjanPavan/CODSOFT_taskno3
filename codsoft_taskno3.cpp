#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void displayBoard(const vector<vector<char>>& board);
bool isMoveValid(const vector<vector<char>>& board, int row, int col);
bool checkForWin(const vector<vector<char>>& board, char player);
bool checkForDraw(const vector<vector<char>>& board);
void switchPlayer(char& currentPlayer);

int main() {
    const int BOARD_SIZE = 3;
    vector<vector<char>> board(BOARD_SIZE, vector<char>(BOARD_SIZE, ' '));
    char currentPlayer = 'X';
    int row, col;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    do {
        // Display the current state of the board
        displayBoard(board);

        // Player input
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid
        if (isMoveValid(board, row, col)) {
            // Update the board
            board[row - 1][col - 1] = currentPlayer;

            // Check for a win
            if (checkForWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }

            // Check for a draw
            if (checkForDraw(board)) {
                displayBoard(board);
                cout << "It's a draw!" << endl;
                break;
            }

            // Switch players for the next turn
            switchPlayer(currentPlayer);
        } else {
            cout << "Invalid move. Please try again." << endl;
        }

    } while (true);

    cout << "Thanks for playing Tic-Tac-Toe!" << endl;

    return 0;
}

// Function to display the current state of the board
void displayBoard(const vector<vector<char>>& board) {
    cout << "  1 2 3" << endl;
    for (int i = 0; i < board.size(); ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < board[i].size(); ++j) {
            cout << board[i][j];
            if (j < board[i].size() - 1) {
                cout << "|";
            }
        }
        cout << endl;
        if (i < board.size() - 1) {
            cout << "  -----" << endl;
        }
    }
    cout << endl;
}

// Function to check if a move is valid
bool isMoveValid(const vector<vector<char>>& board, int row, int col) {
    return row >= 1 && row <= board.size() && col >= 1 && col <= board[0].size() && board[row - 1][col - 1] == ' ';
}

// Function to check if the current player has won
bool checkForWin(const vector<vector<char>>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < board.size(); ++i) {
        // Check rows and columns
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the game is a draw
bool checkForDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; // There is an empty cell, the game is not a draw
            }
        }
    }
    return true; // All cells are filled, the game is a draw
}

// Function to switch players
void switchPlayer(char& currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}
