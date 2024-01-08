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
    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root, low, high);
        return res;
    }
    void dfs(TreeNode* root, int low, int high) {
        if (root == NULL) return;
        if (low <= root->val && root->val <= high) res += root->val;
        dfs(root->left, low, high);
        dfs(root->right, low, high);
    }
};