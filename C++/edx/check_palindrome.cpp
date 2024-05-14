//DO NOT CHANGE THE GIVEN CODE TEMPLATE. WRITE YOUR CODE IN THE PROVIDED PLACES ALONE.

#include<iostream>
using namespace std;

class Node {     
      public:
          int data;
         Node *next;
};
class Stack{ 
   public:
       Node *top;
       Stack(){ 
           top=NULL;
        }
        void push(int data);
        int pop();
};

void Stack :: push(int data){
    //Write your code here
    Node *New = new Node();
    New->data = data;
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


int Stack ::pop(){
    //Write your code here 
    Node *temp;
    if (top == NULL)
    {
        cout << "Stack underflow"<< endl;
        return 0;
    }
    else
    {
        cout << "Popped element:";
        temp = top;
        top = top->next;
        cout << temp->data << endl;
        return temp->data;
        delete temp;
        temp = NULL;
    }
    
    //return -1;  //Change this return value according to the problem description
}

int checkPalindrome(Stack stk, int arr[],int size) {
    //Write your code here
    
    int status = 1;
    for (int i=0; i<size; i++)
    {
        if (stk.pop() != arr[i]){
            status = 0;
            break;
        }
    }
    
    if (status == 1)
        return 1;
    else 
        return 0;
    //return -1;   Change this return value according to the problem description
}

      
int main(){
    Stack stk;
    int size,i,data;
        
    cin>>size;
    if(size<2){
        cout<<"Invalid input";
        return 0;
    }
    
    int arr[size];
    for(i=0; i<size; i++){
       cin>>data;
        arr[i]=data;
        stk.push(data);
    }
    
    //Write your code here for calling the 'checkPalindrome()' method
    
    int is_palindrome = checkPalindrome(stk, arr, size);

    cout << is_palindrome << endl;
    
    return 0;
 }