// implementation of queue using linked list....

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;

};

class queue{
Node *front , *rear;

public:
    queue(){
        front = rear = NULL;
    }
    void enQueue(int value);
    void deQueue();
    void display();
};

void queue::enQueue(int value)
{
    Node *New = new Node();
    New->data = value;
    New->next = NULL;

    if (front == NULL)
    {
        front = rear = New;
    }
    else{
        rear->next = New;
        rear = New;
    }

    cout << "Inserted element is " << value << endl;
}

void queue::deQueue()
{
    Node *temp;
    temp = front;
    if (front == NULL)
    {
        cout << "Queue underflow.." << endl;
        return ;
    }
    else if (front == rear)
    {
        front = rear = NULL;
    }
    else{
        front = front->next;
    }
    cout << "Deleted element is " << temp->data << endl;
    delete temp;
}

void queue::display()
{
    if (front == NULL)
    {
        cout << "Queue underflow.." << endl;
    }
    else{
        Node *temp = front;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    cout << endl;
}

int main()
{

    queue q;
    for (int i=1; i<=5; i++)
    {
        q.enQueue(i*10);
    }

    q.display();

    for (int i=1; i<=5; i++)
    {
        q.deQueue();
    }

    q.deQueue();


    return 0;
}