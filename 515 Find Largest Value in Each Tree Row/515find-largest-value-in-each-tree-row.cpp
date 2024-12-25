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
    vector<int> largestValues(TreeNode* root) {
        deque<TreeNode*> q;
        if (root) q.push_front(root);
        vector<int> ans;
        while (q.size()) {
            int sz = q.size();
            int mx = INT_MIN;
            while (sz--) {
                auto u = q.back();
                q.pop_back();
                mx = max(mx, u->val);
                if (u->left) q.push_front(u->left);
                if (u->right) q.push_front(u->right);
            }
           ans.push_back(mx);
        }
        return ans;
    }
};