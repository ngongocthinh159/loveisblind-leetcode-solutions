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
    pair<TreeNode*, int> dfs(TreeNode* root, int d) {
        if (!root) return {nullptr, d};
        auto l_ans = dfs(root->left, d + 1);
        auto r_ans = dfs(root->right, d + 1);
        if (l_ans.second > r_ans.second) return l_ans;
        if (l_ans.second < r_ans.second) return r_ans;
        return {root, l_ans.second};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root, 0).first;
    }
};