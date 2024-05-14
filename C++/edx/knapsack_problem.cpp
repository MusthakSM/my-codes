

//DO NOT CHANGE THE GIVEN CODE TEMPLATE. WRITE YOUR CODE IN THE PROVIDED PLACES ALONE.
//If required, you can add additional functions or header files.

#include<bits/stdc++.h>
using namespace std;



int totalvalue(int arr[][2], int size, int capacity)
{
    int value_sum = 0;
    int weight_sum = 0;
    for (int i=0; i<size; i++)
    {
        if (weight_sum+arr[i][0]<=capacity)
        {
            weight_sum += arr[i][0];
            value_sum += arr[i][1];
        }
    }

    return value_sum;
}

void sort(int arr[][2], int size)
{
    for (int i=0; i<size-1; i++)
    {
        for (int j=0; j<size-1-i; j++)
        {
            if (arr[j][1]<arr[j+1][1])
            {
                int temp1=arr[j][1];
                int temp2=arr[j][0];

                arr[j][1] = arr[j+1][1];
                arr[j][0] = arr[j+1][0];

                arr[j+1][0] = temp2;
                arr[j+1][1] = temp1;
            }
        }
    }
}


int main(){
    
    //Write your code here
    int n, size;
    cout << "Enter the number of items: ";
    cin >> n;

    if (n>0)
    {
        int items[n][2];

        for (int i=0; i<n; i++)
        {
            for (int j=0; j<2; j++)
            {
                cin >> items[i][j];
            }
        }
        
        cout << "Enter the size of knapsack:";
        cin >> size;

        sort(items, n);

        cout << "The total value is:" << totalvalue(items, n, size) << endl;


    }
    else{
        cout << "Invalid input" << endl;
    }

    
    
    
    return 0;
}
