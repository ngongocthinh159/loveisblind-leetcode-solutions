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
    vector<TreeNode*> leafs;
    int d;
    unordered_map<TreeNode*, vector<TreeNode*>> g;
    int ans = 0;
    int countPairs(TreeNode* root, int distance) {
        dfs(root);
        int n = leafs.size();
        TreeNode* dummy = new TreeNode(-1);
        for (int i = 0; i < n; i++) {
            dfs2(leafs[i], leafs[i], dummy, 0, distance);
        }
        return ans/2;
    }
    void dfs2(TreeNode* org, TreeNode* u, TreeNode* par, int edges, int max_edges) {
        if (edges > max_edges) return;

        if (u->left == NULL && u->right == NULL && u != org) {
            ans++;
        }        
        for (auto v : g[u]) {
            if (v != par) {
                dfs2(org, v, u, edges + 1, max_edges);
            }
        }
    }
    void dfs(TreeNode* root) {
        if (root->left == NULL && root->right == NULL) {
            leafs.push_back(root);
        }
        if (root->left) {
            g[root].push_back(root->left);
            g[root->left].push_back(root);            
            dfs(root->left);
        }
        if (root->right) {
            g[root].push_back(root->right);
            g[root->right].push_back(root);
            dfs(root->right);
        }
    }
};