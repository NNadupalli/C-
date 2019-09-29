#include "main.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QString player[2] ;
    char sym[2];
    Game_board  game1;


        // Player 1 details
        QTextStream(stdout) << "Player1, enter your name: " ;  QTextStream(stdin)>>  player[0];
        QTextStream(stdout) << player[0] <<  ", choose your symbol: " ; QTextStream(stdin) >> sym[0];


        // Player 2 details
        QTextStream(stdout) << "\nPlayer2, enter your name: ";
//        cin.ignore(1000, '\n');
        QTextStream(stdin) >>  player[1];
        QTextStream(stdout) << player[1] <<  ", choose your symbol: " ; QTextStream(stdin) >> sym[1];

        while(sym[0] == sym[1]){
            QTextStream(stderr)<< "\n****Error!!! Choose a different symbol than "<< player[0] << "\n" << endl;
            QTextStream(stdout) << player[1] <<  ", enter your symbol: " ; QTextStream(stdin) >> sym[1];
        }

        game1.play(player, sym);

        while(true)
        {
            char play_again;
            QTextStream(stdout) << "Continue playing? y or n: " << endl;
            QTextStream(stdin) >> play_again;
            if(play_again == 'y')
            {
                game1.clear_board();
                game1.play(player, sym);
            }
            else {
                break;
            }

        }






    return 0;
}
