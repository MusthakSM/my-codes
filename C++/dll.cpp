
#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Students
{

public:
    string name;
    int age;
    Students *next;
    Students *prev;
};

void add_student(Students **head);
void printAll(Students **head);
void print(Students **head, string name);
void Delete(Students **head, string name);

int main()
{
    Students *head;
    head = new Students();
    head = NULL;

    while (true)
    {
        cout << "***************** " << endl;
        cout << "Select an option: " << endl;
        cout << "1. Add a student." << endl;
        cout << "2. Print all students. " << endl;
        cout << "3. Print a student. " << endl;
        cout << "4. Delete a student. " << endl;
        cout << "5. Exit." << endl;

        int option;
        cout << "Option: ";
        cin >> option;

        if (option == 1)
        {
            add_student(&head);
        }
        else if (option == 2)
        {
            printAll(&head);
        }
        else if (option == 3)
        {
            string name;
            cout << "Enter student's name: ";
            cin >> name;

            print(&head, name);
        }
        else if (option == 4)
        {
            string name;
            cout << "name of the student: ";
            cin >> name;
            Delete(&head, name);
        }
        else if (option == 5)
        {
            cout << "Thank you.." << endl;
            break;
        }
        else
        {
            cout << "Invalid option. Try again.." << endl;
            continue;
        }
    }
}

void add_student(Students **head)
{
    static Students *tail;
    Students *New;
    New = new Students();
    cout << " Name: ";
    cin >> New->name;
    cout << " Age: ";
    cin >> New->age;


    if (*head == NULL)
    {
        *head = New;
        tail = New;
        tail->next = NULL;
        tail->prev = NULL;
    }
    else
    {
        tail->next = New;
        New = tail;
        tail = tail->next;
        tail->prev = New;
        tail->next = NULL;
    }
}

void printAll(Students **head)
{
    Students *current; // we don't allocate this pointer on heap or static memory,.. every time with function call this pointer will be created...
    current = *head;

    while (current != NULL)
    {
        printf("Student %s is %d years old.\n", (current->name).c_str(), current->age);
        current = current->next;
    }
}

void print(Students **head, string name)
{
    Students *current;
    current = new Students();

    current = *head;
    int status = 0;
    int is_list_empty = 1;
    while (current != NULL)
    {
        is_list_empty = 0;
        if (name == current->name)
        {
            printf("Student %s is %d years old.\n", (current->name).c_str(), current->age);
            status = 1;
            break;
        }

        current = current->next;
    }

    if (is_list_empty == 1)
    {
        cout << "List is empty..." <<endl;
    }

    if (is_list_empty != 1 && status == 0)
    {
        cout << "There are no students with this name..." << endl;
    }

    
}

void Delete(Students **head, string name)
{
    Students *current, *tracer;
    tracer = new Students();
    current = new Students();
    current = *head;
    tracer = *head;
    int is_it_head = 1;
    int is_deleted = 0;
    int is_list_empty = 1;
    while (current != NULL)
    {
        is_list_empty = 0;
        if (current->name == name && is_it_head == 1)
        {
            *head = (*head)->next;
            (*head)->prev = NULL;
            free(current);
            current = NULL;
            cout << "Deletion is successfull..." << endl;
            is_deleted = 1;
            break;   
        }
        else if (current->name == name && is_it_head != 1)
        {
            if (current->next == NULL)
            {
                tracer->next = NULL;
                free(current);
                current = NULL;
                cout << "Deletion is successfull..." << endl;
                is_deleted = 1;
                break;   
            }
            else{
                tracer->next = current->next;
                (current->next)->prev = tracer;
                tracer = current -> next;
                free(current);
                current = NULL;
                cout << "Deletion is successfull..." << endl;
                is_deleted = 1;
                break;   
            }
           

        }
        
        if (is_it_head != 1)
            tracer = tracer -> next;
        is_it_head = 0;
        current = current->next;
        
    }

    if (is_list_empty == 1)
    {
        cout << "List is empty..." <<endl;
    }

    if (is_list_empty != 1 && is_deleted == 0)
    {
        cout << "There are no students with this name..." << endl;
    }

}