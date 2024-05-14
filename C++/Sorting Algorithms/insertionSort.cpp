
// Insertion sort Algorithm...

#include <iostream>
using namespace std;


void insertion_sort(int arr[], int size)
{  
    for (int i=1; i<size; i++)
    {
        int min =arr[i];

        for (int j = i-1; j>=0; j--)
        {
            if (min<=arr[j])
            {
                arr[j+1] = arr[j];
                arr[j] = min;
            }
        }
    
    }   
}

int main()
{
    int size;
    cout << "Enter the size: ";
    cin >> size;

    int arr[size];

    cout << "Original array is: ";

    for (int i=0; i<size; i++)
    {
        cin >> arr[i];
    }
    

    cout << "\nSorted array is: ";
    // sorting the array using insertion sort...
    // calling the insertion_sort()
    insertion_sort(arr, size);


    for (int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }


    return 0;
}