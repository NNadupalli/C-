#ifndef GRID_H
#define GRID_H
#include <iostream>


class GRID
{
public:
    int grid[9][9] = { {0,0,0,5,8,0,0,0,0},
                       {8,3,0,0,0,2,6,0,0},
                       {0,0,2,0,0,1,0,9,0},
                       {3,9,0,0,0,0,7,0,6},
                       {6,0,0,0,0,0,0,0,9},
                       {2,0,8,0,0,0,0,3,5},
                       {0,8,0,4,0,0,9,0,0},
                       {0,0,7,3,0,0,0,4,1},
                       {0,0,0,0,1,5,0,0,0}
                     } ;
    GRID();
    void display_board();
    void set_grid();
    bool check_row(int num , int row);
    bool check_col(int num , int col);
    bool check_block(int num , int row, int col);
    bool valid_number(int row, int col, int num);
    std::pair<int,int> find_empty_cell();
    bool solve();

};

#endif // GRID_H
