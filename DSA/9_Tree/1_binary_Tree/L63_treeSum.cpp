// A SumTree is a Binary Tree where the value of a node is equal to the sum of the nodes present in its left subtree and right subtree.
// An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0. A leaf node is also considered a Sum Tree.


#include <iostream>
using namespace std;

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


// function to calculate sum 
pair<bool,int> isSumTreeFast(Node* root) {
        
    //base case
    if(root == NULL) {
        pair<bool,int> p = make_pair(true, 0);
        return p;
    }
    
    if(root->left == NULL && root->right == NULL ) {
        pair<bool,int> p = make_pair(true, root->data);
        return p;
    }
    
    pair<bool,int> leftAns = isSumTreeFast(root->left);
    pair<bool,int> rightAns = isSumTreeFast(root->right);
    
    bool isLeftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;
    
    bool condn = root->data == leftAns.second + rightAns.second;
    
    pair<bool, int> ans;
    
    if(isLeftSumTree && isRightSumTree && condn) {
        ans.first = true;
        ans.second = root->data + leftAns.second + rightAns.second ;
    }

    else {
        ans.first = false;
    }

    return ans;
}


int main() {

    Node* root = nullptr;

    root = buildTree(root);

    pair<bool,int> result = isSumTreeFast(root);

    return 0;
}