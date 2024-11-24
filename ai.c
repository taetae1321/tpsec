#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define PLAYER 'X'
#define COMPUTER 'O'
#define EMPTY ' '

// Function to print the Tic Tac Toe board
void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2) {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

// Function to check if any player has won
char checkWinner(char board[3][3]) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY)
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != EMPTY)
            return board[0][i];
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY)
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY)
        return board[0][2];
    // No winner
    return EMPTY;
}

// Function to check if the board is full
bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == EMPTY)
                return false;
    return true;
}

// Minimax algorithm
int minimax(char board[3][3], bool isMaximizing) {
    char winner = checkWinner(board);
    if (winner == COMPUTER) return 10;
    if (winner == PLAYER) return -10;
    if (isBoardFull(board)) return 0;

    int bestScore = isMaximizing ? INT_MIN : INT_MAX;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = isMaximizing ? COMPUTER : PLAYER;
                int score = minimax(board, !isMaximizing);
                board[i][j] = EMPTY;
                bestScore = isMaximizing ? (score > bestScore ? score : bestScore) : (score < bestScore ? score : bestScore);
            }
        }
    }
    return bestScore;
}

// Find the best move for the computer
void bestMove(char board[3][3]) {
    int bestScore = INT_MIN;
    int moveRow = -1, moveCol = -1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = COMPUTER;
                int score = minimax(board, false);
                board[i][j] = EMPTY;
                if (score > bestScore) {
                    bestScore = score;
                    moveRow = i;
                    moveCol = j;
                }
            }
        }
    }
    board[moveRow][moveCol] = COMPUTER;
}

int main() {
    char board[3][3] = {
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY}
    };

    printf("Tic Tac Toe Game\n");
    printf("Player: %c, Computer: %c\n", PLAYER, COMPUTER);
    printBoard(board);

    while (true) {
        // Player's move
        int row, col;
        printf("Enter your move (row and column: 0, 1, or 2): ");
        scanf("%d %d", &row, &col);
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != EMPTY) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        board[row][col] = PLAYER;
        printBoard(board);

        // Check if player wins
        if (checkWinner(board) == PLAYER) {
            printf("You win!\n");
            break;
        }
        if (isBoardFull(board)) {
            printf("It's a draw!\n");
            break;
        }

        // Computer's move
        bestMove(board);
        printBoard(board);

        // Check if computer wins
        if (checkWinner(board) == COMPUTER) {
            printf("Computer wins!\n");
            break;
        }
        if (isBoardFull(board)) {
            printf("It's a draw!\n");
            break;
        }
    }

    return 0;
}
