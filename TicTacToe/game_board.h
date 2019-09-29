#ifndef GAME_BOARD_H
#define GAME_BOARD_H
#include <Qstring>

class Game_board
{
    char places[10] = {'0', '1', '2', '3','4', '5', '6', '7', '8','9'};
    bool isValid(char, char*);

public:
    Game_board();
    void show();
    void update(char location, char playerSymbol);
    int check_win(char *sym);
    void play(QString *, char *) ;
    void clear_board();
};

#endif // GAME_BOARD_H
