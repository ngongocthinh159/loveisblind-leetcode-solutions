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
    vector<int> v;
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        return dfs2(0, v.size() - 1);
    }
    TreeNode* dfs2(int l, int r) {
        if (l > r) return NULL;

        int m = l + (r - l)/2;
        TreeNode* root = new TreeNode(v[m]);
        TreeNode* left = dfs2(l, m - 1);
        TreeNode* right = dfs2(m + 1, r);
        root->left = left;
        root->right = right;
        return root;
    }
    void dfs(TreeNode* root) {
        if (root == NULL) return;
        dfs(root->left);
        v.push_back(root->val);
        dfs(root->right);
    }
};