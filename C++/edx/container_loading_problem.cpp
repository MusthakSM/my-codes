

//DO NOT CHANGE THE GIVEN CODE TEMPLATE. WRITE YOUR CODE IN THE PROVIDED PLACES ALONE.
//If required, you can add additional functions or header files.

#include <iostream>
using namespace std;


void selectionSort(int arr[], int size)
{ 
    for (int i=0; i<size-1; i++)
    {
        int min = i;
        for (int j = i+1; j<size; j++)
        {
            if (arr[j]<arr[min])
            {
                min = j;
            }
        }

        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;  

    }
    
}

int maxContainer(int arr[], int size, int weight)
{
    int max_containers=0;
    int sum = 0;
    for (int i=0; i<size; i++)
    {
        if (sum+arr[i]<weight)
        {
            sum += arr[i];
            max_containers++;
        }
        else{
            arr[i] = 0;
        }
    }
    return max_containers;
}

void array_manipulation(int arr1[], int arr2[], int size)
{
    for (int i=0; i<size; i++)
    {
        int found = 0;
        for (int j=0; j<size; j++)
        {
            if (arr2[i] == arr1[j])
            {
                arr2[i] = 1;
                found =1;
                break;
            }
        }

        if (found == 0)
            arr2[i] = 0;
    }
}


int main() {
    
    //Write your code here
    int size, container_capacity;
    cin >> size;
    int containers[size];
    int pesudo_container[size];

    for (int i=0; i<size; i++)
    {
        cin >> containers[i];
        pesudo_container[i] = containers[i];
    }
    
    cin >> container_capacity;
    
    selectionSort(containers, size);
    int maximum_containers = maxContainer(containers, size, container_capacity);
    array_manipulation(containers, pesudo_container, size);

    cout << maximum_containers << endl;

    cout << "[";
    for (int i=0; i<size; i++)
    {
        if (i!=0)
            cout << "," << pesudo_container[i];
        else
            cout << pesudo_container[i];
    }
    cout << "]" << endl;

    return 0;
}