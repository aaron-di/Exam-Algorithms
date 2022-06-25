/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* 
class Solution {
public:
    int dfs(TreeNode* root, int depth) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val * depth;
        else return dfs(root->left, depth + 1) + dfs(root->right, depth + 1);
    }

    int pathSum(TreeNode* root) {
        return dfs(root, 0);
    }
};
 */
