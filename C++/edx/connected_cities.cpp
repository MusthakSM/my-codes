//DO NOT CHANGE THE GIVEN CODE TEMPLATE. WRITE YOUR CODE IN THE PROVIDED PLACES ALONE.
//If required, you can add additional functions or header files.

#include <iostream>
#include <cstdio>
using namespace std;

void graph_construction(int **arr, int size, int start, int end, int weight)
{
    for (int row=0; row<size; row++)
    {
        for (int col=0; col<size; col++)
        {
            if (row == start && col == end)
            {
                arr[row][col] = weight;
            }
        }
    }
}

void path_distance(int **arr, int size)
{
    cout << "The distance between the connecting cities are:" << endl;
    
    for (int row=0; row<size; row++)
    {
        int no_connection = 1;
        for (int col=0; col<size; col++)
        {
            if (arr[row][col]!=0)
            {
                no_connection = 0;
                printf("%d -> %d Distance: %d\n", row, col, arr[row][col]);
            }
        }

        if (no_connection == 1)
            printf("%d - No connecting roads found\n", row);
        
    }
}

void highest_connection(int **arr, int size)
{
    int city = 0;
    int connections = 0;
    for (int row=0; row<size; row++)
    {
        int temp = 0;
        for (int col=0; col<size; col++)
        {
            if (arr[row][col] != 0)
            {
                temp++;
            }
        }

        for (int newRow=0; newRow<size; newRow++)
        {
            if (arr[newRow][row] != 0)
                temp++;
        }

        if (temp>connections)
        {
            connections = temp;
            city = row;
        }

    }

    if (connections>0)
        cout << city << " is the city with the highest connecting roads." << endl;
    else    
        cout << "No city has any connecting road." << endl;

}


int main(){
    //Write your code here
    int cities, connecting_roads;
    cout << "Enter the no. of cities:";
    cin >> cities;

    cout << "Enter the no. of connecting (one-way) roads:";
    cin >> connecting_roads;

    int **adjacency_matrix;
    adjacency_matrix = new int*[cities];

    for (int row=0; row<cities; row++)
    {
        adjacency_matrix[row] = new int[cities];
        for (int col=0; col<cities; col++)
        {
            adjacency_matrix[row][col] = 0;
        }
    }

    for (int roads = 1; roads<=connecting_roads; roads++)
    {
        int start, end, distance;
        printf("Enter the start node (city) and end node (city) in the connection %d:", roads);
        cin >> start >> end;
        cout << "Enter the distance (weight):";
        cin >> distance;

        graph_construction(adjacency_matrix, cities, start, end, distance);
    }
    
    
    path_distance(adjacency_matrix, cities);


    highest_connection(adjacency_matrix, cities);

    return 0;
}

