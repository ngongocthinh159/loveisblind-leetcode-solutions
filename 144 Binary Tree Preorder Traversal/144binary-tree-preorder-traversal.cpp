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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* cur = root;
        stack<TreeNode*> st;
        
        while (cur != NULL || st.size()) {
            while (cur != NULL) {
                res.push_back(cur->val);
                st.push(cur);
                cur = cur->left;
            }
            cur = st.top(); st.pop();
            cur = cur->right;
        }
        
        return res;
    }
};