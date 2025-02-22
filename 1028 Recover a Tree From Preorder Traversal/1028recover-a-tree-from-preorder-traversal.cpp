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
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        vector<pair<TreeNode*,int>> st;
        st.push_back({new TreeNode(-1), -1});
        for (int i = 0; i < n;) {
            int d = 0, v = 0;
            while (i < n && traversal[i] == '-') d++, i++;
            while (i < n && traversal[i] != '-') v = 10*v + traversal[i++] - '0';
            TreeNode* node = new TreeNode(v);
            while (st.back().second >= d) st.pop_back();
            if (!(st.back().first->left)) 
                st.back().first->left = node;
            else 
                st.back().first->right = node;
            st.push_back({node, d});
        }
        return st[0].first->left;
    }
};