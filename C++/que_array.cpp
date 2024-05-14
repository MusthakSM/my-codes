
// implementation of queue using array..

#include <iostream>
#define SIZE 5
using namespace std;

class queue{
    int front, rear;
    int arr[SIZE];

    public:
        queue()
        {
            front = rear = -1;
        }

        void enqueue(int value);
        void dequeue();
        void display();

};

void queue::enqueue(int value)
{
    if (rear == SIZE-1)
    {
        cout << "Queue overflow.." << endl;
        return;
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        arr[rear] = value;
        cout << "Inserted item: " << value << endl;
    }
    else{
        arr[++rear] = value;
        cout << "Inserted item: " << value << endl;
    }

}

void queue:: dequeue()
{
    if (front == -1)
    {
        cout << "Queue underflow.." << endl;
        return;
    }
    else
    {
        int item = arr[front];
        if (front == rear)
            front = rear = -1;
        
        else 
            front++;
        cout << "Deleted item: " << item << endl;
    }
}

void queue:: display()
{
    if (rear == -1 && front == -1)
    {
        cout << "queue is empty. Nothing to show.." << endl;
    }
    else
    {
        int iter = front;
        while (iter<=rear)
        {
            cout << arr[iter] << " ";
            iter++;
        }

        cout << endl;
    }
}

int main()
{
    queue qu;

    qu.enqueue(1);
    qu.enqueue(2);
    qu.enqueue(3);
    qu.enqueue(4);
    qu.display();
    qu.dequeue();
    qu.dequeue();
    qu.dequeue();
    qu.dequeue();
    qu.dequeue();

    return 0;

}