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
    vector<vector<unordered_map<TreeNode*, int>>> dp;
    void dfs(TreeNode* u) {
        if (!u) return;
        TreeNode* l = u->left;
        TreeNode* r = u->right;
        dfs(l);
        dfs(r);
        dp[0][0][u] = 1e9;
        if (l)
            dp[0][0][u] = dp[0][1][l] + min(dp[0][0][r], dp[0][1][r]);
        if (r)
            dp[0][0][u] = min(dp[0][0][u], min(dp[0][0][l], dp[0][1][l]) + dp[0][1][r]);
        dp[0][1][u] = 1 + min(dp[1][0][r], dp[1][1][r]) + min(dp[1][0][l], dp[1][1][l]);
        dp[1][0][u] = min(dp[0][0][l], dp[0][1][l]) + min(dp[0][0][r], dp[0][1][r]);
        dp[1][1][u] = 1 + min(dp[1][0][r], dp[1][1][r]) + min(dp[1][0][l], dp[1][1][l]);
        // cout << dp[0][1][u] << "\n";
        // cout << dp[1][0][u] << "\n";
    }
    int minCameraCover(TreeNode* root) {
        dp = vector<vector<unordered_map<TreeNode*,int>>>(2, vector<unordered_map<TreeNode*,int>>(2, 
            unordered_map<TreeNode*,int>()));
        dfs(root);
        return min(dp[0][1][root], dp[0][0][root]);
    }
};