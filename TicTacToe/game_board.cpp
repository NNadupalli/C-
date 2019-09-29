#include "main.h"

Game_board::Game_board()
{

}

void Game_board::play(QString *player, char *sym){

    do
    {
        show();
        char choice; int player_number = 0; int count = 0;
        while(player_number <= 1)
        {
            QTextStream(stdout) << player[player_number] << ", choose your location: ";
            QTextStream(stdin) >> choice ;

            // Check if the choice entered is between 1 and 9
            while(choice<='0' || choice>'9' )
            {
                QTextStream(stderr) << "\n**** Error!!! Enter a valid number between 1 and 9 ****\n\n";
                QTextStream(stdout) << player[player_number] << ", choose your location: ";
                QTextStream(stdin) >> choice ;
                if(choice=='1'||choice=='2'||choice=='3'||choice=='4'||choice=='5'||choice=='6'||choice=='7'||choice=='8'||choice=='9')
                    break;
            }

            // check if the choice entered is not already taken
            while(!isValid(choice, sym))
            {
                QTextStream(stderr) << "\n**** Error!!! Choose a location that has not been chosen ****\n\n";
                QTextStream(stdout) << player[player_number] << ", choose your location: ";
                QTextStream(stdin) >> choice ;
                if(isValid(choice, sym))
                        break;
            }

            update(choice,sym[player_number]);

            // Check winner or draw
            if(check_win(sym) == 1)
            {
                QTextStream(stdout) << "\t****** " << player[player_number] << ", You won! ******\n\n"<< endl;
                break;
            }
            else if (check_win(sym) == 0)
            {
                ++player_number;
                ++count;
            }
            else if(check_win(sym)== -1)
            {
                QTextStream(stdout) << "\t Cha!!,  It's a draw :P\n\n"  << endl;
                break;
            }
        }
    }while(check_win(sym)==0);

}


bool Game_board::isValid(char choice, char *sym)
{
    bool a ;
    if((places[int(choice)-48]== sym[0]) || (places[int(choice)-48]== sym[1]))
        a =false;
    else
        a = true;
    return a;
}


void Game_board::show(){
    system("cls");
    QTextStream(stdout)<<"\n\n\t*****************************\n";
    QTextStream(stdout)<<"\t*   Welcome to Tic-Tac-Toe  *\n";
    QTextStream(stdout)<<"\t*****************************\n\n";
    QTextStream(stdout)<<"\t---------|---------|---------\n";
    QTextStream(stdout)<<"\t    " <<places[1]<< "    |    " << places[2] << "    |    "  << places[3] << "    \n";
    QTextStream(stdout)<<"\t---------|---------|---------\n";
    QTextStream(stdout)<<"\t    " <<places[4]<< "    |    " << places[5] << "    |    "  << places[6] << "    \n";
    QTextStream(stdout)<<"\t---------|---------|---------\n";
    QTextStream(stdout)<<"\t    " <<places[7]<< "    |    " << places[8] << "    |    "  << places[9] << "    \n\n\n";
}

void Game_board::update(char i, char x)
{
    if (places[1] == '1' && i== '1')
    {
            places[int(i)-48]=x ;
            show();

    }
    else if(places[2] == '2' && i == '2')
    {
        places[int(i)-48]= x ;
        show();
    }
    else if(places[3] == '3' && i == '3')
    {
        places[int(i)-48]= x ;
        show();
    }
    else if(places[4] == '4' && i == '4')
    {
        places[int(i)-48]= x ;
        show();
    }
    else if(places[5] == '5' && i == '5')
    {
        places[int(i)-48]= x ;
        show();
    }
    else if(places[6] == '6' && i == '6')
    {
        places[int(i)-48]= x ;
        show();
    }
    else if(places[7] == '7' && i == '7')
    {
        places[int(i)-48]= x ;
        show();
    }
    else if(places[8] == '8' && i == '8')
    {
        places[int(i)-48]= x ;
        show();
    }
    else if(places[9] == '9' && i == '9')
    {
        places[int(i)-48]= x ;
        show();
    }

}

int Game_board::check_win(char *sym)
{   
    if(((places[1] == places[2]) && (places[2]== places[3])) ||
       ((places[1] == places[4]) && (places[4]== places[7])) ||
       ((places[2] == places[5]) && (places[5]== places[8])) ||
       ((places[4] == places[5]) && (places[5]== places[6])) ||
       ((places[3] == places[6]) && (places[6]== places[9])) ||
       ((places[7] == places[8]) && (places[8]== places[9])) ||
       ((places[1] == places[5]) && (places[5]== places[9])) ||
       ((places[3] == places[5]) && (places[5]== places[7]))){
        return 1;
    }
    else if ((places [1] == sym[0] || places[1] == sym[1]) &&
             (places [2] == sym[0] || places[2] == sym[1]) &&
             (places [3] == sym[0] || places[3] == sym[1]) &&
             (places [4] == sym[0] || places[4] == sym[1]) &&
             (places [5] == sym[0] || places[5] == sym[1]) &&
             (places [6] == sym[0] || places[6] == sym[1]) &&
             (places [7] == sym[0] || places[7] == sym[1]) &&
             (places [8] == sym[0] || places[8] == sym[1]) &&
             (places [9] == sym[0] || places[9] == sym[1]))
    {
             return -1;
    }
    else {
        return 0;
    }

}

void Game_board::clear_board()
{
//    places[10] = {'0', '1', '2', '3','4', '5', '6', '7', '8','9'};
    places[1] = '1';
    places[2] = '2';
    places[3] = '3';
    places[4] = '4';
    places[5] = '5';
    places[6] = '6';
    places[7] = '7';
    places[8] = '8';
    places[9] = '9';
    show();

}
