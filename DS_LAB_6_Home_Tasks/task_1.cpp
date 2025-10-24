#include<iostream>
using namespace std;

class Node{
    public:
    string item;
    Node* next;
    Node(string s = ""){
        item = s;
        next = NULL;
    }

};

class ToDoList{
    Node *head;
    Node *top;
    public:
        ToDoList(){
            head = top = NULL;
        }

        void addItem(string s){
            Node* temp = new Node(s);
            if (!head)
            {
                head = top = temp;
            }
            else{
                top->next = temp;
                top = temp;
            }
            
        }

        bool isEmpty(){
            return top==NULL;
        }

        void removeTopItem(){
            if (isEmpty())
            {
                cout<<"List is already empty\n";
                return;
            }

            Node* temp = head;
            if (temp==top)
            {
                delete temp;
                temp = top = NULL;
                return;
            }
            
            while (temp->next!=top)
            {
                temp = temp->next;
            }
            top = temp;
            delete temp->next;
            temp->next = NULL;
            
        }

        
        void displayList(){
            Node* temp = head;
            while (temp)
            {
                cout<<temp->item<<endl;
                temp = temp->next;
            }

            cout<<endl;
            
        }
};

int main(){
    ToDoList l;
    l.addItem("sleep");
    l.addItem("eat");
    l.addItem("work");
    l.addItem("repeat");
    l.displayList();
    l.removeTopItem();
    l.displayList();
    cout<<(l.isEmpty()?"Yes":"No");
}