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
    bool isSymmetric(TreeNode* root) {
        if (root->left == NULL && root->right == NULL) return true;
        if (root->left == NULL || root->right == NULL) return false;
        deque<TreeNode*> dq;
        dq.push_front(root->left);
        dq.push_front(root->right);
        while (dq.size()) {
            int size = dq.size();
            if (size&1) return false;
            for (int i = 0; i < size; i+=2) {
                auto left = dq.back(); dq.pop_back();
                auto right = dq.back(); dq.pop_back();
                if (left == NULL && right == NULL) continue;
                if (left == NULL || right == NULL) return false;
                if (left->val != right->val) return false;
                dq.push_front(left->left);
                dq.push_front(right->right);
                dq.push_front(left->right);
                dq.push_front(right->left);
            }
        }
        return true;
    }
};