// Given a binary tree, determine if it is height-balanced. A binary tree is considered height-balanced if the absolute difference
// in heights of the left and right subtrees is at most 1 for every node in the tree.

#include <iostream>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root) {

    int data;
    cin >> data;
    root = new node(data);    

    // base case
    if(data == -1) {
        return NULL;
    }

    root->left = buildTree(root->left);

    root->right = buildTree(root->right);

    return root;
}



// approcah 1. TC - O(n^2)
int height(node* &root){
    //base case
    if(root == NULL) {
        return 0;
    }
    
    int left = height(root ->left);
    int right = height(root->right);
    
    int ans = max(left, right) + 1;
    
    return ans;   
}

bool isBalanced(node* &root) {
    // base case
    if(root == nullptr) {
        return true;
    }

    bool left = isBalanced(root->left);

    bool right = isBalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if(left && right && diff) {
        return true;
    }
    else {
        return false;
    }
}



// Approach 2. returning result in pair - TC - O(n)
pair<bool, int> isBalancedFast(node* root) {
    // base case
    if(root == NULL) {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<int,int> left = isBalancedFast(root->left);
    pair<int,int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs (left.second - right.second ) <=1;

    pair<bool,int> ans;

    ans.second = max(left.second, right.second) + 1;

    if(leftAns && rightAns && diff) {
        ans.first = true;
    }
    else {
        ans.first = false;
    }

    return ans;
}


int main() {

    node* root = nullptr;   //1 2 4 -1 -1 5 -1 -1 3 -1 -1

    root = buildTree(root);

    // Approach 1
    if(isBalanced(root)) 
    cout<<"balanced"<<endl;
    else
    cout<<"not balanced"<<endl;


    // Approach 2
    // if(isBalancedFast(root).first) 
    // cout<<"balanced"<<endl;
    // else
    // cout<<"not balanced"<<endl;

    return 0;
}