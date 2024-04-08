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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) return {};
        vector<vector<int>> res;
        deque<TreeNode*> q;
        q.push_back(root);
        bool even = true;
        while (q.size()) {
            int size = q.size();
            vector<int> v;
            for (int i = 0; i < size; i++) {
                auto cur = q.back(); q.pop_back();
                v.push_back(cur->val);
                if (cur->left) q.push_front(cur->left);
                if (cur->right) q.push_front(cur->right);
            }
            if (!even) reverse(v.begin(), v.end());
            res.push_back(v);
            even = !even;
        }
        return res;
    }
};