//DO NOT CHANGE THE GIVEN CODE TEMPLATE. WRITE YOUR CODE IN THE PROVIDED PLACES ALONE.

#include<iostream>
#include<cstdio>
using namespace std;
#define MAX 50

class Stack {          
    int top;  
    public: 
        int stk[MAX]; 
        Stack() { 
            top = -1; 
        } 
        void push(int data);
        int findMiddle();
        int pop();
};

void Stack::push(int data) { 
    stk[++top]=data; 
}

int Stack::pop(){ 
    //Write your code here  
    if (top < 0)
    {
        cout << "stack underflow" << endl;
        return -1;
    }
    else 
    {
        int popped = stk[top--];
        return popped;
    }
} 

int Stack::findMiddle() { 
    //Write your code here
    int iter = top;
    int middle = 0;
    while (iter>-1)
    {
        middle++;
        iter--;
    }
    
    middle = (middle-1)/2;

    return stk[middle];
} 



int  main() {
    int no;
    Stack st;
    cout<<"\nEnter the number of elements to be pushed into the stack:";
    cin>>no;
    
    //Write your code here
    if (no<=0){
        cout << "Invalid input";
        return 0;
    }

    for (int i=1; i<=no; i++)
    {
        int element;
        printf("Enter element %d:\n", i);
        cin >> element;
        st.push(element);
    }
    
    int popped;
    int middle;

    if (no%2 == 0)
    {
        popped = st.pop();
        middle = st.findMiddle();

        cout << "The middle element is: " << middle << endl;
        cout << "The popped element is: " << popped << endl;
    }
    else{

        middle = st.findMiddle();
        popped= st.pop();
        cout << "The middle element is: " << middle << endl;
        cout << "The popped element is: " << popped << endl;
    }

    return 0;    
}
