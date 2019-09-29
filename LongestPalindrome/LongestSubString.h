#ifndef LONGESTSUBSTRING_H
#define LONGESTSUBSTRING_H

#include <string>
#include <set>
#include <iostream>

using namespace std;

class LongestSubString
{
public:
    LongestSubString();
    string longestPalindrome(string s);
    bool IsPalindrome(string s, int start, int end);
    string FindlongestPalindrome(set<string> s);

};

#endif // LONGESTSUBSTRING_H
