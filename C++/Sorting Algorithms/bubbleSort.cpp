
// Bubble sort algorithm..

#include <iostream>
using namespace std;

void bubble_sort(int arr[], int size)
{
    for ( int i=0; i<size-1; i++)
    {
        for (int j=0; j<size-1-i; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{

    int arr[4] = {16, 19, 11, 15};

    // sorting the above array using bubble sort..
    // call the function bubble_sort()
    bubble_sort(arr, 4);
    cout << "Sorted array is: " << endl;

    for (int i=0; i<4; i++)
    {
        cout << arr[i] << " ";
    }


    return 0;
}