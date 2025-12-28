#include <iostream>
using namespace std;
#include <stack>

void sortedInsert(stack<int>& stk, int num) {
    //base case
    if(stk.empty() || stk.top() < num) {
        stk.push(num);
        return;
    }

    int temp = stk.top();
    stk.pop();
    //recursive call
    sortedInsert(stk, num);

    stk.push(temp);
}


void sortStack(stack<int>& stk) {

    if(stk.empty()) {
        return;
    }

    int temp = stk.top(); //storing top elements and popping them out
    stk.pop();

    //recursive call
    sortStack(stk);

    sortedInsert(stk, temp);
}


int main() {

    stack<int> stk;
    stk.push(6);
    stk.push(-2);
    stk.push(3);
    stk.push(4);
    stk.push(0);

    stack<int> dummy = stk;
    cout<<"stack before sorting\n";
    while(! dummy.empty()) {
        cout<<dummy.top()<<endl;
        dummy.pop();
    }
    cout<<endl;

    // function called
    sortStack(stk);

    dummy = stk;
    cout<<"stack after sorting\n";
    while(! dummy.empty()) {
        cout<<dummy.top()<<endl;
        dummy.pop();
    }
    cout<<endl;

    return 0;
}