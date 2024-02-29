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
    bool isEvenOddTree(TreeNode* root) {
        deque<TreeNode*> q;
        q.push_front(root);
        bool even = true;
        while (q.size()) {
            int size = q.size();
            vector<int> v;
            for (int i = 0; i < size; i++) {
                auto _ = q.back(); q.pop_back();
                v.push_back(_->val);
                if (_->left!=NULL) q.push_front(_->left); 
                if (_->right!=NULL) q.push_front(_->right); 
            }
            if (even) {
                int prev = INT_MIN;
                for (auto num : v) {
                    if (num%2==0) {return false;}
                    if (num <= prev) {return false;}
                    prev = num;
                }
            } else {
                int prev = INT_MAX;
                for (auto num : v) {
                    if (num%2!=0) {return false;}
                    if (num >= prev){return false;}
                    prev = num;
                }
            }
            even=!even;
        }
        return true;
    }
};