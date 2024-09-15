#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 3;
vector<vector<char>> board(SIZE, vector<char>(SIZE, ' '));

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << " " << board[i][j];
            if (j < SIZE - 1) cout << " |";
        }
        cout << "\n";
        if (i < SIZE - 1) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool isMoveValid(int row, int col) {
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ';
}

void makeMove(int row, int col, char player) {
    board[row][col] = player;
}

bool checkWin(char player) {
    
    for (int i = 0; i < SIZE; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }

    
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == ' ') return false; 
        }
    }
    return true; 
}

void resetBoard() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

void switchPlayer(char& currentPlayer) {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playGame() {
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    while (!gameWon && !gameDraw) {
        displayBoard();
        int row, col;
        
    
        cout << "Player " << currentPlayer << ", enter your move (row and column from 1-3): ";
        cin >> row >> col;

        row--;
        col--; 

        
        if (!isMoveValid(row, col)) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        
        makeMove(row, col, currentPlayer);


        gameWon = checkWin(currentPlayer);
        if (gameWon) {
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        gameDraw = checkDraw();
        if (gameDraw) {
            displayBoard();
            cout << "It's a draw!\n";
            break;
        }

      
        switchPlayer(currentPlayer);
    }
}

int main() {
    char playAgain;

    do {
        resetBoard();
        cout << "Welcome to Tic-Tac-Toe!\n";
        playGame();

        
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! Goodbye!\n";
    return 0;
}
