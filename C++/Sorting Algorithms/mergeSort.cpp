
// Merge Sort Algorithm...

#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    int temp[end+1];
    int i, k, j;
    i = start; k = 0; j = mid+1;

    while (i<=mid && j<= end)
    {
        if (arr[i]<arr[j])
        {
            temp[k] = arr[i];
            k++; i++;
        }
        else{
            temp[k] = arr[j];
            k++; j++;
        }
    }

    while (i<=mid)
    {
        temp[k] = arr[i];
        k++; i++;
    }

    while (j<=end)
    {
        temp[k] = arr[j];
        k++; j++;
    }

    for (int index=start; index<=end; index++)
    {
        arr[index] = temp[index-start];
    }
    

}

void mergeSort(int arr[], int start, int end)
{
    if (start<end)
    {
        int mid = (start+end)/2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}


int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Original array is: ";
    int array[size];

    for (int i=0; i<size; i++)
    {
        cin >> array[i];
    }

    cout << "Sorted array is: ";
    // using merge sort algorithm..
    // calling mergeSort() function...

    mergeSort(array, 0, size-1);

    for (int i=0; i<size; i++)
    {
        cout << array[i] << " ";
    }
    
    return 0;
}