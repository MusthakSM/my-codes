//DO NOT CHANGE THE GIVEN CODE TEMPLATE. WRITE YOUR CODE IN THE PROVIDED PLACES ALONE.

#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node *left, *right;
};

class BST {
	public :
	Node *root;
    BST() {
        root = NULL;
    }
    Node* insert(Node*, int);
    void preOrder(Node*);
    void inOrder(Node*);
    void postOrder(Node*);
};

Node* BST :: insert(Node* root, int value) { 
    //Write your code here
    
    Node *New = new Node();
    New->data = value;
    New->right = NULL;
    New->left = NULL;

    if (root == NULL)
    {
        root = New;
    }
    else if (root->data<=value)
    {
        root->right = insert(root->right, value);
    }
    else 
    {
        root->left = insert(root->left, value);
    }
    
    return root;
}

void BST :: preOrder(Node* root){
    //Write your code here
    Node *temp = root;
    Node *sudo_root;

    while (temp!=NULL)
    {
        cout << temp->data << " ";

        if (temp->left != NULL)
        {
            sudo_root = temp;
            temp = temp->left;
        }
        else{
            if (sudo_root->right != NULL)
            {
                temp = sudo_root->right;
                sudo_root = sudo_root->right;
            }
            else 
                temp = NULL;
        }
    }
  
}
  
void BST :: inOrder(Node* root) {
    //Write your code here
    Node *temp;
    temp = root;

    
    if (temp == NULL)
        return;
    inOrder(temp->left);
    cout << temp->data << " ";
    inOrder(temp->right);
    

}


void BST :: postOrder(Node* root) {
    //Write your code here
    Node *temp = root;
    if (temp == NULL)
            return;
    
    postOrder(temp->left);
 
    postOrder(temp->right);
 
    cout << temp->data << " ";
}

int main() {
	BST tree;
	string ch="yes";
	int num;
	do  {
		cout<<"Enter the element to be inserted in the tree\n";
		cin>>num;
		tree.root=tree.insert(tree.root, num);
		cout<<"Do you want to insert another element(yes/no)?\n";
		cin>>ch;
	}while(ch.compare("yes")==0);
	
	cout<<"Preorder Traversal : The elements in the tree are:\n";
	tree.preOrder(tree.root);
	cout<<"\n";
	cout<<"Inorder Traversal : The elements in the tree are:\n";
	tree.inOrder(tree.root);
	cout<<"\n";
    cout<<"Postorder Traversal : The elements in the tree are:\n";
	tree.postOrder(tree.root);
	cout<<"\n";
	return 0;
}



