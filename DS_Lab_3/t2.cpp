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
                t2 = temp;
                temp = temp->next;
                delete t2;
                t2 = NULL;
                return;
            }
            
            
            
            while (temp->next!=NULL)
            {
                if (temp->next->data == d)
                {
                    t2 = temp->next;
                    temp->next = temp->next->next;
                    delete t2;
                    t2 = NULL;
                    return;
                }
                temp = temp->next;
                
            }
            
        }

        void rotateByIndex(int ind){
            // Node* temp  =  head;
            for (int i = 0; i < ind; i++)
            {
                tail->next = head;
                head = head->next;
                tail = tail->next;
                tail->next= NULL;
                // cout<<tail->data<<endl;
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
    l1.push_back(10);
    l1.insertByPos(3,11);
    l1.push_front(0);
    l1.print();
    l1.rotateByIndex(2);
    l1.print();
    
}