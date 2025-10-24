#include<iostream>
using namespace std;

class Node{
    public:
    string url;
    Node* next;
    Node(string s = ""){
        url = s;
        next = NULL;
    }

};

class Web_Browsing_History{
    Node *head;
    Node *top;
    public:
        Web_Browsing_History(){
            head = top = NULL;
        }

        void visitWebsite(string s){
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

        void back(){
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

        void backTwice(){
            back();
            back();
        }

        
        void displayList(){
            Node* temp = head;
            while (temp)
            {
                cout<<temp->url<<" -> ";
                temp = temp->next;
            }

            cout<<endl;
            
        }
};

int main(){

    Web_Browsing_History w;
    w.backTwice();
    w.visitWebsite("Google");
    w.visitWebsite("FB");
    w.visitWebsite("INSTA");
    w.visitWebsite("Youtube");
    w.displayList();
    w.back();
    w.displayList();
    w.backTwice();
    w.displayList();
}