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

    string Palindrome = S.longestPalindrome(InptString);

    cout << "Longest Palindrome is: " << Palindrome <<  "\n "  << endl;
    return 0;
}
