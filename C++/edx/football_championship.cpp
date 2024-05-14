

//DO NOT CHANGE THE GIVEN CODE TEMPLATE. WRITE YOUR CODE IN THE PROVIDED PLACES ALONE.

#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    
    //Fill Your code here
    
    int low = 0;
    int high = size-1;

    int middle = (low+high)/2;

    while (low<=high)
    {
        cout << arr[middle] << " ";
        if (arr[middle] == key)
        {
            return middle+1;
        }
        else if(arr[middle]<key)
        {
            low = middle+1;
        }
        else{
            high = middle-1;
        }

        middle = (low+high)/2;
    }
    
    return -1;  //Change the return value as per the problem statement
}


int main() {
    cout<<"Enter the number of teams:";
    int no,score,result;
    cin>>no;
    int teams[no];
    cout<<"Enter the score:\n";
    for(int idx = 0; idx < no; idx++) {
        cin>>teams[idx];
    }
    cout<<"Enter the score to be searched:";
    cin>>score;
        
    //Fill your code here
    
    cout << "Mid scores: "; 
    int keypos = binarySearch(teams, no, score);
    
    if (keypos != -1)
    {
        cout << "\nScore found for team " << keypos << endl;
    }
    else{
        cout << "\nScore not found" << endl;
    }
        
    return 0;
}
   
