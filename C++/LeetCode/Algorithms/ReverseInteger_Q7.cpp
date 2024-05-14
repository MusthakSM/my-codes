#include <iostream>
#include <typeinfo>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        const int maxVal = 2147483647;
        const int minVal = -2147483648;
        
        if(x == maxVal || x == minVal)
        {
            return 0;
        }

        int ABSx = abs(x);

        int ReversedInt = 0;
        while(ABSx != 0)
        {
            int lastDigit = ABSx % 10;

            if (ReversedInt > (numeric_limits<int>::max() - lastDigit) / 10) {
                return 0; // Handle overflow by returning 0 or another appropriate value
            }

            ReversedInt = ReversedInt * 10 + lastDigit;
            ABSx /= 10;
        }

        if(x<0)
        {
            ReversedInt *= -1;
        }

        return ReversedInt;
    }
};

int main(){
    
    int num;
    cin >> num;
    Solution sol;
    cout << sol.reverse(num);
    
}

