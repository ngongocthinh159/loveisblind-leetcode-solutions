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
    int depth = -1;
    bool check(int x, TreeNode* root) {
        string s = "";
        while (x != 1) {
            if (x&1) s += 'R';
            else s += 'L';
            x /= 2;
        }
        reverse(s.begin(), s.end());
        int i = 0;
        TreeNode* p = root;
        while(p != NULL && i < s.size()) {
            if (s[i] == 'L') p = p->left;
            else p = p->right;
            i++;
        }
        if (p != NULL && i == s.size()) return true;
        else return false;
    }
    void dfs(TreeNode* root, int curDepth) {
        if (root==NULL) return;
        depth = max(depth, curDepth);
        dfs(root->left, curDepth + 1);
    }
    int countNodes(TreeNode* root) {
        dfs(root, 0);
        if (depth == -1) return 0;
        int l = pow(2,depth), r = pow(2, depth+1) - 1;
        int ans = 0;
        while (l <= r) {
            int m = l + (r - l)/2;
            
            if (check(m, root)) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }
};