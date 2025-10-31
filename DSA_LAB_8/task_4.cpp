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
};
int main(){
    BST b;
    b.insert(4);
    b.insert(1);
    b.insert(2);
    b.insert(0);
    b.insert(5);
    b.inorder(b.root);
    cout<<endl;
    b.insert(5);
    b.inorder(b.root);
}   