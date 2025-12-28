#include <iostream>
using namespace std;

// Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

class Solution {
    public:
    
        class info { // sub class
            public:
            int maxi;
            int mini;
            bool isBST;
            int sum;
        };
    
        /*info solve(TreeNode* root, int &ans) {
            // base case
            if(root == nullptr) {
                return {INT_MIN, INT_MAX, true, 0};
            }
    
            info left = solve(root->left, ans);
            info right = solve(root->right, ans);
    
            info curr; // object for info class
    
            curr.maxi = max(root->val, right.maxi);
            curr.mini = min(root->val, left.mini);
    
            if(left.isBST && right.isBST && root->val > left.maxi && root->val < right.mini) {
                curr.isBST = true;
                curr.sum = (left.sum + right.sum + root->val);
                ans = max(ans, curr.sum);
    
            }
            else {
                curr.isBST = false;
                curr.sum = 0; // not a BST, don't consider its sum
            }
    
            return curr;
        }
    
        int maxSumBST(TreeNode* root) {
            
            int maxSize = 0;
            info temp = solve(root, maxSize);
    
            return maxSize;
        }*/
    };

int main() {

    return 0;
}
