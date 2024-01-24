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
    int res = 0;
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root, 0);
        return res;
    }
    void dfs(TreeNode* root, int path) {
        if (root == NULL) return;

        path = path ^ (1 << root->val);
        if (root->left == NULL && root->right == NULL && (path & (path - 1)) == 0) {
            res++;
        }
        dfs(root->left, path);
        dfs(root->right, path);
    }
};