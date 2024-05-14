// Implementation of stack using array...

#include <iostream>
#define SIZE 10     // Define the size of the stack(an array..)
using namespace std;

class stack{
private:
    int top;
public:
    int arr[SIZE];
    stack()
    {
        top = -1;
    }

    void push(int value);
    int pop();
    int peek();

};

void stack:: push(int value)
{
    if( top >= SIZE-1)
    {
        cout << "stack overflow." << endl;
        return;
    }
    else{
        arr[++top] = value;
        cout << "Element added: " << value << endl;
    }
}

int stack:: pop()
{
    if (top < 0)
    {
        cout << "stack underflow." << endl;
        return -1;
    }
    else
    {
        int deleted = arr[top--];
        return deleted;
    }
}

int stack:: peek()
{
    if (top < 0)
    {
        cout << "stack underflow." << endl;
        return -1;
    }
    else{
        return arr[top];
    }
}

int main()
{
    // creating a stack..
    stack st;

    for (int i=10; i>0; i--)
    {
        st.push(i);
    }

    cout << "Top element is: " << st.peek() << endl;
    
    for (int i=0; i<=10; i++)
    {
        int top = st.pop();
        if (top != -1)
            cout << "The Deleted element from the stack is: " << top << endl;
    }

    st.push(5);
    

}