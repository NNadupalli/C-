#include "LongestSubString.h"

LongestSubString::LongestSubString()
{

}


string LongestSubString::longestPalindrome(string s)
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


string LongestSubString:: FindlongestPalindrome(set<string> s)
{
    string output;
    unsigned int max_size = 0;
    for(string subString : s)
        {
        if(subString.length() > max_size)
            {
            max_size = subString.length();
            output = subString;
            }
        }
    return output;
}

