//DO NOT CHANGE THE GIVEN CODE TEMPLATE. WRITE YOUR CODE IN THE PROVIDED PLACES ALONE.
//If required, you can add additional functions or header files.

#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

int partition(char str[], int start, int end)
{
    char pivot = str[start];
    int pIndex = end;

    for (int i=end; i>start; i--)
    {
        if (str[i]>pivot)
        {
            char temp = str[i];
            str[i] = str[pIndex];
            str[pIndex] = temp ;
            pIndex--;
        }
    }

    str[start] = str[pIndex];
    str[pIndex] = pivot;

    return pIndex;
}

void quick(char str[], int start, int end)
{
    if (start<end)
    {
        int pivotindex = partition(str, start, end);
        quick(str, start, pivotindex-1);
        quick(str, pivotindex+1, end);
    }
}

void bubble(char str[], int size)
{
    for (int i=0; i<size-1; i++)
    {
        for (int j=0; j<size-1-i; j++)
        {
            if (str[j]<str[j+1])
            {
                char temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
}

int main() { 
    char st[50];
    cout<<"Enter the String: ";
    cin>>st;
     
    //Write your code here
    int size = strlen(st);

    quick(st, 0, size-1);

    int capUpperBound = 0;
    for (int i = 0; i<size; i++)
    {
        if (st[i]<'Z')
            capUpperBound++;
    }
    
    bubble(st, capUpperBound);


    cout << "The sorted string is: " << st << endl;
 
    return 0;
} 