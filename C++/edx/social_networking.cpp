//DO NOT CHANGE THE GIVEN CODE TEMPLATE. WRITE YOUR CODE IN THE PROVIDED PLACES ALONE.
//If required, you can add additional functions or header files.


#include <iostream>
#include <cstdio>
using namespace std;

void graph_construction(int **arr, int size, int start, int end)
{
    for (int row=0; row<size; row++)
    {
        for (int col=0; col<size; col++)
        {
            if (row+1 == start && col+1 == end)
            {
                arr[row][col] = end;
            }
            if (row+1 == end && col+1 == start)
            {
                arr[row][col] = start;
            }
        }
    }
}

void graph_representation(int **arr, int size)
{
    for (int row = 0; row<size; row++)
    {
        for (int col=0; col<size; col++)
        {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
}

void friends_list(int **arr, int size)
{
    for (int row = 0; row<size; row++)
    {
        cout << row+1 << "->";
        int no_friends = 1;
        for (int col=0; col<size; col++)
        {
            if (arr[row][col] != 0)
            {
                no_friends = 0;
                cout << arr[row][col] << " ";
            }
        }

        if (no_friends == 1)
            cout << "0";
        cout << endl;
    }

}


int main(){
        
    //Write your code here
    int users, connections;
    cout << "Enter the no. of users: ";
    cin >> users;

    cout << "Enter the no. of connections: ";
    cin >> connections;

    int **graph;
    graph = new int *[users];
    
    for (int row = 0; row<users; row++)
    {
        graph[row] = new int [users];
        for (int col=0; col<users; col++)
        {
            graph[row][col] = 0;
        }
    }

    for (int i=1; i<=connections; i++)
    {
        int start, end;
        printf("Enter the start node and end node in connection %d:\n", i);
        cin >> start >> end;

        graph_construction(graph, users, start, end);
    }
    
    cout << "The representation of SocialNet users:" << endl;

    graph_representation(graph, users);

    cout << "The friends' list of all users:" << endl;

    friends_list(graph, users);
    
    delete[] graph;
    graph = NULL;
    return 0; 
}

