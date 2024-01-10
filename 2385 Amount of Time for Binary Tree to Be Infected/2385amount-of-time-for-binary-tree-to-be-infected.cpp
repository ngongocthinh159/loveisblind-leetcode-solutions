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
    unordered_map<int,vector<int>> g;
    int amountOfTime(TreeNode* root, int start) {
        buildGraph(root);
        unordered_set<int> visited;
        deque<int> q;
        q.push_front(start);
        visited.insert(start);
        int cnt = -1;
        while (q.size()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int u = q.back(); q.pop_back();
                for (auto v : g[u]) {
                    if (!visited.count(v)) {
                        visited.insert(v);
                        q.push_front(v);
                    }
                }
            }
            cnt++;
        }
        return cnt;
    }
    void buildGraph(TreeNode* root) {
        if (root==NULL) return;
        if (root->left) {
            g[root->val].push_back(root->left->val);
            g[root->left->val].push_back(root->val);
        }
        if (root->right) {
            g[root->val].push_back(root->right->val);
            g[root->right->val].push_back(root->val);
        }
        buildGraph(root->left);
        buildGraph(root->right);
    }
};