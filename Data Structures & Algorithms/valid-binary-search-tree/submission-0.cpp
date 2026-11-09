/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    void solve(TreeNode* node, vector<int> &ans){
        if(node==NULL){
            return;
        }
        solve(node->left, ans);
        ans.push_back(node->val);
        solve(node->right, ans);
        return;
    }

    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        vector<int> ans;
        solve(root, ans);
        for(int i =1;i<ans.size();i++){
            if(ans[i] > ans[i-1]){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
