#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int rotate(int** matrix, int rowStart, int rowEnd, int colStart, int colEnd)
{
    if( rowStart >= rowEnd || colStart >= colEnd)
    {
        return 0;
    }else{

        int temp = matrix[rowStart][colStart];
        for (int i=rowStart; i<rowEnd; i++)
        {
            int toTemp = matrix[i+1][colStart];
            matrix[i+1][colStart] = temp;
            temp = toTemp;
        }

        for (int i=colStart; i<colEnd; i++)
        {
            int toTemp = matrix[rowEnd][i+1];
            matrix[rowEnd][i+1] = temp;
            temp = toTemp;
        }

        for (int i=rowEnd; i>rowStart; i--)
        {
            int toTemp = matrix[i-1][colEnd];
            matrix[i-1][colEnd] = temp;
            temp = toTemp;
        }

        for (int i=colEnd; i>colStart; i--)
        {
            int toTemp = matrix[rowStart][i-1];
            matrix[rowStart][i-1] = temp;
            temp = toTemp;
        }

        return rotate(matrix, rowStart+1, rowEnd-1, colStart+1, colEnd-1);

    }

}


int main(void){
    int x, y, z;
    cin >> x >> y >> z;

    int** matrix = new int*[x];
    for (int i=0; i<x; i++)
    {
        matrix[i] = new int[y];

        for (int j=0; j<y; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i=0; i<z; i++)
        rotate(matrix, 0, x-1, 0, y-1);

    for (int i=0; i<x; i++)
    {
        for (int j=0; j<y; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i=0; i<x; i++)
    {
        delete[] matrix[i];
        matrix[i] = NULL;
    }

    delete[] matrix;
    matrix = NULL;

    return 0;
}
