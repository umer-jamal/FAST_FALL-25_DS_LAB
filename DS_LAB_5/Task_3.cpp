#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node *next;
    Node(int x=0):data(x),next(NULL){}
};

class LinkedList{
    public: 
    Node *head;
    Node *tail;
        LinkedList(){
            head = tail =  NULL;
        }
        void push_back(int d){
            Node *temp = new Node(d);
            if (head==NULL)
            {
                head = tail = temp;
                return;
            }

            tail->next = temp;
            tail = temp;
            
        }

        void print(){
            Node *temp = head;
            while (temp!=NULL)
            {
                cout<<temp->data<<" -> ";
                temp = temp->next;
            }
            cout<<"NULL\n";
            
            
        }

        void printBackwards(Node *t=NULL){
            // Node *temp = head;
            if (t->next==NULL)
            {
                cout<<t->data<<" -> ";
                return ;
            }
            printBackwards(t->next);
            cout<<t->data<<" -> ";

        }
        int findLenght(Node *t,int c=0){
            if (t->next==NULL)
            {
                // count+=c+1;
                return c+1 ;
            }
            return findLenght(t->next,c+1);

        }

};
           



int main(){
    LinkedList l1;
    l1.push_back(3);
    l1.push_back(2);
    l1.push_back(1);
    l1.push_back(0);
    l1.push_back(-1);
    l1.print();
    cout<<l1.findLenght(l1.head);
}