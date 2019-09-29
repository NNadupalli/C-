#include <QCoreApplication>
#include "GRID.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    GRID puzzle;
    puzzle.display_board();
    puzzle.solve();

    return 0;
}
