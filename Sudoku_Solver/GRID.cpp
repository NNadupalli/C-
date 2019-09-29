#include "GRID.h"
using namespace std;

GRID::GRID()
{


}

void GRID:: display_board()
{
    cout <<"\n\n\t*********************************************************************************************\n";
    cout <<"\t\t\t\t\t    *  Sudoku Solver  *\n";
    cout <<"\t*********************************************************************************************\n\n";
    cout <<"\t|    " <<"0"<<"    |" <<"    1"<<"    |" <<"    2"<<"    |" <<"    3"<<"     |" <<"    4"<<"    |" <<"    5"<<"    |" <<"     6"<<"    |" <<"    7"<<"    |" <<"      8"<<"  |" << "\n\n\n" ;
    cout <<"\t|-------------------------------------------------------------------------------------------|\n";
    cout <<"\t|    " <<grid[0][0]<< "    |    " << grid[0][1] << "    |    "  << grid[0][2] << "    ||    "  << grid[0][3] << "    |    "  << grid[0][4] << "    |    "  << grid[0][5] << "    ||    "  << grid[0][6] << "    |    "  << grid[0][7] << "    |    "  << grid[0][8] << "    |\n" ;
    cout <<"\t|-----------------------------||-----------------------------||-----------------------------|\n";
    cout <<"\t|    " <<grid[1][0]<< "    |    " << grid[1][1] << "    |    "  << grid[1][2] << "    ||    "  << grid[1][3] << "    |    "  << grid[1][4] << "    |    "  << grid[1][5] << "    ||    "  << grid[1][6] << "    |    "  << grid[1][7] << "    |    "  << grid[1][8] << "    |\n" ;
    cout <<"\t|-----------------------------||-----------------------------||-----------------------------|\n";
    cout <<"\t|    " <<grid[2][0]<< "    |    " << grid[2][1] << "    |    "  << grid[2][2] << "    ||    "  << grid[2][3] << "    |    "  << grid[2][4] << "    |    "  << grid[2][5] << "    ||    "  << grid[2][6] << "    |    "  << grid[2][7] << "    |    "  << grid[2][8] << "    |\n" ;
    cout <<"\t|*******************************************************************************************|\n";
    cout <<"\t|    " <<grid[3][0]<< "    |    " << grid[3][1] << "    |    "  << grid[3][2] << "    ||    "  << grid[3][3] << "    |    "  << grid[3][4] << "    |    "  << grid[3][5] << "    ||    "  << grid[3][6] << "    |    "  << grid[3][7] << "    |    "  << grid[3][8] << "    |\n" ;
    cout <<"\t|-----------------------------||-----------------------------||-----------------------------|\n";
    cout <<"\t|    " <<grid[4][0]<< "    |    " << grid[4][1] << "    |    "  << grid[4][2] << "    ||    "  << grid[4][3] << "    |    "  << grid[4][4] << "    |    "  << grid[4][5] << "    ||    "  << grid[4][6] << "    |    "  << grid[4][7] << "    |    "  << grid[4][8] << "    |\n" ;
    cout <<"\t|-----------------------------||-----------------------------||-----------------------------|\n";
    cout <<"\t|    " <<grid[5][0]<< "    |    " << grid[5][1] << "    |    "  << grid[5][2] << "    ||    "  << grid[5][3] << "    |    "  << grid[5][4] << "    |    "  << grid[5][5] << "    ||    "  << grid[5][6] << "    |    "  << grid[5][7] << "    |    "  << grid[5][8] << "    |\n" ;
    cout <<"\t|*******************************************************************************************|\n";
    cout <<"\t|    " <<grid[6][0]<< "    |    " << grid[6][1] << "    |    "  << grid[6][2] << "    ||    "  << grid[6][3] << "    |    "  << grid[6][4] << "    |    "  << grid[6][5] << "    ||    "  << grid[6][6] << "    |    "  << grid[6][7] << "    |    "  << grid[6][8] << "    |\n" ;
    cout <<"\t|-----------------------------||-----------------------------||-----------------------------|\n";
    cout <<"\t|    " <<grid[7][0]<< "    |    " << grid[7][1] << "    |    "  << grid[7][2] << "    ||    "  << grid[7][3] << "    |    "  << grid[7][4] << "    |    "  << grid[7][5] << "    ||    "  << grid[7][6] << "    |    "  << grid[7][7] << "    |    "  << grid[7][8] << "    |\n" ;
    cout <<"\t|-----------------------------||-----------------------------||-----------------------------|\n";
    cout <<"\t|    " <<grid[8][0]<< "    |    " << grid[8][1] << "    |    "  << grid[8][2] << "    ||    "  << grid[8][3] << "    |    "  << grid[8][4] << "    |    "  << grid[8][5] << "    ||    "  << grid[8][6] << "    |    "  << grid[8][7] << "    |    "  << grid[8][8] << "    |\n" ;
    cout <<"\t|*******************************************************************************************|\n\n\n";

}

void GRID::set_grid()
{
    cout << "Enter initial values of the sudoku puzzle " << "\n";
    cout << "Row ,Column ,Value \n" ;
    int row, col, value;
    while(cin >> row >> col >> value)
    {
        grid[row][col] = value ;
        display_board();
        cout << "Row:  , Column: , Value:  \n" ;
    }

}

bool GRID::check_row(int num, int row)
{
    for(int i = 0; i<=8 ; ++i)
    {
        if(grid[row][i] == num )
            return false;
    }
    return true;
}

bool GRID::check_col(int num, int col)
{
    for(int i = 0; i<=8 ; ++i)
    {
        if(grid[i][col] == num )
            return false;
    }
    return true;
}


bool GRID::check_block(int num, int startRow, int startCol)
{
    for(int row=0; row<3;++row)
    {
        for(int col = 0; col <3 ; ++col)
        {
            if(grid[row+startRow][col+startCol] == num)
                return false;
        }
    }
    return true;
}

bool GRID:: valid_number(int row, int col, int num)
{
    if(check_row(num, row) && check_col(num, col) && check_block(num, row-row%3, col-col%3))
        return true;
    else
        return false;
}


pair<int, int> GRID::find_empty_cell()
{
     pair <int, int> cell;

     for(int i = 0; i <9; ++i)
    {
      for (int j=0; j <9; ++j)
      {
        if(grid[i][j] == 0)
        {
            cell = make_pair(i,j);
//            cout << cell.first << " " << cell.second << "\n";
            return cell;
        }

      }

    }
    return make_pair(9,9);
}

bool GRID::solve()
{

    if(make_pair(9,9) == find_empty_cell())
        return true;

    pair<int, int> cell = find_empty_cell();
    int row = cell.first;
    int col = cell.second;

//    cout << " " << row << " " << col <<"\n";
    for(int num = 1; num <=9; ++num)
    {
//        cout << num << "\n";
        if(valid_number(row, col, num))
        {
            grid[row][col]=num;
             display_board();
            if(solve())
                return true;
            grid[row][col] = 0;
        }
     }
//    display_board();
    return false;
}
