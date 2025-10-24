#include<iostream>
#include<vector>
#include <cstdlib>
#include <string>


using namespace std;

class Node{
    public:
    string data;
    Node *next;
    Node(string s=""){
        data = s;
        next = NULL;
    }
};

class Stack{
    Node* top;
    Node* head;
    public:
    Stack(){
        top = head = NULL;
    }
    Stack(const Stack &obj) {
    if (obj.head == NULL) {
        head = top = NULL;
        return;
    }

    head = new Node(obj.head->data);
    Node *currNew = head;
    Node *currOld = obj.head->next;

    while (currOld != NULL) {
        currNew->next = new Node(currOld->data);
        currNew = currNew->next;
        currOld = currOld->next;
    }

    top = currNew;
}
    void push(string s){
        Node *temp = new Node(s);
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
    
    void pop(){
        if (isEmpty())
        {
            return;
        }
        
        Node *temp = head;
        if (temp==top)
        {
            delete temp;
            top = head = NULL;
            return;
        }
        
        while (temp->next!=top)
        {
            temp = temp->next;
        }

        top = temp;
        delete temp->next;
        top->next = NULL;
        

    }
    Node* getTop(){return top;}
    string topValue(){
        return top->data;
    }

    int size(){
        if (isEmpty())
        {
            return 0;
        }
        int count = 0;
        Node *temp = head;
        while (temp)
        {
            temp = temp->next;
            count++;
        }
        return count;
        
    }
};

int calculate(const Stack &stack){
    Stack st = stack; //deep copy
    int ans;
    vector<int> num;
    vector<string> op;
    while (!st.isEmpty())
    {

        if (st.topValue()=="+" || st.topValue()=="-"||st.topValue()=="*"||st.topValue()=="/")
        {
            op.push_back(st.topValue());
            st.pop();
        }
        else if(st.topValue()==")"){
            st.pop();
            int a = std::stoi(st.topValue());
            st.pop();
            if (st.topValue()=="+")
            {
                st.pop();
                a += std::stoi(st.topValue());
            }
            else if(st.topValue()=="-"){
                 st.pop();
                a -= std::stoi(st.topValue());
            }
            else if(st.topValue()=="*"){
                 st.pop();
                a *= std::stoi(st.topValue());
            }
            else if(st.topValue()=="/"){
                st.pop();
                a *= std::stoi(st.topValue());
            }

            num.push_back(a);
            st.pop();
            st.pop();
            

        }
        // else if(st.topValue()=="(") continue;
        else if(st.topValue()=="=") break;
        else{
            num.push_back(std::stoi(st.topValue()));
            st.pop();

        }
    }
    ans = num[0];
    for (int i = 0; i+1 <num.size(); i++)
    {
        if (op[i]=="+")
        {
            ans += num[i+1];
        }
        else if (op[i]=="-")
        {
            ans -= num[i+1];
        }
        else if (op[i]=="*")
        {
            ans *= num[i+1];
        }
        else if (op[i]=="/")
        {
            ans /= num[i+1];
        }
        
        
    }
    return ans;
}

void StringToStack(string s){
    Stack sta;
                                    
// first pushing equation in stack
    for (int i = 0; i < s.size(); i++)
    {
        string n;
        if (s[i]>='0' && s[i]<='9')
        {
            while (s[i]>='0' && s[i]<='9')
            {
                n+= s[i];
                i++;
            }
            sta.push(n);
            i--;
            
        }
        else{
            n = s[i];
            sta.push(n);
        }
        
    }

    
    cout<<endl;  // calculate function returning the answer of equation, then pusing it back to the stack
    sta.push(to_string(calculate(sta)));
    
    int n = sta.size(); // printing and poping out 
    for (int i = 0; i < n; i++)
    {
        cout<<sta.topValue()<<"  ";
        sta.pop();
    }

    
}



int main(){

    StringToStack("x=5+(12+4)*1");
}