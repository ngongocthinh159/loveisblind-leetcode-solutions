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
    unordered_map<TreeNode*,int> in;
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        if (root == NULL) 0;
        dfs1(root);
        dfs2(root);
        return res;
    }
    void dfs1(TreeNode* root) {
        if (root->left == NULL && root->right == NULL) {
            in[root] = root->val;
            return;
        }
        int res = 0;
        if (root->left) {
            dfs1(root->left);
            res = max(res, in[root->left]);
        }
        if (root->right) {
            dfs1(root->right);
            res = max(res, in[root->right]);
        }
        res += root->val;
        in[root] = res;
    }
    void dfs2(TreeNode* root) {
        if (root==NULL) return;
        res = max(res, root->val + (root->right?max(in[root->right], 0) : 0) 
                                 + (root->left?max(in[root->left], 0) : 0) );
        dfs2(root->left);
        dfs2(root->right);
    }
};