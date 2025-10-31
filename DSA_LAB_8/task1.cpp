#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d=0){
        data = d;
        left = right = NULL;
    }
};


class BinarySearchTree{
    Node* root;
    public:
    BinarySearchTree(){
        root = nullptr;
    }
    void insert(int data){
        root = insertRecursive(root,data);
    }

    Node* insertRecursive(Node *root,int data){
        if (root==NULL)
        {
            return new Node(data);
        }

        if (data<root->data)
        {
            root->left = insertRecursive(root->left,data);
        }

        else if(data>root->data)
        {
            root->right = insertRecursive(root->right,data);
        }
        return root;
    }

    void traversal(Node *root){
        if (root==NULL)
        {
            return;
        }

        traversal(root->left);
        cout<<root->data<<" ";
        traversal(root->right);

        
    }
    Node* deleteNode(Node* root,int d){
        if (root==NULL)
        {
            return root;
        }

        if (root->data>d)
        {
            root->left = deleteNode(root->left,d);
        }
        else if (root->data<d)
        {
            root->right = deleteNode(root->right,d);
        }

        else if(root->data==d){
            if (root->left==NULL && root->right==NULL)
            {
                delete root;
                return NULL;
            }

            else if(root->left==NULL){
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL){
                Node *temp = root->left;
                delete root;
                return temp;
            }
            else{
                Node *temp = findSuccessor(root);
                root->data =temp->data;
                root->right = deleteNode(root->right,temp->data);
            }
        }
            return root;
    }

        Node* findSuccessor(Node *root)
        {
            root = root->right;
            while (root!=NULL && root->left!=NULL)
            {
                root = root->left;
            }

            return root;
            
        }
        
        
    

    Node* getRoot(){
        return root;
    }
};

int main(){
    BinarySearchTree b;
    b.insert(10);
    b.insert(5);
    b.insert(12);
    b.insert(11);
    b.traversal(b.getRoot());
    cout<<endl;
    Node *r = b.findSuccessor(b.getRoot());
    b.deleteNode(b.getRoot(),10);
    b.traversal(b.getRoot());


}