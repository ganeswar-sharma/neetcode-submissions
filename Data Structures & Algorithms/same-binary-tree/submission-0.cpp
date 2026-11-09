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

    bool solve(TreeNode* node1, TreeNode* node2){
        if(node1== NULL && node2==NULL){
            return true;
        }
        if((node1== NULL && node2!=NULL) || (node1!= NULL && node2==NULL)){
            return false;
        }
        if(node1->val != node2->val){
            return false;
        }
        
        return solve(node1->left, node2->left) && solve(node1->right, node2->right);

    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p, q);
    }
};
