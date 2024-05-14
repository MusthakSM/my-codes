#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){

    string S, suffix;
    cin >> S;
    long long stringlen = S.size();

    suffix = S;

    long long wordScore = stringlen;

    for (long long i=1; i<stringlen; i++)
    {
        string suffix = S.substr(i);
        long long suffixLength = suffix.size();

        for (int j=0; j<suffixLength; j++)
        {
            if (S[j] == suffix[j])
            {
                ++wordScore;
            }else{
                break;  
            }
        }
        
    }

    cout << wordScore;

    return 0;
}
