#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int biggestIsland(int** matrix, int rowPos, int colPos, int row, int col)
{
    if(rowPos < 0 || rowPos >= row || colPos < 0 || colPos >= col)
    {
        return 0;
    }

    if (matrix[rowPos][colPos] == 0)
    {
        return 0;
    }else{
        matrix[rowPos][colPos] = 0;
        return 1+ biggestIsland(matrix, rowPos, colPos+1, row, col) 
                + biggestIsland(matrix, rowPos, colPos-1, row, col) 
                + biggestIsland(matrix, rowPos+1, colPos, row, col) 
                + biggestIsland(matrix, rowPos-1, colPos, row, col)
                + biggestIsland(matrix, rowPos-1, colPos+1, row, col)
                + biggestIsland(matrix, rowPos-1, colPos-1, row, col)
                + biggestIsland(matrix, rowPos+1, colPos+1, row, col)
                + biggestIsland(matrix, rowPos+1, colPos-1, row, col);
    }
}

int main(void){

    int row, col;
    cin >> row >> col;

    int** matrix = new int*[row];
    //taking the input matrix.
    for (int i=0; i<row; i++)
    {
        matrix[i] = new int[col];

        for (int j=0; j<col; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // check for the biggest island..
    int biggest = 0;
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            if(matrix[i][j] == 1)
            {
                int IslandSize = biggestIsland(matrix, i, j, row, col); 
                if(biggest < IslandSize)
                {
                    biggest = IslandSize;
                }
            }
        }
    }

    cout << biggest;

    for (int i=0; i<row; i++)
    {
        delete[] matrix[i];
        matrix[i] = NULL;
    }

    delete[] matrix;
    matrix = NULL;

    return 0;
}
