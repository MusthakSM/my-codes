//DO NOT CHANGE THE GIVEN CODE TEMPLATE. WRITE YOUR CODE IN THE PROVIDED PLACES ALONE.

#include <iostream>
using namespace std;
 
void merge(int *arr, int low, int high, int mid){
	//Write your code here
    int i = low, j = mid+1, k = 0;
    int temp[high+1];

    while (i<=mid && j<= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            k++, i++;
        }
        else
        {
            temp[k] = arr[j];
            k++, j++;
        }
    }

    while (i<=mid)
    {
        temp[k] = arr[i];
        k++, i++;
    }

    while (j<=high)
    {
        temp[k] = arr[j];
        k++, j++;
    }

    for (int i=low; i<=high; i++)
    {
        arr[i] = temp[i-low];
    }
	
}
 

void mergeSort(int *arr, int low, int high){
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		//Split the data into two half.
		mergeSort(arr, low, mid);
		mergeSort(arr, mid+1, high);
 
		// Merge them to get sorted output.
		merge(arr, low, high, mid);
	}
}
 
int main()
{
	int n;
	cout<<"Enter the size of an array:";
	cin>>n;
    if(n>0){
	    int arr[n];
	    cout<<"Enter the elements:";
	    for(int i = 0; i < n; i++){
		    cin>>arr[i];
	    }
	    
    	mergeSort(arr, 0, n-1);
    	
    	//Write your code here for print the sorted array.
        cout << "The sorted array is" << endl;
    	for(int i = 0; i < n; i++){
		    cout << arr[i] << " ";
	    }
	   
    }
    else {
         //Write your code here for invalid array size.
         
         cout << "Invalid array size" << endl;
         
    }
 
	return 0;
}