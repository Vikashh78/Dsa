#include <iostream>
using namespace std;
#include<vector>

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



//1. function for left part of tree excluding root nodes
void leftTraverse(Node* &root, vector<int>& ans) {
    // base case
    if((root == nullptr) || (root->left == nullptr && root->right == NULL)) {
        return;
    }

    //pushing root data into the ans while going to downwards through the tree
    ans.push_back(root->data);

    if(root->left) {
        leftTraverse(root->left, ans);
    }
    else { //left node is not presesnt
        leftTraverse(root->right, ans);
    }
}


//2. for root data
void rootTraverse(Node* &root, vector<int>& ans) {
    // base case
    if(root == nullptr) {
        return;
    }
    if(root->left == nullptr && root->right == nullptr) {
        ans.push_back(root->data);
        return;
    }

    rootTraverse(root->left, ans);
    rootTraverse(root->right, ans);
}


//3. for right part
void rightTraverse(Node* &root, vector<int>& ans) {
    // base case
    if((root == nullptr) || (root->left == nullptr && root->right == nullptr))
    return;

    if(root->right) {
        rightTraverse(root->right, ans);
    }
    else{
        rightTraverse(root->left, ans);
    }
    // return hote time value push karlo vector me
    ans.push_back(root->data);
}



int main() {

    Node* root = NULL;
    root = buildTree(root);

    vector<int> ans;
    ans.push_back(root->data); // very first push root value in ans vector

    // call for left part
    leftTraverse(root->left, ans);

    // call for root
    rootTraverse(root->left, ans);
    rootTraverse(root->right, ans);

    // call for right part
    rightTraverse(root->right, ans);

    cout<<"Bundary traversal of tree is : ";
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    } cout<<endl; 

    return 0;
}