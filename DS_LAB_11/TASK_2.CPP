#include<iostream>
using namespace std;


class Node{
    public:
    string data;
    Node* next;
    int key;
    Node(string s="",int k=0){
        data = s;
        next = NULL;
        key = k;

    }
};

int sum(string s){
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        count+=s[i];
    }

    return count;
    
}

class ASCII_Dictionary{
    Node** arr;
    public:
        ASCII_Dictionary(){
            arr = new Node*[100];
            for (int i = 0; i < 100; i++)
            {
                arr[i] = NULL;
            }
            
        }
        void insert(string s){
            Node* n = new Node(s,sum(s));
            int ind = sum(s)%100;
            if (arr[ind]==NULL)
            {
                arr[ind]= n;
                return;
            }
            n->next = arr[ind];
            arr[ind] = n;
            
        }
        void search(string s){
            int ind = sum(s)%100;
            if (arr[ind]->data==s)
            {
                cout<<"Found\n";
                return;
            }
            Node* temp = arr[ind];
            while (temp)
            {
                if(temp->data ==s)
                {  
                    cout<<"Found\n";
                    return;
                }
                temp = temp->next;
            }
            cout<<"Not found\n";
            
        }

        void display(){
            for (int i = 0; i <100 ; i++)
            {
                if (arr[i]!=NULL)
                {
                    cout<<i<<" : "<<arr[i]->data;
                    Node *temp = arr[i];
                    
                    while (temp->next)
                    {
                        cout<<" -> "<<temp->next->data;
                        temp = temp->next;
                    }
                    cout<<endl;
                }
                
            }
            
        }
        void deleteWord(string s){
            int ind = sum(s)%100;
            Node* temp = arr[ind];
            Node* prev = NULL;
            while (temp && temp->data!=s)
            {
                prev = temp;
                temp = temp->next;
            }

            if (temp==NULL)
            {
                cout<<"Not found\n";
                return;
            }
            if (prev==NULL)
            {
                arr[ind] = temp->next;
            }
            else{
                prev->next = temp->next;
            }

            delete temp;
            
            
            
        }

        



};


int main(){
    ASCII_Dictionary a;
    a.insert("good");
    a.insert("bad");
    a.insert("delicious");
    a.deleteWord("bad");
    a.display();
}