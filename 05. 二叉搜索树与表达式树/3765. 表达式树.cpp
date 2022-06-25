/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     string val；
 *     TreeNode *left;
 *     TreeNode *right;
 * };
 */
/* 
class Solution {
public:
    string dfs(TreeNode* root) {
        if (!root) return "";
        if (!root->left && !root->right) return root->val;
        else return '(' + dfs(root->left) + root->val + dfs(root->right) + ')';
    }

    string expressionTree(TreeNode* root) {
        return dfs(root->left) + root->val + dfs(root->right);
    }
};
 */