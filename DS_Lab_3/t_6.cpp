#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int d=0):data(d), next(NULL){}
};

class LinkedList{
    Node *head;
    Node *tail;
    public:
        LinkedList(){
            head = tail= NULL;
        }

        void push_back(int d){
            Node *temp  = new Node(d);
            if (head==NULL)
            {
                head = tail =  temp;
                return;
            }
            tail->next = temp;
            tail = temp;
        }
        void push_front(int d){
            Node *temp  = new Node(d);
            if (head==NULL)
            {
                head = tail =  temp;
                return;
            }
            temp->next = head;
            head  = temp;
        }
    
        void insertByPos(int p,int d){
            Node *newNode  = new Node(d);
            Node *temp  = head;
            for (int i = 0; i < p-1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next  = newNode;
            
        }
        void deleteByValue(int d){
            
            Node *temp  = head;
            Node *t2  = NULL;
            if (temp->data ==d)
            {
                cout<<"Error! -  First element of the list cannot be deleted\n";
                return;
            }
            
            
            
            while (temp->next!=NULL)
            {
                if (temp->next ==tail && tail->data == d)
                {
                    t2 = tail;
                    tail = temp;
                    tail->next = NULL;
                    cout<<"Found and deleted\n";
                    return;
                }
                
                if (temp->next->data == d)
                {
                    t2 = temp->next;
                    temp->next = temp->next->next;
                    delete t2;
                    t2 = NULL;
                    cout<<"Found and deleted\n";
                    return;
                }
                else 
                    temp = temp->next;
                
            }
            
        }
        
        void print(){
            Node *temp  = head;
            while (temp!=NULL)
            {
                cout<<temp->data<<" -> ";
                temp = temp->next;
            }
            cout<<"NULL\n";
            
            
        }
    };

int main(){
   
    LinkedList l1;
    l1.push_back(3);
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(5);
    l1.push_back(8);
    l1.push_back(9);
    l1.insertByPos(3,11);
    l1.push_front(4);
    l1.deleteByValue(11);
    l1.deleteByValue(5);
    l1.deleteByValue(4);
    l1.print();

   
}