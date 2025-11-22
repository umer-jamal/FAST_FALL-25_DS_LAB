#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    int key;
    Node(int val=0,int k=0){
        data = val;
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

class MyHash{
    Node** arr;
    int size;
    public:
        MyHash(int s){
            size = s;
            arr = new Node*[size];
            for (int i = 0; i < size; i++)
            {
                arr[i] = NULL;
            }
            
        }
        void insert(int k,int val){
            Node* n = new Node(val,k);
            int ind = k%size;
            if (arr[ind]==NULL)
            {
                arr[ind]= n;
                return;
            }
            n->next = arr[ind];
            arr[ind] = n;
            
        }
        void search(int k,int val){
            int ind = k%size;
            if (arr[ind]->data==val)
            {
                cout<<"Found\n";
                return;
            }
            Node* temp = arr[ind];
            while (temp)
            {
                if(temp->data ==val)
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
        void remove(int k,int val){
            int ind = k%size;
            Node* temp = arr[ind];
            Node* prev = NULL;
            while (temp && temp->data!=val)
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
    MyHash m(10);
    m.insert(4,5);
    m.insert(4,6);
    m.insert(2,10);
    m.insert(1,12);
    m.insert(8,54);
    m.remove(1,12);
    m.display();
}