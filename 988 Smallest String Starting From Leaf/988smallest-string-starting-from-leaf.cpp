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
    string res = "";
    string smallestFromLeaf(TreeNode* root) {
        res += 26 + 'a';
        string cur = "";
        dfs(root, cur);
        return res;
    }
    void dfs(TreeNode* root, string &cur) {
        if (root == NULL) {
            cur += '#';
            return;
        }
        cur += root->val + 'a';
        if (root->left == NULL  && root->right == NULL) {
            string tmp = cur;
            reverse(tmp.begin(), tmp.end());
            res = min(res, tmp);
        }
        dfs(root->left, cur);
        cur.pop_back();
        dfs(root->right, cur);
        cur.pop_back();
    }
};