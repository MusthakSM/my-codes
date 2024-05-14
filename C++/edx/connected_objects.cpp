// Finding the biggest island question.....

//DO NOT CHANGE THE GIVEN CODE TEMPLATE. WRITE YOUR CODE IN THE PROVIDED PLACES ALONE.
//If required, you can add additional functions or header files.

#include<iostream>
using namespace std;


int BiggestIsland(int **arr, int row_pos, int col_pos, int rows, int columns)
{
    int connection_size = 0;

    if (row_pos < 0 || row_pos >= rows || col_pos < 0 || col_pos >= columns)
    {
        return 0;
    }
    

    if (arr[row_pos][col_pos] == 1)
    {
        arr[row_pos][col_pos] = 0;
        connection_size = 1;

        return connection_size + BiggestIsland(arr, row_pos, col_pos+1, rows, columns) + BiggestIsland(arr, row_pos, col_pos-1, rows, columns) + BiggestIsland(arr, row_pos-1, col_pos, rows, columns) + BiggestIsland(arr, row_pos+1, col_pos, rows, columns) + BiggestIsland(arr, row_pos+1, col_pos-1, rows, columns) + BiggestIsland(arr, row_pos+1, col_pos+1, rows, columns)+ BiggestIsland(arr, row_pos-1, col_pos+1, rows, columns);
    }
    else
    {
        return 0;
    }

}


int main(){
    int rows, columns;
    cin >> rows;
    cin >> columns;

    if (rows < 1 || columns < 1)
    {
        cout << "Invalid input";
        return 0;
    }

    int **matrix;
    matrix = new int*[rows];

    for (int row=0; row<rows; row++)
    {
        matrix[row] = new int[columns];
        for (int col=0; col<columns; col++)
        {
            cin >> matrix[row][col];
        }
    }

    int max_size = 0;
    for (int row=0; row<rows; row++)
    {
        for (int col=0; col<columns; col++)
        {
            if (matrix[row][col] == 1){
                int size = BiggestIsland(matrix, row, col, rows, columns);
                if (size>max_size)
                    max_size = size;
            
            }
        }
    }
    
    cout << max_size << endl; 
    

    return 0;
}
   

