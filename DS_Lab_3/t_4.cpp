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
                if (temp->next ==tail && tail->data == d)
                {
                    t2 = tail;
                    tail = temp;
                    tail->next = NULL;
                    return;
                }
                
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
        
        void print(){
            Node *temp  = head;
            while (temp!=NULL)
            {
                cout<<temp->data<<" -> ";
                temp = temp->next;
            }
            cout<<"NULL\n";
            
            
        }

    void appearsEvenFirst(){

    Node *current = head;
    Node *next = head->next;
    Node *prevEven = NULL;

    if (head->data % 2 == 0) {
        prevEven = head;
    }

    while (next != NULL) {

        if (next->data % 2 == 0) {
            if (prevEven == NULL)
            {
                current->next = next->next;
                next->next = head;
                head = next;
                prevEven = head;
                next = current->next;
            } 
            
            else
            {
                if (prevEven->next == next)
                {
                    prevEven = next;
                    current = next;
                    next = next->next;
                }

                else
                {
                    current->next = next->next;
                    next->next = prevEven->next;
                    prevEven->next = next;
                    prevEven = next;
                    next = current->next;
                }
            }
        } 

        else
        {
            current = next;
            next = next->next;
        }
    }

    tail = current;
}
    };

int main(){
    LinkedList l1;
    l1.push_back(3);
    l1.push_back(1);
    l1.push_back(2);
    l1.push_back(5);
    l1.push_back(8);
    l1.insertByPos(3,11);
    l1.push_front(11);
    l1.print();
    l1.appearsEvenFirst();
    l1.print();
    
}