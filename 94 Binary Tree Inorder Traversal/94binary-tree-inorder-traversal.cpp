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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        pushAllLeft(st, root);
        while (st.size()) {
           TreeNode* cur = st.top(); st.pop();
           res.push_back(cur->val);
           pushAllLeft(st, cur->right);
        }
        return res;
    }

    void pushAllLeft(stack<TreeNode*>& st, TreeNode* cur) {
        while (cur != NULL) {
            st.push(cur);
            cur = cur->left;
        }
    }
};