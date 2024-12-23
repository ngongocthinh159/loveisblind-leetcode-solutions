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
    int minimumOperations(TreeNode* root) {
        deque<TreeNode*> q;
        q.push_front(root);
        int ans = 0;
        while (q.size()) {
            int size = q.size();
            vector<int> vals;
            for (int cnt = 0; cnt < size; cnt++) {
                auto u = q.back();
                vals.push_back(u->val);
                q.pop_back();
                if (u->left) q.push_front(u->left);
                if (u->right) q.push_front(u->right);
            }
            vector<int> sorted_vals = vals;
            sort(sorted_vals.begin(), sorted_vals.end());
            unordered_map<int,int> M;
            for (int i = 0; i < vals.size(); i++) M[sorted_vals[i]] = i;
            int swp = 0;
            for (int i = 0; i < vals.size(); i++) {
                int cur = vals[i];
                int idx = i;
                while (M[cur] != idx) {
                    swap(vals[idx], vals[M[cur]]);
                    cur = vals[idx];
                    swp++;
                }
            }
            ans += swp;
        }
        return ans;
    }
};