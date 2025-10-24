#include <iostream>
#include <stack>
#include <string>
using namespace std;

string infixToPostfix(string &s) {
    stack<char> st;
    string postfix = "";
    
    for (int i = 0;i<s.size();i++) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || s[i] >='a' && s[i]<='z' ) {  
            postfix += s[i];
        } 
        else if (s[i] == ')') {
            //pop until '('
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else {                        
            st.push(s[i]);
            
        }
    }
    while (!st.empty()) {             // pop all operators
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string s = "(a+b)*c";
    cout << "Postfix expression: " << infixToPostfix(s) << endl;
    return 0;
}
