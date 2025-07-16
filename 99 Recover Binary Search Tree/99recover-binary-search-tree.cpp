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
    pair<int,int> p1, p2;
    void dfs(TreeNode* root, int &idx, int &idx1, int &idx2, int &prev) {
        if (!root) return;
        dfs(root->left, idx, idx1, idx2, prev);
        if (root->val < prev) {
            if (idx1 == -1) {
                idx1 = idx;
                p1 = {prev, root->val};
            }
            else {
                idx2 = idx;
                p2 = {prev, root->val};
            }
        }
        prev = root->val;
        idx++;
        dfs(root->right, idx, idx1, idx2, prev);
    }
    void dfs2(TreeNode* root, int &idx, int idx1, int idx2, int val1, int val2) {
        if (!root) return;
        dfs2(root->left, idx, idx1, idx2, val1, val2);
        if (idx == idx1) root->val = val2;
        if (idx == idx2) root->val = val1;
        idx++;
        dfs2(root->right, idx, idx1, idx2, val1, val2);
    }
    void recoverTree(TreeNode* root) {
        int idx = 0, idx1 = -1, idx2 = -1, prev = INT_MIN;
        dfs(root, idx, idx1, idx2, prev);
        idx = 0;
        if (idx2 == -1) {
            dfs2(root, idx, idx1 - 1, idx1, p1.first, p1.second);
        } else {
            dfs2(root, idx, idx1 - 1, idx2, p1.first, p2.second);
        }
    }
};