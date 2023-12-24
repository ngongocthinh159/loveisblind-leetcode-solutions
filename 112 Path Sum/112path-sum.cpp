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
    bool ans = false;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        dfs(root, targetSum, root->val);
        return ans;
    }

    void dfs(TreeNode* root, int targetSum, int curSum) {
        if (root->left == NULL && root->right == NULL) {
            if (curSum == targetSum) ans = true;
            return;
        }
        if (root->left) dfs(root->left, targetSum, curSum + root->left->val);
        if (root->right) dfs(root->right, targetSum, curSum + root->right->val);
    }
};