#include <iostream>
using namespace std;
#include <vector>

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d) {
        this-> data = d;
        this-> left = NULL;
        this-> right = NULL;
    }
};
Node* buildTree(Node* root) {

    int data;
    cin >> data;
    root = new Node(data);    

    // base case
    if(data == -1) {
        return NULL;
    }

    root->left = buildTree(root->left);

    root->right = buildTree(root->right);

    return root;
}



// function for left view of tree
void leftView(Node* root, vector<int>& ans, int level) {

    // base case
    if(root == nullptr) {
        return;
    }

    // we entered into a new level then
    if(level == ans.size()) {
        ans.push_back(root->data);
    }

    leftView(root->left, ans, level+1);

    leftView(root->right, ans, level+1);
}



// function for right view of tree
void rightView(Node*& root, vector<int>& ans, int level) {

    //base case
    if(root == nullptr) {
        return;
    }

    if(level == ans.size()) {
        ans.push_back(root->data);
    }

    //recursive call
    rightView(root->right, ans, level+1); //only change form left view

    rightView(root->left, ans, level+1);
}



int main() {

    Node* root = nullptr;
    root = buildTree(root);

    vector<int> leftAns;
    vector<int> rightAns;
    int level = 0;

    cout<<"printing left view : ";
    leftView(root, leftAns, level);     // function call
    for(int i=0; i<leftAns.size(); i++) {
        cout<<leftAns[i] <<" ";
    }cout<<endl;


    // for right part
    cout<<"printing right view : ";
    rightView(root, rightAns, level);     // function call
    for(int i=0; i<rightAns.size(); i++) {
        cout<<rightAns[i] <<" ";
    }cout<<endl;

    
    return 0;
}