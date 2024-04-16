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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            return newNode;
        }
        deque<TreeNode*> q;
        q.push_front(root);
        int curDepth = 1;
        while (q.size()) {
            int size = q.size();
            vector<pair<TreeNode*, TreeNode*>> l;
            vector<pair<TreeNode*, TreeNode*>> r;
            for (int i = 0; i < size; i++) {
                auto &u = q.back(); q.pop_back();
                l.push_back({u->left,u});
                r.push_back({u->right,u});
                if (u->left) {q.push_front(u->left);}
                if (u->right) {q.push_front(u->right);}
            }
            if (curDepth == depth - 1) {
                for (auto &p : l) {
                    auto parent = p.second;
                    auto child = p.first;
                    TreeNode* newNode = new TreeNode(val);
                    parent->left = newNode;
                    newNode->left = child;
                }
                for (auto &p : r) {
                    auto parent = p.second;
                    auto child = p.first;
                    TreeNode* newNode = new TreeNode(val);
                    parent->right = newNode;
                    newNode->right = child;
                }
                break;
            }
            curDepth++;
        }
        return root;
    }
};