#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int d=0){
        this->data = d;
        next = NULL;
    }
};

class LinkedList{
    Node* head;
    Node* tail;
    public:
        LinkedList(){
            head = tail = NULL;
        }

        void push_back(int d){
            Node *temp = new Node(d);
            if (!head)
            {
                head = tail = temp;
            }
            else{
                tail->next = temp;
                tail = temp;
            }
            
        }

        void push_front(int d){
            Node *temp = new Node(d);
            if (!head)
            {
                head = tail = temp;
            }
            else{
                temp->next = head;
                head = temp;
            }
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

        void bubbleSort(){
            
            int size = 0;
            Node *temp1 = head;
            if (temp1==NULL || temp1->next ==NULL)
            {
                return;
            }
            while (temp1)
            {
                size++;
                temp1 = temp1->next; // calculating lenght of list
            }

            for (int i = 0; i < size; i++)
            {
                Node *temp = head;
                if (temp==NULL || temp->next ==NULL)
                {
                    return;
                }
                
                while (temp->next!=NULL)
                {
                    if (temp->data > temp->next->data)
                    {
                        swap(temp->data,temp->next->data);
                    }
                    temp = temp->next;
                    
                }
        }
            
        }
};



int main()
{
    LinkedList l1;
    l1.push_back(5);
    l1.push_back(4);
    l1.push_back(2);
    l1.push_back(10);
    l1.push_back(0);
    l1.print();
    l1.bubbleSort();
    l1.print();

return 0;
}
