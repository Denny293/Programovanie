#include <stdio.h>
#include <stdbool.h>

#define SIZE 4

struct game 
{
    char board[SIZE][SIZE];
    int score;
};

bool is_game_won(const struct game game);
bool is_move_possible(const struct game game);
bool update(struct game *game, int dy, int dx);

int main() {
    struct game game = {
        .board = {
        {' ', ' ', 'C', ' '},
        {'A', 'C', 'C', 'C'},
        {'A', ' ', 'C', 'C'},
        {'A', 'A', 'C', 'C'}
    },

        .score = 0
    };
    
    printf("is won: %d\n", is_game_won(game));
    printf("is move possible: %d\n", is_move_possible(game));

    for (int j = 0; j < SIZE; j++) {
            for (int i = 0; i < SIZE; i++) {
                printf("%c", game.board[j][i]);
            }
            printf("\n");
        }

        printf("\n \n");

    update(&game, 0, 1);

    
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

bool update(struct game *game, int dy, int dx) {
    int c = 0;
    char na;
    if (dy == dx) {
        return false;
    } else if (dx == 1) {
        for (int j = 0; j < SIZE; j++) {
            for (int i = 0; i < SIZE; i++) {
                if (game->board[j][i] == ' ') {
                    game->board[j][i] = game->board[j][i - 1];
                    game->board[j][i - 1] = ' ';
                }

                if (game->board[j][2] == ' ') {
                    game->board[j][2] = game->board[j][1];
                    game->board[j][1] = ' ';
                }

                if (game->board[j][4 - i] == ' ') {
                    game->board[j][4 - i] = game->board[j][3 - i];
                    game->board[j][3 - i] = ' ';
                }
                
                for (int j = 0; j < SIZE; j++) {
                    for (int i = 0; i < SIZE; i++) {
                        printf("%c", game->board[j][i]);
                    }
                    printf("\n");
                }
                printf("\n");

            }
        }

        for (int j = 0; j < SIZE; j++) {
            for (int i = 0; i < SIZE; i++) {
                if (game->board[j][4 - i] == game->board[j][3 - i] && game->board[j][3 - i] != ' ') {
                    game->board[j][4 - i] = game->board[j][3 - i] + 1;
                    game->board[j][3 - i] = ' ';
                }
                
                if (game->board[j][3 - i] == ' ' && i != 3) {
                    game->board[j][3 - i] = game->board[j][2 - i];
                    game->board[j][2 - i] = ' ';
                }

                if (game->board[j][4 - i] == game->board[j][3 - i] && game->board[j][3 - i] != ' ') {
                    game->board[j][4 - i] = game->board[j][3 - i] + 1;
                    game->board[j][3 - i] = ' ';
                }
                
                for (int j = 0; j < SIZE; j++) {
                    for (int i = 0; i < SIZE; i++) {
                        printf("%c", game->board[j][i]);
                    }
                    printf("\n");
                }
                printf("\n");

            }
        }
    }
}
