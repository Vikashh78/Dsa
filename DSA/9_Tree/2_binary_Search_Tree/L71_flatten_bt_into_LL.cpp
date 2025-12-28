#include <iostream>
using namespace std;
#include <vector>

class Solution {
private:
    /*void treeToLL(vector<TreeNode*>& preorderVal) {

        if(preorderVal.size() == 0) return;

        for(int i=0; i<preorderVal.size()-1; i++) {
            
            preorderVal[i]->left = nullptr;

            preorderVal[i]->right = preorderVal[i+1];
        }

        // for last node
        preorderVal.back()->left = nullptr;
        preorderVal.back()->right = nullptr;
    }


    void preorder(TreeNode* root, vector<TreeNode*>& preorderVal) {

        if(root == nullptr) return;

        preorderVal.push_back(root);

        preorder(root->left, preorderVal);
        preorder(root->right, preorderVal);
    }


public:
    void flatten(TreeNode* root) {
        // vector of type TreeNode
        vector<TreeNode*> preorderVal;
        preorder(root, preorderVal);

        treeToLL(preorderVal);
    }*/
};


int main() {

    return 0;
}