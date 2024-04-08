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
    vector<double> averageOfLevels(TreeNode* root) {
        if (root == NULL) return {};
        vector<double> res;
        deque<TreeNode*> q;
        q.push_front(root);
        while (q.size()) {
            int size = q.size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                auto cur = q.back(); q.pop_back();
                sum += cur->val;
                if (cur->left) q.push_front(cur->left);
                if (cur->right) q.push_front(cur->right);
            }
            sum /= size;
            res.push_back(sum);
        }
        return res;
    }
};