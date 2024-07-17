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
    vector<TreeNode*> res;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (root == NULL) return {};
        unordered_set<int> S(to_delete.begin(), to_delete.end());
        TreeNode* dum = new TreeNode(-1);
        S.insert(-1);
        dfs(root, dum, true, S);
        return res; 
    }
    void dfs(TreeNode* root, TreeNode* par, bool left, unordered_set<int> &S) {
        if (root == NULL) return;

        if (S.count(par->val) && !S.count(root->val)) res.push_back(root);
        if (S.count(root->val)) {
            if (left) par->left = NULL;
            else par->right = NULL;
        }

        dfs(root->left, root, true, S);
        dfs(root->right, root, false, S);
    }
};