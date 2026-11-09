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

    void solve(TreeNode* node, vector<int> &path, vector<int> &ans){
        if(node==NULL){
            return;
        }

        int nodeVal = node->val;
        bool isGoodNode = true;
        for(int i =0;i<path.size();i++){
            if(nodeVal < path[i]){
                isGoodNode = false;
            }
        }
        if(isGoodNode){
            ans.push_back(nodeVal);
        }
        path.push_back(nodeVal);
        solve(node->left, path, ans);
        solve(node->right, path, ans);
        path.pop_back();

        return;
    }

    int goodNodes(TreeNode* root) {
        vector<int> path;
        vector<int> ans;
        solve(root, path, ans);
        return ans.size();
    }
};
