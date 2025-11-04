#include <iostream>
using namespace std;

class Node
{
public:
    int height;
    int data;
    string name;
    Node *left;
    Node *right;
    Node(string s="",int d = 0)
    {
        data = d;
        name = s;
        right = left = NULL;
        height = 1;
    }
};

class AVL
{
public:
    Node *root;
    AVL()
    {
        root = NULL;
    }

    int getBalance(Node *n)
    {
        if (n == NULL)
        {
            return 0;
        }

        return getHeight(n->left) - getHeight(n->right);
    }

    Node *leftRotate(Node *y)
    {
        Node *x = y->right;
        Node *temp = x->left;
        x->left = y;
        y->right = temp;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }
    int getHeight(Node *n)
    {
        return (n == NULL) ? 0 : n->height;
    }
    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *temp = x->right;
        x->right = y;
        y->left = temp;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }
    void insert(string s,int d)
    {
        root = insertNode(root,s, d);
    }
    Node *insertNode(Node *root, string s,int d)
    {
        if (root == NULL)
        {
            return new Node(s,d);
        }

        if (root->data > d)
        {
            root->left = insertNode(root->left,s, d);
        }
        else if (root->data < d)
        {
            root->right = insertNode(root->right,s, d);
        }
        else
        {
            return root;
        }
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        int balance = getBalance(root);

        if (balance > 1 && d < root->left->data)
        {
            return rightRotate(root);
        }
        if (balance > 1 && d > root->left->data)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && d > root->right->data)
        {
            return leftRotate(root);
        }
        if (balance < -1 && d < root->right->data)
        {
            root->right = rightRotate(root->right);
            root = leftRotate(root);
        }
        return root;
    }

    void inOrder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        inOrder(root->left);
        cout<<"Name is: "<<root->name<<"  , ";
        cout<<"Roll number is: "<< root->data << "\n";
        inOrder(root->right);
    }
    void deleteNode(int d)
    {
        root = deleteNode(root, d);
    }
    Node *deleteNode(Node *root, int d)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->data > d)
        {
            root->left = deleteNode(root->left, d);
        }
        else if (root->data < d)
        {
            root->right = deleteNode(root->right, d);
        }

        else if (root->data == d)
        {
            if (root->left == NULL)
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            if (root->right == NULL)
            {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            else if (root->left != NULL && root->right != NULL)
            {
                Node *temp = findMin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
            root->height = 1 + max(getHeight(root->left), getHeight(root->right));
            int balance = getBalance(root);

            if (balance > 1 && getBalance(root->left) >=0)
            {
                return rightRotate(root);
            }
            if (balance > 1 &&  getBalance(root->left) <0)
            {
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
            if (balance < -1 && getBalance(root->right) <=0)
            {
                return leftRotate(root);
            }
            if (balance < -1 && getBalance(root->right) >0)
            {
                root->right = rightRotate(root->right);
                root = leftRotate(root);
            }
        
        return root;
    }

    Node *findMin(Node *node)
    {
        while (node && node->left)
        {
            node = node->left;
        }
        return node;
    }

   
};

int main()
{
    AVL a;
    a.insert("Umer",10);
    a.insert("arif",20);
    a.insert("Jamal",30);
    a.insert("waqar",40);
    a.insert("asad",50); 
    a.inOrder(a.root);
    cout<<endl;
    // now tree looks like this  
       // 20
    //   /  \
    // 10    40
    //      /  \
    //    30    50   inserting 15 , then it will goes to the right of 10 
    a.insert("hussain",15);

    // tree is balance already no need to do any rotation
    // now it looks like 
    //    20
    //   /  \
    // 10    40
    //   \   /  \
    //   15 30   50

    cout<<"Height of tree is : "<<a.root->height<<endl;
    a.inOrder(a.root);
}