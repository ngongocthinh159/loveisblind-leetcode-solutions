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
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        int ans = INT_MAX;
        for (int i = 1; i < v.size(); i++) {
            ans = min(ans,v[i]-v[i-1]);
        }
        return ans;
    }
    void dfs(TreeNode* root) {
        if (root == NULL) return;
        dfs(root->left);
        v.push_back(root->val);
        dfs(root->right);
    }
};