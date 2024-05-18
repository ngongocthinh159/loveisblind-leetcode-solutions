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
    int ans = 0;
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
    int dfs(TreeNode* root) {
        if (root == NULL) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);

        int res = 1;
        int tmp = 1;
        if (root->left && root->left->val == root->val) {
            res = max(res, 1 + l);
            tmp += l;
        }
        if (root->right && root->right->val == root->val) {
            res = max(res, 1 + r);
            tmp += r;
        }
        ans = max(ans, tmp - 1);
        return res;
    }
};