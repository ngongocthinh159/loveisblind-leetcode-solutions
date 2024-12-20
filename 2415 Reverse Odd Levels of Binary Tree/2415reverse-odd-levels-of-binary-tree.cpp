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
 #define MAX 100005
 TreeNode* nodes[MAX];
 int cnt = -1;
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, 1);
        return root;
    }
    void dfs(TreeNode* left, TreeNode* right, int level) {
        if (!left || !right) return;
        if (level&1) swap(left->val, right->val);
        dfs(left->left, right->right, level + 1);
        dfs(left->right, right->left, level + 1);
    }
};