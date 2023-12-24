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
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return res;
        path.push_back(root->val);
        dfs(root, targetSum, root->val);
        return res;
    }
    void dfs(TreeNode* root, int targetSum, int curSum) {
        if (root->left == NULL && root->right == NULL) {
            if (curSum == targetSum) {
                vector<int> tmp(path); res.push_back(tmp);
            }
            return;
        }
        if (root->left) {
            path.push_back(root->left->val);
            dfs(root->left, targetSum, curSum + root->left->val);
            path.pop_back();
        }
        if (root->right) {
            path.push_back(root->right->val);
            dfs(root->right, targetSum, curSum + root->right->val);
            path.pop_back();
        }
    }
};