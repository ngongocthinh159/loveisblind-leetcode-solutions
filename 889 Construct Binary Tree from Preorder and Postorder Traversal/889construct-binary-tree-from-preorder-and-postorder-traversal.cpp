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
    vector<int> to_pre, to_post;
    TreeNode* build(int l, int r, vector<int>& preorder, vector<int>& postorder) {
        TreeNode* node = new TreeNode(preorder[l]);
        if (l + 1 <= r) {
            int left_child = preorder[l + 1];
            int right_child = postorder[to_post[preorder[l]] - 1];
            if (left_child != right_child) {
                node->left = 
                    build(l + 1, to_pre[right_child] - 1, preorder, postorder);
                node->right = 
                    build(to_pre[right_child], r, preorder, postorder);
            } else {
                node->left = build(l + 1, r, preorder, postorder);
            }
        }
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        to_pre.resize(n + 1);
        to_post.resize(n + 1);
        for (int i = 0; i < n; i++) to_pre[preorder[i]] = i, to_post[postorder[i]] = i;
        return build(0, n - 1, preorder, postorder);
    }
};