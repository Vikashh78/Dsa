#include <iostream>
using namespace std;
#include <stack>

// recursive function to insert at bottom
void insertAtBottom(stack<int> &stk, int element) {
    // base case
    if(stk.empty()) {
        stk.push(element);
        return; //each step ke liye return hoga
    }

    int temporary = stk.top();
    stk.pop();

    insertAtBottom(stk, element);

    stk.push(temporary); // return hote waqt ye line execute hote jati hai
}


// recursive function to reverse the stack
void reverse(stack<int> &stk) {

    // base case
    if(stk.empty()) {
        return;  //each step ke liye return hoga
    }

    int temp = stk.top();
    stk.pop();

    // recursive call
    reverse(stk);


    insertAtBottom(stk, temp); //jab stack empty ho gya then return hote waqt insertAtBottom() funtion call hote jaa rha hai ek ek baar

}


int main() {

    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);

    stack<int> dummy = stk;
    cout<<"stack before reversed\n";
    while(! dummy.empty()) {
        cout<<dummy.top()<<endl;
        dummy.pop();
    }
    cout<<endl;

    // function called
    reverse(stk);

    dummy = stk;
    cout<<"stack after reversed\n";
    while(! dummy.empty()) {
        cout<<dummy.top()<<endl;
        dummy.pop();
    }
    cout<<endl;

    return 0;
}