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
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, INT_MIN, INT_MAX);
    }
    int dfs(TreeNode* root, int mx, int mn) {
        if (root==NULL) return 0;
        mx = max(mx, root->val);
        mn = min(mn, root->val);
        int cur = max(abs(root->val - mx), abs(root->val - mn));
        return max(cur, max(dfs(root->left, mx, mn), dfs(root->right, mx, mn)));
    }
};