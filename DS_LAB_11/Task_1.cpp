#include<iostream>
using namespace std;

class Node{
    public:
    string data;
    Node* next;
    string key;
    Node(string s="",string k=""){
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

class HashTable{
    Node **arr;
    int size;
    public:
        HashTable(int s){
            size = s;
            arr = new Node*[size];
            for (int i = 0; i <size; i++)
            {
                arr[i]  = NULL;
            }
            
        }

        void insert(string k,string val){
            Node *n = new Node(val,k);
            int ind = sum(k)%size;
            if (arr[ind]==NULL)
            {
                arr[ind] = n;
            }
            else{
                n->next = arr[ind];
                arr[ind] = n;
            }
            
        }
        void remove(string k,string s){
            int ind = sum(k)%size;
            if (arr[ind]==NULL)
            {
                cout<<"Not found\n";
                return;
            }
            Node* temp = arr[ind];
            Node* prev = nullptr;
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
    HashTable m(10);
    m.insert("A","aaa");
    m.insert("B","aaabbb");
}