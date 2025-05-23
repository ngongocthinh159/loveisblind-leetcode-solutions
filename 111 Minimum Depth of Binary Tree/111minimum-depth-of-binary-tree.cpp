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
    int minDepth(TreeNode* root) {
        if (!root) { 
            return 0;
        }   
        deque<TreeNode*> q;
        q.push_front(root);
        int level = 1;
        while (q.size()) {
            int sz = q.size();
            while (sz--) {
                auto u = q.back();
                q.pop_back();
                if (!u->left && !u->right) {
                    return level;
                }
                if (u->left) {
                    
                    q.push_front(u->left);
                }
                if (u->right) {
                    q.push_front(u->right);
                }
            }
            level++;
        }
        return -1;
    }
};