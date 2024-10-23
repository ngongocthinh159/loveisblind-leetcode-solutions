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
    TreeNode* replaceValueInTree(TreeNode* root) {
        deque<TreeNode*> q;
        q.push_front(root);
        unordered_map<TreeNode*, TreeNode*> nodeToPar;
        unordered_map<TreeNode*,int> childrenSum;
        while (q.size()) {
            int size = q.size();
            vector<TreeNode*> v;
            long long sum = 0;
            for (int i = 0; i < size; i++) {
                auto node = q.back(); q.pop_back();
                if (node->left) {q.push_front(node->left); nodeToPar[node->left] = node; childrenSum[node] += node->left->val;}
                if (node->right) {q.push_front(node->right); nodeToPar[node->right] = node; childrenSum[node] += node->right->val;}
                v.push_back(node);
                sum += node->val;
            }
            for (auto node : v) {
                int sumInSameSubtree = node == root ? node-> val : childrenSum[nodeToPar[node]];
                node->val = (sum - sumInSameSubtree);
            }
        }
        return root;
    }
};