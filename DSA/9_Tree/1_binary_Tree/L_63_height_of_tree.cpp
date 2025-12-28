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


 //Function to find the height of a binary tree.
 int height(node* &root){
    //base case
    if(root == NULL) {
        return 0;
    }
    
    int left = height(root ->left);
    int right = height(root->right);
    
    //on returning from recursive call the height is calculated
    int ans = max(left, right) + 1;
    
    return ans;   
}


int main() {

    node* root = nullptr;

    root = buildTree(root);

    int treeHeight = height(root);

    cout<<"height of the tree is : "<<treeHeight <<endl;

    return 0;
}