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
    unordered_map<int,int> maxHeight;
    int mx = 0;
    void dfs1(TreeNode* node, int height) {
        if (node == NULL) return;
        maxHeight[node->val] = mx;
        mx = max(mx, height);
        dfs1(node->left, height+1);
        dfs1(node->right, height+1);
    }
    void dfs2(TreeNode* node, int height) {
        if (node == NULL) return;
        maxHeight[node->val] = max(maxHeight[node->val], mx);
        mx = max(mx, height);
        dfs2(node->right, height+1);
        dfs2(node->left, height+1);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        dfs1(root, 0);
        mx=0;
        dfs2(root, 0);
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            ans[i] = maxHeight[queries[i]];
        }
        return ans;
    }
};