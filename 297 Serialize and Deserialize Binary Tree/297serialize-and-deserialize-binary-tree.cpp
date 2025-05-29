/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        dfs1(root, 1, res);
        return res;
    }
    void dfs1(TreeNode* root, bool left, string &s) {
        if (!root) return;
        if (left) s += 'L';
        else s += 'R';
        if (root->val >= 0) s += '+';
        else s += '-';
        s += to_string(abs(root->val));
        s += ',';
        dfs1(root->left, 1, s);
        dfs1(root->right, 0, s);
        s += 'B';
        s += ',';
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if (s.empty()) return nullptr;
        int n = s.size();
        int i = 0;
        TreeNode* root = nullptr;
        vector<TreeNode*> st;
        while (i < n) {
            if (s[i] == 'B') {
                st.pop_back();
                i++;
            } else {
                bool left = s[i++] == 'L';
                int sign = s[i++] == '+' ? 1 : -1;
                int cur = 0;
                while (i < n && '0' <= s[i] && s[i] <= '9') {
                    cur = 10 * cur + (s[i] - '0');
                    i++;
                }
                cur *= sign;
                TreeNode* newNode = new TreeNode(cur);
                if (st.empty()) root = newNode;
                else if (left) st.back()->left = newNode;
                else st.back()->right = newNode;
                st.push_back(newNode);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));