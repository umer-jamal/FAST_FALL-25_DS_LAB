#include<iostream>
using namespace std;

class Node{
    public:
    Node *left;
    Node *right;
    float score;
    string name;
    int roll;
    Node(string n="",float sc=0,int r=0){
        score = sc;
        name = n;
        roll = r;
        left = right = NULL;
    }

    
};

class Students{
    public:
    Node *root;
    Students(){
        root = NULL;
    }

    Node* insertNode(Node *root,Node *n){
        if (root==NULL)
        {
            return n;
        }

        if (n->name < root->name)
        {
            root->left = insertNode(root->left,n);
        }
        if (n->name >= root->name)
        {
            root->right = insertNode(root->right,n);
        }
        
        return root;
        
    }
    Node* deleteStudentsLessThan10(Node *root){
        if (root==NULL)
        {
            return NULL;
        }
        root->left= deleteStudentsLessThan10(root->left);
        root->right =  deleteStudentsLessThan10(root->right);
        if (root->score<10)
        {
            return deleteStudent(root,root->name);
        }
        return root;
    }
void deleteAllStudentsLessThan10Score(){
    root  = deleteStudentsLessThan10(root);
}

    void insert(Node *n){
        root = insertNode(root,n);
    }
    void inOrder(Node* root){
        if (root==NULL)
        {
            return;
        }

        inOrder(root->left);
        cout<<"Student name: is "<<root->name<<endl;
        cout<<"Score is: "<<root->score<<endl<<endl;
        cout<<"Roll number: is "<<root->roll<<endl;
        inOrder(root->right);
        
    }
    void search(Node *root,string name){
        if (root==NULL)
        {
            return;
        }

        if (root->name==name)
        {
            cout<<"Found\n";
            return;
        }
        
        if (root->name > name)
        {
            search(root->left,name);
        }
        if (root->name < name)
        {
            search(root->right,name);
        }
        
        
    }

    Node* findMin(Node* root){
        while (root && root->left)
        {
            root = root->left;
        }
        return root;
        
    }

    Node* deleteStudent(Node* root,string name){
        if (root==NULL)
        {
            return NULL;
        }
        
        if (root->name==name)
        {
            if (root->left==NULL && root->right==NULL)
            {
                delete root;
                return NULL;
            }

            else if(root->left==NULL){
                Node* temp = root->right;
                delete root;
                return temp;

            }
            else if(root->right==NULL){
                Node* temp = root->left;
                delete root;
                return temp;

            }

            else{
                Node *temp = findMin(root->right);
                root->name = temp->name;
                root->roll= temp->roll;
                root->score = temp->score;
                root->right = deleteStudent(root->right,temp->name);
            }
            
        }
        
        if (root->name > name)
        {
            root->left = deleteStudent(root->left,name);
        }
        if (root->name < name)
        {
            root->right = deleteStudent(root->right,name);
        }

        return root;
    }


};

int main(){
    Node *s1 = new Node("arif",10,90);
    Node *s2 = new Node("umer",1,58);
    Node *s3 = new Node("kamil",4,60);
    Node *s4 = new Node("asad",60,30);
    Node *s5 = new Node("waqar",13,44);

    Students s;
    s.insert(s1);
    s.insert(s2);
    s.insert(s3);
    s.insert(s4);
    s.insert(s5);
    s.search(s.root,"umer");
    cout<<endl;    
    s.deleteAllStudentsLessThan10Score();
    s.inOrder(s.root);
}