#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int height;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = right = NULL;
        height = 1;
    }
};

class BST{
    public:
    Node* root;
    BST(){
        root = NULL;
    }
  

int getHeight(Node *n)
{
    return (n == NULL) ? 0 : n->height;
}

int getBalance(Node *n)
{
    return (n == NULL) ? 0 : getHeight(n->left) - getHeight(n->right);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *temp = x->right;
    x->right = y;
    y->left = temp; // y: originally unbalanced node (root of that subtree)

                        // x: its left child (becomes new root)

                            // t2: temporarily stores x’s right subtree so it doesn’t get lost

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node *leftRotate(Node *y)
{
    Node *x = y->right;
    Node *temp = x->left;
    x->left = y;
    y->right = temp;    //y: unbalanced node
                            // x: right child that becomes new root
                            // t2: subtree that sits between y and x

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

// The variable x (from the rotation) becomes the topmost node after balancing.
// Returning it ensures that the parent node correctly reconnects to this balanced subtree.
// When the recursion unwinds, these new roots propagate up, giving you a completely balanced AVL tree.

    return x;
}

Node *convertBSTtoAVL(Node *root)
{
    if (root==NULL)
    {
        return NULL;
    }

    root->left = convertBSTtoAVL(root->left);
    root->right = convertBSTtoAVL(root->right);
    root->height = 1+max(getHeight(root->left),getHeight(root->right));

    int balance = getBalance(root);

    if (balance>1 && getBalance(root->left) >=0)
    {
        return rightRotate(root);
    }
    if (balance>1 && getBalance(root->left) <0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);   
    }
    if (balance<-1 && getBalance(root->right) <=0)
    {
        return leftRotate(root);
    }
    if (balance<-1 && getBalance(root->right) >0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root); 

// For Left–Right (LR):
// First perform leftRotate(root->left)
// Then rightRotate(root)
// For Right–Left (RL):
// First perform rightRotate(root->right)
// Then leftRotate(root)
// These combinations handle "zig-zag" imbalances.
    }

    return root;
    
}
void insert(int d){
    root = insertInBST(root,d);
}

Node *insertInBST(Node *root, int d)
{
    if (root == NULL)
        return new Node(d);
    if (d < root->data)
        root->left = insertInBST(root->left, d);
    else if (d > root->data)
        root->right = insertInBST(root->right, d);
    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

};
// The function processes each node bottom-up, recalculating its height and balance.
// If a node becomes unbalanced, rotations (right, left, or double) are applied to restore AVL balance.
// Temporary pointers like x, y, and t2 preserve subtree links during reattachment.
// The rotated node (usually x) is returned because it becomes the new balanced root of that subtree.
int main()
{
    BST b;
    b.insert(15);
    b.insert(11);
    b.insert(10);
    b.insert(12);
    b.inorder(b.root);
    cout<<endl;
    cout<<"Current root is: "<<b.root->data<<endl;
    b.root = b.convertBSTtoAVL(b.root);
    b.inorder(b.root);
    cout<<endl;
    cout<<"Current root is: "<<b.root->data<<endl;
    return 0;
}
