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
        dfs1(root, res);
        if (res.size()) res.pop_back();
        return res;
    }
    void dfs1(TreeNode* root, string &s) {
        if (!root) {
            s += "None,";
            return;
        }
        s += to_string(root->val);
        s += ',';
        dfs1(root->left, s);
        dfs1(root->right, s);
    } 

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        vector<string> arr;
        int i = 0, n = s.size();
        while (i < n) {
            string cur = "";
            while (i < n && s[i] != ',') cur += s[i++];
            arr.push_back(cur);
            i++;
        }
        reverse(arr.begin(), arr.end());
        return build(arr);
    }
    TreeNode* build(vector<string> &arr) {
        if (arr.back() == "None") {
            arr.pop_back();
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(arr.back()));
        arr.pop_back();
        node->left = build(arr);
        node->right = build(arr);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;