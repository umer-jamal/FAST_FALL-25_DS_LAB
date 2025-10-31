#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d=0){
        left = right = NULL;
        data = d;
    }
};

class BST{
    public:
    Node* root;
    BST(){
        root = NULL;
    }

    Node* insertNode(Node* root,int d){
        if (root==NULL)
        {
            return new Node(d);
        }
        if (root->data==d)
        {
            cout<<"Value already exist\n";
            return root;
        }
        

        if (d>root->data)
        {
            root->right = insertNode(root->right,d);
        }
        if (d<root->data)
        {
            root->left = insertNode(root->left,d);
        }
        
        return root;
    }
    void insert(int d){
        root  = insertNode(root,d);
    }

    void inorder(Node* root){
        if (root==NULL)
        {
            return;
        }

        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);

        
    }

    void isBst(Node* root){
        if (root==NULL)
        {
            return;
        }
        if (root->left)
        {
            if (root->left->data > root->data)
            {
                cout<<"\nIts not a bst\n";
                return;
            }
        }
        
        if (root->right)
        {
            if (root->right->data < root->data)
            {
                cout<<"\nIts not a bst\n";
                return;
            }
        }
        
        
      

        isBst(root->left);
        isBst(root->right);
        
        
        
    }
};
int main(){
    BST b;
    b.root = new Node(10);
    b.root->left = new Node(5);
    b.root->right = new Node(20);
    b.root->right->left = new Node(25);
    b.root->right->right = new Node(30);
    // b.insert(4);
    // b.insert(1);
    // b.insert(2);
    // b.insert(0);
    // b.insert(5);
    b.inorder(b.root);
    b.isBst(b.root);
}   