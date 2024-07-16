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
    string path1 = "", path2 = "";
    string getDirections(TreeNode* root, int startValue, int destValue) {
        bool ok1 = false, ok2 = false;
        dfs(root, startValue, ok1, path1);
        dfs(root, destValue, ok2, path2);

        int i = -1;
        while (i + 1 < path1.size() && i + 1 < path2.size() && path1[i + 1] == path2[i + 1]) {
            i++;
        }

        string res = "";
        for (int j = path1.size() - 1; j >= i + 1; j--) res += "U";

        for (int j = i + 1; j < path2.size(); j++) res += path2[j];

        return res;
    }
    void dfs(TreeNode* root, int tar, bool &ok, string &path) {
        if (root->val == tar) {
            ok = true;
            return;
        }

        if (root->left) {
            path += 'L';
            dfs(root->left, tar, ok, path);
            if (ok) return;
            path.pop_back();
        }
        if (root->right) {
            path += 'R';
            dfs(root->right, tar, ok, path);
            if (ok) return;
            path.pop_back();
        }
    }
};