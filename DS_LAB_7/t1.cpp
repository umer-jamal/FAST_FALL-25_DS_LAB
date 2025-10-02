#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int d=0):data(d),next(NULL),prev(NULL){}


};

class List{
    Node* head;
    Node* tail;
    public:
        List(){
            head = tail = NULL;
        }

        void pushBack(int v){
            Node *temp = new Node(v);
            if (!head)
            {
                head = tail = temp;
                return;
            }
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
            
        }

        void pop_Front(){
            Node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }

        void pop_Back(){
            Node *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;

        }


        void pop_pos(int pos){

            Node *temp = head;
            for (int i = 0; i < pos-1; i++)
            {
                temp = temp->next;
            }
            Node *t2 = temp->next;
            temp->next = temp->next->next;
            temp->next->prev = temp;
            delete t2;
            
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
};


int main(){
List l1;
l1.pushBack(3);
l1.pushBack(2);
l1.pushBack(33);
l1.pushBack(34);
l1.pushBack(5);
l1.pushBack(22);
l1.print();
l1.pop_Back();
l1.pop_Front();
l1.pop_pos(2);
l1.print();
}