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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        int level = 1;
        deque<TreeNode*> q;
        q.push_front(root);
        vector<long long> sums;
        while (q.size()) {
            long long sum = 0;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto node = q.back(); q.pop_back();
                sum += node->val;
                if (node->left) q.push_front(node->left);
                if (node->right) q.push_front(node->right);
            }

            sums.push_back(sum);

            level++;
        }
        if (level - 1 < k) return -1;
        sort(sums.begin(), sums.end());
        return sums[sums.size() - k];
    }
};