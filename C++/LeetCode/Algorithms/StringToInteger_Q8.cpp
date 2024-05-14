#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <climits>
using namespace std;

class Solution {

private: 
    int nonSpaceIndex(string s, int index)
    {
        if(s[index] == ' ')
        {
            return index + nonSpaceIndex(s, index+1);
        }else{
            return index;
        }
    }
public:
    int myAtoi(string s) {
        
        int nonSpaceCharIndex = nonSpaceIndex(s, 0);

        s = s.substr(nonSpaceCharIndex);

        long extractedInteger;
        istringstream iss(s);
        long result;

        if(isdigit(s[0]) || (isdigit(s[1]) && (s[0] == '-' || s[0] == '+')))
            if(iss >> extractedInteger)
            {
                if(extractedInteger > INT_MAX)
                {
                    result = INT_MAX;
                }else if(extractedInteger < INT_MIN)
                {
                    result= INT_MIN;
                }
                else{
                    result = (int)extractedInteger;
                }
            }else{
                if(isdigit(s[1]) && (s[0] == '-'))
                    result = (int)INT_MIN;
                else if ( (isdigit(s[1]) && (s[0] == '-')) || isdigit(s[0]) )
                    result = (int)INT_MAX;
            }
        else{
            result = 0;
        }

        return result;
    }
};

int main()
{
    string numString;
    cin >> numString;

    Solution sol;
    cout << sol.myAtoi(numString);

}