#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int d=0):data(d), next(NULL){}
};

class CircularLinkedList{
    Node *head;
    Node *tail;
    public:
        CircularLinkedList(){
            head = tail= NULL;
        }

        void push_back(int d){
            Node *temp  = new Node(d);
            if (head==NULL)
            {
                head = tail =  temp;
                tail->next = head;
                return;
            }
            tail->next = temp;
            tail = temp;
            tail->next = head;
        }
        void pushFront(int d){
            Node *temp  = new Node(d);
            if (head==NULL)
            {
                head = tail =  temp;
                tail->next = head;
                return;
            }
            
            temp->next = head;
            head = temp;
            tail->next = temp;
            
        }
        
        void pushByPos(int p,int d){
            Node *temp  = new Node(d);
            Node *temp2  = head;
            for (int i = 0; i < p-1; i++)
            {
                temp2 = temp2->next;
            }
            
            temp->next = temp2->next;
            temp2->next = temp;

        }
        void deleteByValue(int d){
            Node *temp  = head;
            Node *t2  = NULL;
            if (temp->data ==d)
            {
                t2 = temp;
                temp = temp->next;
                head = temp;
                head = tail;
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
        
        void print(){
            Node *temp  = head;
            int j = 1;
            do
            {
                cout<<temp->data<<" -> ";
                temp  = temp->next;
                j++;

            } while (temp!=head);


            
            
            
            
            
            

        }
    };

    int main(){
        CircularLinkedList l1;
        l1.push_back(3);   
        l1.push_back(2);
        l1.deleteByValue(3);
        l1.pushFront(1);
        l1.pushByPos(1,4);   
        l1.print();
    }