#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

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
        {' ', ' ', ' ', 'F'},
        {'A', 'B', 'J', 'A'},
        {'A', 'D', 'F', 'C'},
        {'D', 'C', 'A', 'J'}
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

    for (int j = 0; j < SIZE; j++) {
            for (int i = 0; i < SIZE; i++) {
                printf("%c", game.board[j][i]);
            }
            printf("\n");
        }

    //     printf("\n ############ \n");
    //     printf("%d\n", game.score);

    // update(&game, -1, 0);

    // for (int j = 0; j < SIZE; j++) {
    //         for (int i = 0; i < SIZE; i++) {
    //             printf("%c", game.board[j][i]);
    //         }
    //         printf("\n");
    //     }
        
    //     printf("\n ############ \n");
    //     printf("%d\n", game.score);
    
    //  update(&game, 0, -1);

    // for (int j = 0; j < SIZE; j++) {
    //         for (int i = 0; i < SIZE; i++) {
    //             printf("%c", game.board[j][i]);
    //         }
    //         printf("\n");
    //     }
        
    //     printf("\n ############ \n");
    //     printf("%d\n", game.score);

    printf("is won: %d\n", is_game_won(game));
    printf("is move possible: %d\n", is_move_possible(game));

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
    int counterr = 0;
    int counter = 1;
    int number_65 = 65;
    int number_score = 1;
    srand(time(NULL));
    if (dy == dx) {
        return false;
    } else if (dy != 0 && dx != 0) {
        return false;
    } else if (dx == 1) {
        for (int j = 0; j < SIZE; j++) {
            for (int i = 0; i < SIZE; i++) {
               if (i != 0){
                    if (game->board[j][i] == ' ') {
                        game->board[j][i] = game->board[j][i - 1];
                        game->board[j][i - 1] = ' ';
                    }
               
                    if (game->board[j][4 - i] == ' ') {
                        game->board[j][4 - i] = game->board[j][3 - i];
                        game->board[j][3 - i] = ' ';
                    }
               }
            }
        }

        for (int j = 0; j < SIZE; j++) {
            for (int i = 0; i < SIZE; i++) {
                if (game->board[j][4 - i] == game->board[j][3 - i] && game->board[j][3 - i] != ' ' && i != 0) {
                    game->board[j][4 - i] = game->board[j][3 - i] + 1;
                    while (game->board[j][4 - i] >= number_65) {
                        number_score *= 2;
                        number_65++;
                    }
                    game->score += number_score;
                    game->board[j][3 - i] = ' ';
                }
            }
        }

        for (int j = 0; j < SIZE; j++) {
            for (int i = 0; i < SIZE; i++) {
                if (game->board[j][4 - i] == ' ' && i != 0) {
                    game->board[j][4 - i] = game->board[j][3 - i];
                    game->board[j][3 - i] = ' ';
                }
            }
        }
    } else if (dy == -1) {
        for (int j = 0; j < SIZE; j++) {
            for (int i = 0; i < SIZE; i++) {
               if (j != 0){
                    if (game->board[j][i] == ' ') {
                        game->board[j][i] = game->board[j - 1][i];
                        game->board[j - 1][i] = ' ';
                    }
                
                    if (game->board[4 - j][i] == ' ') {
                        game->board[4 - j][i] = game->board[3 - j][i];
                        game->board[3 - j][i] = ' ';
                    }
               }
            }
        }

        for (int j = 0; j < SIZE; j++) {
            for (int i = 0; i < SIZE; i++) {
                if (game->board[4 - j][i] == game->board[3 - j][i] && game->board[3 - j][i] != ' ' && j != 0) {
                    game->board[4 - j][i] = game->board[3 - j][i] + 1;
                    while (game->board[4 - j][i] >= number_65) {
                        number_score *= 2;
                        number_65++;
                    }
                    game->score += number_score;
                    game->board[3 - j][i] = ' ';
                }
            }
        }

        for (int j = 0; j < SIZE; j++) {
            for (int i = 0; i < SIZE; i++) {
                if (game->board[4 - j][i] == ' ' && j != 0) {
                    game->board[4 - j][i] = game->board[3 - j][i];
                    game->board[3 - j][i] = ' ';
                }
            }
        }
    } else if (dx == -1) {
        for (int j = 0; j < SIZE; j++) {
            for (int i = 0; i < SIZE; i++) {
               if (i != 0) { 
                    if (game->board[j][3 - i] == ' ') {
                        game->board[j][3 - i] = game->board[j][4 - i];
                        game->board[j][4 - i] = ' ';
                    }
                
                    if (game->board[j][i - 1] == ' ') {
                        game->board[j][i - 1] = game->board[j][i];
                        game->board[j][i] = ' ';
                    }
                }
            }
        }

        for (int j = 0; j < SIZE; j++) {
            for (int i = 0; i < SIZE; i++) {
                if (game->board[j][i] == game->board[j][i + 1] && game->board[j][i + 1] != ' ' && i != 3) {
                    game->board[j][i] = game->board[j][i + 1] + 1;
                    while (game->board[j][i] >= number_65) {
                        number_score *= 2;
                        number_65++;
                    }
                    game->score += number_score;
                    game->board[j][i + 1] = ' ';
                }
            }
        }

        for (int j = 0; j < SIZE; j++) {
            for (int i = 0; i < SIZE; i++) {
                if (game->board[j][i] == ' ' && i != 3) {
                    game->board[j][i] = game->board[j][i + 1];
                    game->board[j][i + 1] = ' ';
                }
            }
        }
    } else if (dy == 1){
        for (int j = 0; j < SIZE; j++) {
            for (int i = 0; i < SIZE; i++) {
               if (j != 0) { 
                    if (game->board[3 - j][i] == ' ') {
                        game->board[3 - j][i] = game->board[4 - j][i];
                        game->board[4 - j][i] = ' ';
                    }
               
                    if (game->board[j - 1][i] == ' ') {
                        game->board[j - 1][i] = game->board[j][i];
                        game->board[j][i] = ' ';
                    }
                }
            }
        }

        for (int j = 0; j < SIZE; j++) {
            for (int i = 0; i < SIZE; i++) {
                if (game->board[j][i] == game->board[j + 1][i] && game->board[j + 1][i] != ' ' && j != 3) {
                    game->board[j][i] = game->board[j + 1][i] + 1;
                    while (game->board[j][i] >= number_65) {
                        number_score *= 2;
                        number_65++;
                    }
                    game->score += number_score;
                    game->board[j + 1][i] = ' ';
                }
            }
        }

         for (int j = 0; j < SIZE; j++) {
            for (int i = 0; i < SIZE; i++) {
                if (game->board[j][i] == ' ' && j != 3) {
                    game->board[j][i] = game->board[j + 1][i];
                    game->board[j + 1][i] = ' ';
                }
            }
        }
    }

    for (int j = 0; j < SIZE; j++) {
            for (int i = 0; i < SIZE; i++) {
                if (game->board[j][i] == ' ') {
                    counterr++;
                }
            }
        }

    if (counterr == 1) {
        counter = 2;
    }
 
    
    while (counter != 3 && counterr != 0) {
        int j = rand() % 4;
        int i = rand() % 4;
        if (game->board[j][i] == ' ' && counter == 1) {
            game->board[j][i] = 'A';
            counter++;
        } else if (game->board[j][i] == ' ' && counter == 2) {
            game->board[j][i] = 'B';
            counter++;
        }
    }
        
    

    return true;
    
    
}