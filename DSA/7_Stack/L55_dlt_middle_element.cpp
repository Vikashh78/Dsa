#include <iostream>
using namespace std;
#include <stack>

void removeMiddle(stack<int> &st, int size, int count) {
    // base case
    if(count == size/2) {
        st.pop();
        return;
    }

    // storing the top element until the middle element is reached
    int temp = st.top();
    st.pop();

    // recursive call
    removeMiddle(st, size, count+1);
    
    // again pushing back the stored element back to stack
    st.push(temp);

}

int main() {

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    int size = st.size();
    cout<<"size of stack is : "<<size<<"\n";
    
    // Create a copy of the stack to print its elements
    stack<int> tempSt = st;

    cout<<"\nbefore removing the middle element"<<endl;
    while(! tempSt.empty()) {
        cout<<tempSt.top()<<endl;
        tempSt.pop();
    }
    

    removeMiddle(st, size, 0);

    tempSt = st;  // create a copy of stack to print after removal od middle

    cout<<"\nAfter removing the middle element"<<endl;
    while(! tempSt.empty()) {
        cout<<tempSt.top()<<endl;
        tempSt.pop();
    }


    return 0;
}