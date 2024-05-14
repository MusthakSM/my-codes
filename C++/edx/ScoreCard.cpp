//DO NOT CHANGE THE GIVEN CODE TEMPLATE. WRITE YOUR CODE IN THE PROVIDED PLACES ALONE.
//If required, you can add additional functions or header files.


#include <iostream>
#include <cstdio>
#define SIZE 100
using namespace std;

class queue{
    int front, rear;
    public: 
        int arr[SIZE];
        queue()
        {
            front = rear = -1;
        }

        void enqueue(int value);
        void display();


};

void queue::enqueue(int value)
{
    if (rear == SIZE-1)
    {
        cout << "Queue overflow.." << endl;
        return;
    }
    else if (front == - 1 &&  rear == -1)
    {
        front = rear = 0;
        arr[rear] = value;
    }
    else
    {
        arr[++rear] = value;
    }
}

void queue::display()
{

    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty.." << endl;
    }
    else{

        front = rear-4;
        cout << "Latest hurdle race scores are: ";
        while (front<=rear)
        {
            cout << arr[front] << " ";
            front++;
        }

    }

    cout << endl;
}


int main(){
    //Write your code here
    queue qu;

    int hurdles;
    cout << "Enter the no. of hurdles:";
    cin >> hurdles;

    if (hurdles<=0 || hurdles > 100)
    {
        cout << "Invalid no. of hurdles" << endl;
        return 0;
    }

    cout << endl;

    for (int i=1; i<=hurdles; i++)
    {
        int height;
        printf("Enter the hurdle height %d:", i);
        cin >> height;

        qu.enqueue(height);
    }

    cout << endl;

    qu.display();

    return 0;
}