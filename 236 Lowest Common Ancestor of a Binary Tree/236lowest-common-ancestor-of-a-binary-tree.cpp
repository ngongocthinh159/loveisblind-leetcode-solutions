/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define LOG 19
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, unordered_map<int, TreeNode*>> par;
        unordered_map<TreeNode*, int> height;
        TreeNode* dummy = new TreeNode(-1);
        for (int i = 0; i <= LOG; i++) {
            par[dummy][i] = dummy;
            par[root][i] = dummy;
        }
        height[dummy] = -1;
        height[root] = 0;
        dfs(root, par, height, dummy);
        return LCA(p, q, par, height);
    }
    void dfs(TreeNode* root,
     unordered_map<TreeNode*, unordered_map<int, TreeNode*>> &par, unordered_map<TreeNode*, int> &height,
     TreeNode* dummy) {
        if (root->left) {
            par[root->left][0] = root;
            for (int i = 1; i <= LOG; i++) {
                par[root->left][i] = par[par[root->left][i - 1]][i - 1];
            }
            height[root->left] = height[root] + 1;
            dfs(root->left, par, height, dummy);
        }
        if (root->right) {
            par[root->right][0] = root;
            for (int i = 1; i <= LOG; i++) {
                par[root->right][i] = par[par[root->right][i - 1]][i - 1];
            }
            height[root->right] = height[root] + 1;
            dfs(root->right, par, height, dummy);
        }
    }
    TreeNode* LCA(TreeNode* u, TreeNode* v, 
        unordered_map<TreeNode*, unordered_map<int, TreeNode*>> &par, unordered_map<TreeNode*, int> &height) {
        if (height[u] < height[v]) return LCA(v, u, par, height);
        // can bang do sau
        for (int i = LOG; i >= 0; i--) {
            if (height[par[u][i]] >= height[v]) {
                u = par[u][i];
            }
        }
        if (u == v) return u;

        // nhay den node xa nhat chua gap nhau
        for (int i = LOG; i >= 0; i--) {
            if (par[u][i] != par[v][i]) {
                u = par[u][i];
                v = par[v][i];
            }
        }
        return par[u][0];
    }
};