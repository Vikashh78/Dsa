#include <iostream>
using namespace std;
#include <vector>

class Solution {
    private:
        /*bool check(vector<int> ans, int target) {
            // by two pointer approach
            int n = ans.size();
            int i=0, j=n-1;
            
            while(i < j) {
    
                int sum = ans[i] + ans[j];
                if(sum == target) {
                    return true;
                }
                else if(sum > target) {
                    j--;
                }
                else {
                    i++;
                }
            }
            return false;
        }
    
        void inOrder(TreeNode* root, vector<int>& ans) {
            //base case
            if(root == nullptr) return;
    
            inOrder(root->left, ans);
    
            ans.push_back(root->val);
    
            inOrder(root->right, ans);
        }
    
    public:
        bool findTarget(TreeNode* root, int k) {
            
            vector<int> ans;
    
            inOrder(root, ans);
    
            bool result = check(ans, k);
    
            return result;
    
        }*/
    };

int main() {

    return 0;
}