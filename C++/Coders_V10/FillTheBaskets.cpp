#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    int n, m, c;
    cin >> n;
    cin >> m;

    vector<int>ballValArray;
    for (int i=0; i<m; i++)
    {
        int value;
        cin >> value;
        ballValArray.push_back(value);
    }

    cin >> c;

    // Use sort with a custom sorting criterion to sort the vector in descending order
    sort(ballValArray.begin(), ballValArray.end(), greater<int>());

    int finalValue = 0;
    for (int i=0; i<n; i++)
    {
        if(ballValArray.empty() == 1)
        {
            finalValue += 10;
            continue;
        }else{
            int filledValue = ballValArray[0];
            ballValArray.erase(ballValArray.begin()+0);

            for (int j=0; j<ballValArray.size(); j++)
            {
                if( filledValue + ballValArray[j] < c)
                {
                    filledValue += ballValArray[j];
                    ballValArray.erase(ballValArray.begin()+j);
                    j--;

                }else if(filledValue + ballValArray[j] == c){
                    ballValArray.erase(ballValArray.begin()+j);
                    break;
                }
            }
            
        }
    }

    if (m == 0)
    {
        finalValue = n*10;
    }

    cout << finalValue;

    return 0;
}
