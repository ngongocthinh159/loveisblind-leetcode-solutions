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
    int res = 1;
    int longestZigZag(TreeNode* root) {
        dfs(root);
        return res - 1;
    }
    pair<int,int> dfs(TreeNode* root) {
        if (root == NULL) return {0, 0};
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        int val1 = 1 + l.second;
        int val2 = 1 + r.first;
        res = max(res, max(val1, val2));
        return {val1, val2};
    }
};