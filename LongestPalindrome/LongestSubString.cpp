#include "LongestSubString.h"

LongestSubString::LongestSubString()
{

}


set<string> LongestSubString::longestPalindrome(string s)
{
    set<string> subStrings ;

    int len = s.length();
    for(int i=0; i< len; i++){
        for(int j=i; j<len; j++){
            string subString;
            if(IsPalindrome(s,i,j))
            {
                for(int k = i; k <=j; k++)
                {
                    subString = subString + s[k];
                }
                subStrings.insert(subString);
            }
        }
    }
    return FindlongestPalindrome(subStrings);
}


bool LongestSubString::IsPalindrome(string s, int start, int end)
{
    int flag =0;
    if(start == end)
        return true;
    else
    {
        for(int i=start, j=end; i<=j; i++,j--)
        {
            if(s[i] != s[j])
                return false;
            else
                flag =1;
        }
    }
    if(flag ==1)
        return true;
}


set<string> LongestSubString:: FindlongestPalindrome(set<string> s)
{
    cout << "Do you want to display all the substring palindromes - enter A\nDo you want to print only the longest Palindrome     - enter P " << endl;

    set<string> output;
    char selection;

    cin >> selection;
    while(selection != 'A' and selection != 'P')
    {
        cout << "Enter only valid choices";
        cout << "Do you want to display all the substring palindromes - enter A\nDo you want to print only the longest Palindrome     - enter P " << endl;
        if(selection == 'P' or selection =='A')
            break;
    }

    if(selection == 'P')
    {
        string longest ;
        unsigned int max_size = 0;

        for(string subString : s)
        {
            if(subString.length() > max_size)
                 {
                     max_size = subString.length();
                     output.insert(subString);
                 }
             }

        return output;
    }
    else if(selection == 'A')
    {
        return s;
    }
}

