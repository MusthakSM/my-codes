
// SELECTION SORT ALGORITHM...

#include <iostream>
using namespace std;

void selection_sort(int arr[], int size)
{
    for (int i=0; i<size; i++)
    {
        int min = i;
        for (int j=i+1; j<size; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }

        if (min != i)
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }

}


int main()
{
    int size;
    cout << "Enter the array size: ";
    cin >> size;

    int arr[size];

    for (int i=0; i<size; i++)
    {
        cin >> arr[i];
    }

    cout << "Sorted array is: " << endl;
    // sorting array using selection sort..
    // calling selection_sort(),
    selection_sort(arr, size);

    for (int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}