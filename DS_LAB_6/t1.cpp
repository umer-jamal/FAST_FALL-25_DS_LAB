#include<iostream>
using namespace std;

class Node{
    public:
    char data;
    Node *next;
    Node(char d=0):data(d),next(nullptr){}
};

class Stack{
    // Node *head;
    // Node *top;
    char *arr;
    int size;
    int top;
    public: 
    Stack(int s){
        // head = top = nullptr;
        size = s;
        arr = new char[size];
        top = -1;
    }

    void push(char ch){
        if (top<size)
        {
            top++;
            arr[top] = ch;
        }
        else{
            cout<<"Stack is full\n";
        }
        

    }
    bool isEmpty(){
        if (top==-1)
        {
            return 1;
        }
        return 0;
        
    }
    void pop(){
        if (isEmpty())
        {
            cout<<"Stack is empty\n";
            return;
        }
        
        arr[top] = '0';
        top--;
    }
    char peek(){
        return arr[top];
    }
    void display(){
        for (int i = 0; i <= top; i++)
        {
            cout<<arr[i]<<" -> ";
        }
        cout<<endl;
    }


    // void push(char c){
    //     Node* n = new Node(c);
    //     if (!head)
    //     {
    //         head = top = n;
    //     }
    //     else{
    //         top->next = n;
    //         top = n;
    //     }
    // }

    // void pop(){
    //     Node *temp = head;
    //     if (temp==top)
    //     {
    //         delete temp;
    //         temp = NULL;
    //         head = top = NULL;
    //         return;
    //     }
        
    //     while (temp->next!=top)
    //     {
    //         temp = temp->next;
    //     }
    //     delete temp->next;
    //     temp->next = NULL;
    //     top = temp;
        
    // }

    // void display(){
    //     Node* temp = head;
    //     while (temp)
    //     {
    //         cout<<temp->data<<" -> ";
    //         temp = temp->next;
    //     }
    //     cout<<"NULL\n";
        
    // }

    // char topChar(){
    //     return top->data;
    // }

    // bool isEmpty(){
    //     if (top!=NULL)
    //     {
    //         return 0;
    //     }
    //     return 1;       
    // }

    
};

// bool isPalindrome(string s){
//     Stack s1;
//     for (int i = 0; i < s.size(); i++)
//     {
//         s1.push(s[i]);
//     }
    
//     string n;
//     while (!s1.isEmpty())
//     {
//         n += s1.topChar();
        
//         s1.pop();
//     }
//     if (n==s)
//     {
//         return 1;
//     }
//     return 0;
    

    
// }

bool isPalindrome(string s){
    Stack st(s.size());
    for (int i = 0; i < s.size(); i++)
    {
        st.push(s[i]);
    }

    string n;
    while (!st.isEmpty())
    {
        n+= st.peek();
        st.pop();
    }

    if (n==s)
    {
        return 1;
    }
    return 0;
    
    
    
}
int main()
{
    // cout<<(isPalindrome("0110") ? "Its a palindrome\n" : "Its not a palindtrome\n");
    
    cout<<(isPalindrome("BORROWROB") ? "Its a palindrome\n" : "Its not a palindtrome\n");
return 0;
}
