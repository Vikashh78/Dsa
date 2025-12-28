#include <iostream>
using namespace std;
#include <stack>

bool isValid(string s) {
    // creating a stack of type character
    stack<char> st;

    for(int i=0; i<s.size(); i++) {
        char ch = s[i];

        // if opening bracket encountered then push it to the stack
        if((ch == '(') || (ch == '{') || (ch == '[')) {
            st.push(ch);
        }

        else { // brackets are closing brackets
        
            if(! st.empty()) {
                
                if((st.top() == '(' && ch == ')') || (st.top() == '{' && ch == '}')
                    || (st.top() == '[' && ch == ']')) {
                    
                    st.pop();
                }

                else {  // brackets mismatched
                    return false;
                }

            }

            else { // there is only one bracket i.e. ) || } || ], and stack is empty
                return false;
            }

        }
    }

    if(st.empty())  // after popping all brackets successfully
    return true;

    else 
    return false;
}



int main() {

    //string s = "([]{()})[{}()]";
    string s = "]";

    if(! isValid(s)) {
        cout<<"Not valid "<<endl;
    }

    else {
        cout<<"Valid parentheses"<<endl;
    }

    return 0;
}