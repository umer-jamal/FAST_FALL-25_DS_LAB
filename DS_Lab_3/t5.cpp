#include<iostream>
using namespace std;

class Node{
    public:
        string data;
        Node* next;
        Node(string d=0):data(d), next(NULL){}
};

class LinkedList{
    Node *head;
    Node *tail;
    public:
        LinkedList(){
            head = tail= NULL;
        }

        void push_back(string d){
            Node *temp  = new Node(d);
            if (head==NULL)
            {
                head = tail =  temp;
                return;
            }
            tail->next = temp;
            tail = temp;
        }
        void push_front(string d){
            Node *temp  = new Node(d);
            if (head==NULL)
            {
                head = tail =  temp;
                return;
            }
            temp->next = head;
            head  = temp;
        }
    
        void insertByPos(int p,string d){
            Node *newNode  = new Node(d);
            Node *temp  = head;
            for (int i = 0; i < p-1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next  = newNode;
            
        }
        void deleteByValue(string d){
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

        void reverse(LinkedList *list){
            Node* temp  =  head;
            while (temp!=NULL)
            {
                list->push_front(temp->data);
                temp = temp->next;
            }
            
        }

        void rotateByIndex(int ind){
            Node* temp  =  head;
            for (int i = 0; i < ind; i++)
            {
                tail->next = head;
                head = head->next;
                tail = tail->next;
                tail->next= NULL;
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
        
        bool checkPalindrome(LinkedList *list){
            Node *temp  = head;
            Node *temp2  = list->head;
            while (temp!=NULL)
            {
                if (temp->data!=temp2->data)
                {
                    return 0;
                }
                temp = temp->next;
                temp2 = temp2->next;
                
            }
            return 1;
            
            
        }
    };


    int main(){
        LinkedList l1,l2;
    l1.push_back("1");
    l1.push_back("1");
    l1.push_back("0");
    l1.push_back("1");
    l1.push_back("1");
    // l1.push_back(9);
    // l1.push_back(10);
    l1.print();
    l1.reverse(&l2);
    l2.print();
    cout<<(l1.checkPalindrome(&l2) ? "Its a palindrome\n":"its not a palindrome\n"); 
    }