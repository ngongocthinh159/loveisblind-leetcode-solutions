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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> M;
        unordered_map<int, int> inDeg;
        int u, v; bool left;
        for (auto &tmp : descriptions) {
            u = tmp[0];
            v = tmp[1];
            left = tmp[2] == 1 ? true : false;

            TreeNode* p;
            TreeNode* c;
            if (!M.count(u)) {
                p = new TreeNode(u);
                M[u] = p;
            } else p = M[u];
            if (!M.count(v)) {
                c = new TreeNode(v);
                M[v] = c;
            } else c = M[v];

            if (left) {
                p->left = c;
            } else {
                p->right = c;
            }

            inDeg[c->val]++;
            inDeg[p->val];
        }
        int root_val;
        for (auto &[val, deg] : inDeg) {
            if (deg == 0) {root_val = val; break;}
        }
        return M[root_val];
    }
};