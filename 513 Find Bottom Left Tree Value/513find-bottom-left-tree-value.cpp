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
    int ans;
    int mx = INT_MIN;
    int findBottomLeftValue(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
    void dfs(TreeNode* root, int h) {
        if (root==NULL) return;
        dfs(root->left,h+1);
        if (mx < h) {mx=h; ans = root->val;}
        dfs(root->right,h+1);
    }
};