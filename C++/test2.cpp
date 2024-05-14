#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void findLCM(int **matrix, int l[], int m[], int rowMax, int colMax)
{
    vector<int>LCMreverse;
    while(rowMax > 0 && colMax > 0)
    {
            if(l[rowMax-1] == m[colMax-1])
            {
                LCMreverse.push_back(l[rowMax-1]);
                --rowMax;
                --colMax;
            }else{
                if(matrix[rowMax][colMax-1] <= matrix[rowMax-1][colMax])
                {
                    --rowMax;
                }else{
                    --colMax;
                }
            }
    }

    // Using the reverse function
    reverse(LCMreverse.begin(), LCMreverse.end());

    // Print the reversed vector
    for (const auto& num : LCMreverse) {
        cout<< num << " ";
    }
}

int main(void)
{
    int p, q;   // size of the sequences l and m respectively..
    cin >> p >> q;

    int l[p];   // sequence l 
    int m[q];   // sequence m

    int **LCSMatrix = new int*[p+1];
    // initialize all the elements of LCSMatrix to be 0
    for (int i=0; i<p+1; i++)
    {
        LCSMatrix[i] = new int[q+1];
        for(int j=0; j<q+1; j++)
        {
            LCSMatrix[i][j] = 0;
        }
    }

    for(int i=0; i<p; i++)
    {
        cin >> l[i];
    }

    for(int i=0; i<q; i++)
    {
        cin >> m[i];
    }


    for (int i=1; i<p+1; i++)
    {
        for(int j=1; j<q+1; j++)
        {
            if(l[i-1] == m[j-1])
            {
                LCSMatrix[i][j] = LCSMatrix[i-1][j-1] + 1;
            }else{
                LCSMatrix[i][j] = max(LCSMatrix[i][j-1], LCSMatrix[i-1][j]);
            }
        }
    }    

    // Finding the Longest Common Subsequence by traversing through the LCSMatrix..

    for (int i=1; i<p+1; i++)
    {
        for(int j=1; j<q+1; j++)
        {
            if(l[i-1] == m[j-1])
            {
                LCSMatrix[i][j] = LCSMatrix[i-1][j-1] + 1;
            }else{
                LCSMatrix[i][j] = max(LCSMatrix[i][j-1], LCSMatrix[i-1][j]);
            }
        }
    }   

    findLCM(LCSMatrix, l, m, p, q);

    return 0;
}