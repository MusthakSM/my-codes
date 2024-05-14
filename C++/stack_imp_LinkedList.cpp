
// stack implementation using linked list..

#include <iostream>
using namespace std;

class Node{

    public:
        int data;
        Node *next;

};

class stack{

    Node *top;
    public:
        stack()
        {
            top = NULL;
        }

        void push(int value);
        void pop();
        int peek();
        void display();
};

void stack:: push(int value)
{
    Node *New;
    New = new Node();

    New->data = value;
    New->next = NULL;

    if (top == NULL)
    {
        top = New;
    }
    else{
        New->next = top;
        top = New;
    }
}

void stack:: pop()
{
    Node *current;

    if (top == NULL)
    {
        cout << "stack underflow.." << endl;
        return;
    }
    
    current = top;
    top = current->next;
    current = NULL;

}

int stack:: peek()
{
    Node *current;

    if (top == NULL)
    {
        cout << "stack underflow.." << endl;
        return -1;
    }

    return top->data;
}

void stack:: display()
{
    Node *current;
    if (top == NULL)
    {
        cout << "stack underflow.." << endl;
        return;
    }

    current = top;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current ->next;
    }
    cout << endl;
}


int main()
{
    stack st;
    st.push(30);
    st.push(50);
    st.push(20);
    st.push(70);
    st.display();
    st.pop();
    int top_value = st.peek();
    if (top_value != -1)
    {
        cout << "The top value is " << top_value << endl;
    }

    cout << "Elements after the pop operation are: " << endl;
    st.display();

    return 0;
}