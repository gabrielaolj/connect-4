#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// Define constants for the board dimensions
#define ROWS 6
#define COLUMNS 7

// Function to print the board
void print_board(char board[ROWS][COLUMNS]) {
    printf("|--|--|--|--|--|--|--|\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("| %c", board[i][j]);
        }
        printf("|\n");
        printf("|--|--|--|--|--|--|--|\n");
    }
    printf(" 1  2  3  4  5  6  7\n");
}

// Function to make a move on the board
bool make_move(char board[ROWS][COLUMNS], int column, char player) {
    if (column < 1 || column > COLUMNS) {
        printf("Invalid column number. Please choose a column between 1 and 7.\n");
        return false;
    }

    // Check if the column is already full
    if (board[0][column - 1] != ' ') {
        printf("Illegal move, column full!\n");
        return false;
    }

    // Find the first available row in the selected column
    int row = ROWS - 1;
    while (row >= 0 && board[row][column - 1] != ' ') {
        row--;
    }

    // Make the move
    board[row][column - 1] = player;

    return true;
}

// check_win(board) returns true if the given player has 4 connected
//   pieces on the board
bool check_win(char board[6][7], char player){
  
  
  //checking columns
  for (int i=0; i<6; i++){
    for(int j=0; j<7; j++){
      if (board[i][j] == player && board[i][j+1] == player && board[i][j+2] == player &&board[i][j+3] == player)
       return true;
    }
  }

  //checking rows
  for (int j=0; j<6; j++){
    for(int i=0; i<7; i++){
      if (board[i][j] == player && board[i+1][j] == player && board[i+2][j] == player &&board[i+3][j] == player)
        return true;
    }
  }

  //checking diagonals
    int count = 0;
    int c = 0;
    // first diagonal 
    while(c != 4){
        if(board[3-c][0+c] == player){
            count++;
        }

        if(board[3-c][0+c] != player){
            count = 0;
        }

        if(count == 4){
            return true;
        }
        c++;
    }

    // second diagonal
    c = 0;
    count = 0;
    while(c != 5){
        if(board[4-c][0+c] == player){
            count++;
        }

        if(board[4-c][0+c] != player){
            count = 0;
        }

        if(count == 4){
            return true;
        }
        c++;
    }

    // third diagonal
    c = 0;
    count = 0;
    while(c != 6){
        if(board[5-c][0+c] == player){
            count++;
        }

        if(board[5-c][0+c] != player){
            count = 0;
        }

        if(count == 4){
            return true;
        }
        c++;
    }

    // fourth diagonal
    c = 0;
    count = 0;
    while(c != 6){
        if(board[5-c][1+c] == player){
            count++;
        }

        if(board[5-c][1+c] != player){
            count = 0;
        }

        if(count == 4){
            return true;
        }
        c++;
    }

    // fith diagonal
    c = 0;
    count = 0;
    while(c != 5){
        if(board[5-c][2+c] == player){
            count++;
        }

        if(board[5-c][2+c] != player){
            count = 0;
        }

        if(count == 4){
            return true;
        }
        c++;
    }

    // sixth diagonal
    c = 0;
    count = 0;
    while(c != 4){
        if(board[5-c][3+c] == player){
            count++;
        }

        if(board[5-c][3+c] != player){
            count = 0;
        }

        if(count == 4){
            return true;
        }
        c++;
    }

// diagonal \ check
    // first diagonal
    c = 0;
    count = 0;
    while(c != 4){
        if(board[3-c][6-c] == player){
            count++;
        }

        if(board[3-c][6-c] != player){
            count = 0;
        }

        if(count == 4){
            return true;
        }
        c++;
    }

    // second diagonal
    c = 0;
    count = 0;
    while(c != 5){
        if(board[4-c][6-c] == player){
            count++;
        }

        if(board[4-c][6-c] != player){
            count = 0;
        }

        if(count == 4){
            return true;
        }
        c++;
    }

    // third diagonal
    c = 0;
    count = 0;
    while(c != 6){
        if(board[5-c][6-c] == player){
            count++;
        }

        if(board[5-c][6-c] != player){
            count = 0;
        }

        if(count == 4){
            return true;
        }
        c++;
    }

    // fourth diagonal
    c = 0;
    count = 0;
    while(c != 6){
        if(board[5-c][5-c] == player){
            count++;
        }

        if(board[5-c][5-c] != player){
            count = 0;
        }

        if(count == 4){
            return true;
        }
        c++;
    }

    //fith diagonal
    c = 0;
    count = 0;
    while(c != 5){
        if(board[5-c][4-c] == player){
            count++;
        }

        if(board[5-c][4-c] != player){
            count = 0;
        }

        if(count == 4){
            return true;
        }
        c++;
    }

    //sixth diagonal
    c = 0;
    count = 0;
    while(c != 4){
        if(board[5-c][3-c] == player){
            count++;
        }

        if(board[5-c][3-c] != player){
            count = 0;
        }

        if(count == 4){
            return true;
        }
        c++;
    }
 return false; // Replace this with the actual win-checking result
}

bool is_board_full(char board[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main(void) {
    char board[ROWS][COLUMNS];
    char player = 'X';
    int play_again = 1;

    while (play_again) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                board[i][j] = ' ';
            }
        }

        print_board(board);

        while (1) {
            int column;

            printf("Player %c, pick a column to drop your token: ", player);
            scanf("%d", &column);

            if (make_move(board, column, player)) {
                print_board(board);

                if (check_win(board, player)) {
                    printf("Player %c wins!\n", player);
                    break;
                }

                if (is_board_full(board)) {
                    printf("It's a tie!\n");
                    break;
                }

                player = (player == 'X') ? 'O' : 'X';
            }
        }

        printf("Do you want to play again? (1 for yes, 0 for no): ");
        scanf("%d", &play_again);
    }

    return 0;
}