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
    int res = 0;
    vector<long long> pre;
    unordered_map<long long,int> mp;
    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return 0;
        pre.push_back(root->val);
        mp[pre.back() - root->val]++;
        dfs(root, targetSum);
        mp[pre.back() - root->val]--;
        pre.pop_back();
        return res;
    }   

    void dfs(TreeNode* root, int targetSum) {
        if (root == NULL) return;
        
        if (mp.count(pre.back() - targetSum)) {
            res += mp[pre.back() - targetSum];
        }
        
        if (root->left) {
            pre.push_back(0LL + root->left->val + pre.back());
            mp[pre.back() - root->left->val]++;
            dfs(root->left, targetSum);
            mp[pre.back() - root->left->val]--;
            pre.pop_back();
        }
        
        if (root->right) {
            pre.push_back(0LL + root->right->val + pre.back());
            mp[pre.back() - root->right->val]++;
            dfs(root->right, targetSum);
            mp[pre.back() - root->right->val]--;
            pre.pop_back();
        }
    }
};