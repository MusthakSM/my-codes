
//DO NOT CHANGE THE GIVEN CODE TEMPLATE. WRITE YOUR CODE IN THE PROVIDED PLACES ALONE.

#include <iostream>
using namespace std;

class Node 
{
    public:
      int data;
      Node *left, *right;
};

class BST
{
	public :
	Node *root;
    BST() {
        root = NULL;
    }
    Node* insert(Node*, int);
    int search(int);
};

Node* BST :: insert(Node* root, int value){
    //Write your code here
    
    Node *New = new Node();
    New->data = value;
    New->left = NULL;
    New->right = NULL;

    if (root == NULL)
    {
        root = New;
    }
    else if (root->data <= value)
    {
        root->right = insert(root->right, value);
    }
    else{
        root->left = insert(root->left, value);
    }
    
    return root;
}

int BST :: search(int searchKey) {
    //Write your code here
    Node *current = root;

    int status = -1;
    while (current != NULL)
    {
        if (current->data == searchKey)
        {
            status = searchKey;
            break;
        }
        else if (current->data > searchKey)
        {
            current = current->left;
        }
        else 
        {
            current = current->right;
        }

    }
    return status; //Change the return value as per the problem statement
}

int main() 
{
	BST tree;
	string ch="yes";
	int num,searchKey;
	cout<<"Enter the key number:\n";
	cin>>num;
	
	tree.root=tree.insert(tree.root, num);
	do  {
	    cout<<"Do you want to create another junction (yes/no)?\n";
		cin>>ch;
		if (ch.compare("yes")==0){
		    cout<<"Enter the key number:\n";
		    cin>>num;
	    	tree.root=tree.insert(tree.root, num);
	    
	    }
		else{
		    break;
		}
	}while(true);
	
	
    //Write your code here for searching the key and displaying the search result.
    cout << "Enter the key to be searched" << endl;
    cin >> searchKey;

    int search_result = tree.search(searchKey);

    if ( search_result != -1)
    {
        cout << searchKey << " found" << endl;
    }
    else 
    {
        cout << searchKey << " not found" << endl;
    }
    
  
    return 0;
}
