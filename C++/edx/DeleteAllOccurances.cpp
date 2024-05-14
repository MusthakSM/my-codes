// PLEASE DO NOT CHANGE THE GIVEN CODE TEMPLATE. WRITE YOUR CODE IN THE PROVIDED PLACES ALONE.

#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
public:
    // Fill your code here
    int data;
    Node *next;
};

class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }
    void append(int value);
    void deleteAllOccurrences(int key);
    void display();
};

void LinkedList ::append(int value)
{
    // Write your code here
    Node *New;
    static Node *tail;
    New = new Node();

    New->data = value;
    New->next = NULL;

    if (head == NULL)
    {
        head = New;
        tail = New;
    }
    else
    {
        tail->next = New;
        tail = New;
    }
}

void LinkedList ::deleteAllOccurrences(int key)
{
    // Write your code here
    Node *current, *tracer;
    current = head;

    int is_head = 1;
    while(current != NULL)
    {
        if (current->data == key && is_head == 1)
        {
            head = current->next;
            free(current);
            current = NULL;
            current = head;
            continue;
        }
        else if (current->data == key && is_head == 0)
        {
            if (current->next == NULL)
            {
                tracer->next = NULL;
                free(current);
                current =  NULL;
                break;
            }
            else
            {
                tracer->next = current->next;
                free(current);
                current = NULL;
                current = tracer->next;
                continue;
            }
        }

        if (is_head == 1)
            tracer = head;
        else
            tracer = tracer->next;
        
        current = current->next;
        is_head = 0;
    }
    
}

void LinkedList ::display()
{
    Node *temp = head;
    cout << "\nThe list after deletion: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    cout << "\nEnter the size of the list: ";
    int N, value;
    LinkedList lst;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> value;
        lst.append(value);
    }
    cout << "\nEnter the element to be deleted: ";
    int delValue;
    cin >> delValue;

    // Write your here here for deleting and displaying the elements in the list

    lst.deleteAllOccurrences(delValue);
   
    lst.display();

    return 0;
}
