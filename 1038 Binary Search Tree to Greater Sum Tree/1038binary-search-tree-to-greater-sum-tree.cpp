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
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root, 0);
        return root;
    }
    int dfs(TreeNode* root, int cur) {
        if (root == NULL) return 0;

        int r = dfs(root->right, cur);
        int l = dfs(root->left, cur + root->val + r);
        int orgVal = root->val;
        root->val = r + cur + orgVal;
        return l + r + orgVal;
    }
};