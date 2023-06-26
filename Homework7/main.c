#include <stdio.h>
#include <stdbool.h>

#define SIZE 4

bool is_game_won(const struct game game);
bool is_move_possible(const struct game game);

struct game 
{
    char board[SIZE][SIZE];
    int score;
};


int main() {
    struct game game = {
        .board = { {'A', 'B', 'C', 'D'},
        {'E', 'F', 'G', 'H'},
        {'I', 'J', 'K', 'A'},
        {'B', 'C', 'D', 'E'}
        },
        .score = 0
    };
    
    printf("is won: %d\n", is_game_won(game));

    return 0;
}

bool is_game_won(const struct game game){
    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE; i++) {
            if (game.board[j][i] == 'K') {
                return true;
            } 
        }
    }
    return false;
}

bool is_move_possible(const struct game game){
    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE; i++) {
            if (game.board[j][i] == ' ') {
                return true;
            }
            else if (game.board[j][i] == game.board[j][i + 1]) {
                return true;
            }
            else if (game.board[j][i] == game.board[j + 1][i]) {
                return true;
            }
        }
    }
    return false;
}