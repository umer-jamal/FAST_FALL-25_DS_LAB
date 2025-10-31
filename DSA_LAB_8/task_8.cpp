#include<iostream>
#include<vector>
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

    int height(Node* root){
        static int count = 0;
        if (root==NULL)
        {
            return count;
        }
        count++;
        height(root->left);
        height(root->right);

        
    }
    void storeInArray(Node* root,vector<int> &arr){
        if (root==NULL)
        {
            return;
        }
        storeInArray(root->left,arr);
        arr.push_back(root->data);
        storeInArray(root->right,arr);
        
    }

    int median(Node* root){
        vector<int> arr;
        storeInArray(root,arr);
        int n=arr.size();
        if(n%2==0){
            return (arr[(n / 2) - 1] + arr[n / 2]) / 2;
        }
        return arr[(n/2)];
    }

    int ocurrenceInRange(Node* root,int a,int b){
        if (root==NULL)
        {
            return 0;
        }
        int count = 0;
        count += ocurrenceInRange(root->left,a,b);
        if (root->data >= a && root->data<=b)
        {
            count++; 
        }
        count +=  ocurrenceInRange(root->right,a,b);
        return count;
        
    }

};
int main(){
    BST b;
    b.insert(10);
    b.insert(1);
    b.insert(5);
    b.insert(50);
    b.insert(40);
    b.insert(100);
    cout<<b.ocurrenceInRange(b.root,5,45);
}   