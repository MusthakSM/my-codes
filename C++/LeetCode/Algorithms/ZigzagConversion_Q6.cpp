#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length() == numRows || numRows == 1)
        {
            return s;
        }

        string result = "";
 
        for(int i=0; i<numRows; i++)
        {
            int row = i+1;
            int changeDirection = 0;
            for (int j=i; j<s.length(); j++)
            {

                if (row == i+1)
                {
                    result += s[j];
                }

                if(row == numRows && changeDirection  == 0){
                changeDirection = 1;
                }
                else if(row == 1 && changeDirection == 1)
                {
                    changeDirection = 0;
                }
                

                if(changeDirection == 0)
                {
                    row++;
                }else{
                    row--;
                }

            }
            


        }
        return result;
    }
};

int main()
{
    string s;
    int row;
    cin >> s;
    cin >> row;

    Solution sol;
    cout << sol.convert(s, row);
}