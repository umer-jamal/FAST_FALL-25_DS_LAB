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
        void reverseAlternativeNodes(){
            if (!head || !head->next)
            {
                return;
            }

            Node *temp = head;
            int len = 0;
            while (temp!=NULL)
            {
                temp = temp->next;
                len++;
            }
            
            if (len%2==0)
            {
                len/=2;
                len--;
            }
            else
                len/=2;
            
            temp =head->next;
            Node* prev = head;
            Node* next = temp->next;
            Node *end = NULL;
            for (int i = 0; i < len; i++)
            {
                while (temp->next!=NULL && temp->next!=end)
                {
                    temp->next = temp->next->next;
                    next->next = temp;
                    prev->next = next;
                    prev = next; 
                    next = temp->next;

                }
                end = temp;
                temp = head->next;
                prev = head;
                for (int j = 0; j < i+1; j++)
                {
                    temp = temp->next;
                    prev = prev->next;
                }
                next = temp->next;
                
                
            }

            temp = head;
            while (temp->next!=NULL)
            {
                temp = temp->next;
            }

            tail = temp;
            return;
            
            
            

            
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
    l1.push_back(10);
    l1.push_back(4);
    l1.push_back(9);
    l1.push_back(1);
    l1.push_back(3);
    l1.push_back(5);
    l1.push_back(9);
    l1.push_back(4);
    // l1.push_back(1);
    // l1.push_back(2);
    // l1.push_back(4);
    // l1.push_back(8);
    // l1.push_back(5);
    cout<<"Original list\n";
    l1.print();
    cout<<"\nlist after reversing alternative nodes and appending \n\n";
    l1.reverseAlternativeNodes();
    l1.print();

   
}