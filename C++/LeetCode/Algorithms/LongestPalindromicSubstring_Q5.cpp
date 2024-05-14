#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:

    string expand(string s, int left, int right)
    {
        while(left>=0 && right<=s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }

        return s.substr(left+1, right-left-1); 
    }
public:
    string longestPalindrome(string s) {
                int len = s.length();
        if(len<=1)
            return s;

        string LP = ""; // Longest Palindrome...

        for (int i=0; i<len; i++)
        {
            string result1, result2;
            result1 = expand(s, i, i); // result of the expand() function..
            if(result1.length()>LP.length())
            {
                LP = result1;
            }

            result2 = expand(s, i, i+1);
            if(result2.length()>LP.length())
            {
                LP = result2;
            }
        }

        return LP;
    }
};