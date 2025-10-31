#include<iostream>
using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
    const int id;
    int quantity;
    Node(const int i,int q = 0):id(i){
        left = right = NULL;
        quantity = q;
    }
};

class Inventory{
    public:
    Node* root;
    Inventory(){
        root = NULL;
    }
    void insert(Node* n){
        root = insertNode(root,n);
    }
    Node* insertNode(Node* root,Node* q){
        if (root==NULL)
        {
            return q;
        }

        if (root->id>q->id)
        {
            root->left = insertNode(root->left,q);
        }
        if (root->id<q->id)
        {
            root->right = insertNode(root->right,q);
        }

        return root;
        
        
    }

    void Display(Node* root){
        if (root==NULL)
        {
            return;
        }
        Display(root->left);
        cout<<"\nProduct ID: "<<root->id<<endl;
        cout<<"Product quantity: "<<root->quantity<<endl;
        Display(root->right);
    }
    void updateQuantity(Node* root,int id){
        if (root==NULL)
        {
            return;
        }
        if (root->id==id)
        {
            cout<<"Found\n";
            cout<<"Enter new quantity: ";
            int q;
            cin>>q;
            root->quantity = q;
            cout<<"Succesfully updated\n";
            return;
        }
        
        if (root->id >id )
        {
            updateQuantity(root->left,id);
        }
        if (root->id<id )
        {
            updateQuantity(root->right,id);
        }
        return;
    }
    int Highest(Node* root){
        static int max  = 0;
        static int id  = 0;
        if (root==NULL)
        {
            return id;
        }
        Highest(root->left);
        if (root->quantity>max)
        {
            max = root->quantity;
            id = root->id;
        }
        Highest(root->right);
        return id;
        
    }

    
    void Search(Node* root,int id){
        if (root==NULL)
        {
            return;
        }
        if (root->id==id)
        {
            cout<<"Found\n";
            cout<<"Quantity available: "<<root->quantity<<endl;
            return;
        }
        
        if (root->id >id )
        {
            Search(root->left,id);
        }
        if (root->id<id )
        {
            Search(root->right,id);
        }

        return;
        
    }
};
int main(){
    Node *n1 = new Node(5,10);
    Node *n2 = new Node(3,11);
    Node *n3 = new Node(9,1);
    Node *n4 = new Node(10,3);
    Inventory i;
    i.insert(n1);
    i.insert(n2);
    i.insert(n3);
    i.insert(n4);
    i.Display(i.root);
    i.updateQuantity(i.root,3);
    i.Search(i.root,3);
    cout<<"ID of max quantity's Product : ";
    int id = i.Highest(i.root);
    cout<<id;
    cout<<endl;
    i.Search(i.root,id);
}