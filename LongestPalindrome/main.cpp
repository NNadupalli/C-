#include <QCoreApplication>
#include <iostream>
#include <string>
#include "LongestSubString.h"


using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    string InptString;
    LongestSubString S;
    cout << "Enter the string: " << endl;
    getline(cin, InptString);

    set<string> Palindromes = S.longestPalindrome(InptString);
    set<string> :: iterator it;

    cout << "\nSelected Palindrome(s)" << "\n" ;
    for (it = Palindromes.begin(); it!=Palindromes.end() ; ++it )
        cout << *it << "\n " ;
    return 0;
}
