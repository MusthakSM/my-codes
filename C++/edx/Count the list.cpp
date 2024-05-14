//PLEASE DO NOT CHANGE THE GIVEN CODE TEMPLATE. WRITE YOUR CODE IN THE PROVIDED PLACES ALONE.

#include <iostream>
using namespace std;

class Node {  
    public:            
        int data; 
        Node* next;
};    

class LinkedList {  
  public:
        Node *head;         
        LinkedList()  {
            head = NULL; 
        }
        void append(int);
        void display();
        int countTheKey(int);
};

void LinkedList :: append(int value)  {
    //Write your code here
    Node *New;
    static Node *tail;
    New = new Node();
    New->data = value;
    New->next = NULL;
    
    if (head == NULL)
    {
        head = New;
        tail = New;
        tail->next = NULL;
    }
    else{
        tail->next = New;
        tail = New;
        tail->next = NULL;
    }
    
}

void LinkedList :: display() {
    //Write your code here
    Node *current;
    current = head;
    cout << "The list is: ";
    while(current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    
}
        
int LinkedList :: countTheKey(int key){
    //Write your code here
    Node *current;
    current = head;
    int count = 0;
    while(current != NULL)
    {
        if (current->data == key)
            count++;
        
        current = current->next;
    }
    
    return count;
}    
    
int main(){
    cout<<"\nEnter the size of the list: ";
    int N,value,key;
    LinkedList lst;
    cin>>N;
    if(N>0){
        for(int i=0;i<N;i++){
            cin>>value;
            lst.append(value);
        }
        cout<<"\n";
        lst.display();
        cout<<"\nEnter the number: ";
        cin>>key;
        
        //Write your code here
        cout << key << " occurs " << lst.countTheKey(key) << " times."<< endl;
        
    }
    else
    cout<<"\nInvalid Input";
    
    return 0;
}
