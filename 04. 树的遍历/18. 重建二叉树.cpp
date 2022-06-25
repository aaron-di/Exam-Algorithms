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
    unordered_map<int, int> pos;
    vector<int> preorder, inorder;
    
    TreeNode* build(int a, int b, int x, int y) {
        if (a > b) return NULL;
        auto root = new TreeNode(preorder[a]);
        int k = pos[root->val];
        root->left = build(a + 1, a + 1 + k - 1 - x, x, k - 1);
        root->right = build(a + 1 + k - 1 - x + 1, b, k + 1, y);
        return root;
    }
 
    TreeNode* buildTree(vector<int>& _preorder, vector<int>& _inorder) {
        preorder = _preorder, inorder = _inorder;
        int n = inorder.size();
        for (int i = 0; i < n; i++) pos[inorder[i]] = i;
        return build(0, n - 1, 0, n - 1);
    }
};
 */