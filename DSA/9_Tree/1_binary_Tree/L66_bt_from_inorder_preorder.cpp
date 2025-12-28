/*Given two arrays representing the inorder and preorder traversals of a binary tree, construct the tree and return the root node of the constructed tree.
Note: The output is written in postorder traversal.
Examples:
Input: inorder[] = [1, 6, 8, 7], preorder[] = [1, 6, 7, 8]
Output: [8, 7, 6, 1]*/

#include <iostream>
using namespace std;
#include <map>

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


/*  Overall TC of code is : O(nlogn) + O(n) + O(1) = O(nlogn) 
    O(n) [map] + O(n) [recursion] + O(n) [tree nodes] = O(n) */

// function for mapping index to nodes : map- TC O(nlogn)
void createMapping(int in[], map<int,int>& nodeToIndex, int inorderSize){
    for(int i=0; i<inorderSize; i++) {
        nodeToIndex[in[i]] = i;
    }
}

// function for building tree : TC O(n)
Node* buildBt(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int preorderSize, int inorderSize, map<int,int>& nodeToIndex) {

    // base case
    if(index >= preorderSize || inorderStart > inorderEnd) {
        return nullptr;
    }

    int element = pre[index++];
    Node* root = new Node(element);
    int position = nodeToIndex[element];   // TC O(1)

    // catch - for [postorder/inorder] first we make root->right call then left call
    root->left = buildBt(in, pre, index, inorderStart, position-1, preorderSize, inorderSize, nodeToIndex);

    root->right = buildBt(in, pre, index, position+1, inorderEnd, preorderSize, inorderSize, nodeToIndex);
}





// function for printing result
void print(Node* &root) {
    if(root == nullptr)
    return;

    print(root->left);
    print(root->right);

    cout<<root->data<<" ";
}



int main() {

    // given inorder and preorder arrays
    int in[6] = {3,1,4,0,5,2};
    int pre[6] = {0,1,3,4,2,5};
    int index = 0;

    map<int,int> nodeToIndex;           // searching element TC reduced from O(n) to O(1) by using
    createMapping(in, nodeToIndex, 6);

    Node* ans = buildBt(in, pre, index, 0, 5, 6, 6, nodeToIndex);
    cout<<"output which is postOrder : ";
    print(ans);
    

    return 0;
}