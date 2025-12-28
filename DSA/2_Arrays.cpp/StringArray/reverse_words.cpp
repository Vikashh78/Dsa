#include <iostream>
using namespace std;
#include <stack>
#include <vector>


void reverseWords(string s, stack<string>& st){

    string temp;

    for(char ch : s) {

        if(ch != ' ') {
            temp.push_back(ch);
        }

       else{ //the current character is a ' '(space)
            if(!temp.empty()){
                st.push(temp);
                temp.clear();
            }
        }
    }

    // Add the last word if there's one left
    if (!temp.empty()) {
        st.push(temp);
    }

}


int main() {

    string s = "the sky is blue";  //output should be -> "blue is sky the"
    stack <string> st;

    reverseWords(s, st);

    while(!st.empty()){
        cout<< st.top() <<" ";
        st.pop();
    }

    return 0;
}