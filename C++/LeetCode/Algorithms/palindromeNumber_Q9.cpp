
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string numString = to_string(x);

        string reversed = numString;
        reverse(reversed.rbegin(), reversed.rend());
        
        if(numString == reversed)
        {
            return true;
        }else{
            return false;
        }
    }
};

int main()
{
    int number;
    cin >> number;
    Solution sol;

    if(sol.isPalindrome(number) == 1)
    {
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
}