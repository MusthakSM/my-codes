
// Quick sort Algorithm..(recursive Algorithms...)

#include <iostream>
using namespace std;


int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int pivot_index = high;

    for ( int i=high; i>low; i--)
    {
        if (arr[i] >= pivot)
        {
            int temp = arr[i];
            arr[i] = arr[pivot_index];
            arr[pivot_index] = temp;
            pivot_index--;
        }
    }
    int temp = arr[low];
    arr[low] = arr[pivot_index];
    arr[pivot_index] = temp;
    return pivot_index;
}

void quickSort(int arr[], int low, int high)
{
    if (low<high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }

}



int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];

    cout << "Original array is: ";

    for (int i=0; i<size; i++)
    {
        // give inputs as space seperated...
        cin >> arr[i];
    }

    cout << "Sorted array is: ";
    // sorted array is.... (using quick sort..)
    // calling the function quickSort().

    quickSort(arr, 0, size-1);

    for (int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}