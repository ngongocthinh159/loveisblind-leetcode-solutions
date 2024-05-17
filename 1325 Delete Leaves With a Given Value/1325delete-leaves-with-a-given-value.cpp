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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        dfs(root, NULL, target);
        if (root->left == NULL && root->right == NULL && root->val == target) return NULL;
        return root;
    }
    void dfs(TreeNode* cur, TreeNode* par, int target) {
        if (cur == NULL) return;
        dfs(cur->left, cur, target);
        dfs(cur->right, cur, target);
        if (cur->left == NULL && cur->right == NULL) {
            if (cur->val == target) {
                if (par != NULL) {
                    if (par->left == cur) par->left = NULL;
                    if (par->right == cur) par->right = NULL;
                }
            }
        }
    }
};