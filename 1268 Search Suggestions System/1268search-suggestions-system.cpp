struct Node {
    Node* child[26];
    int cnt = 0;
    Node() {for (int i = 0; i < 26; i++) child[i] = nullptr;}
};
void insert(Node* root, string &s) {
    Node* p = root;
    for (auto c : s) {
        int idx = c - 'a';
        if (!p->child[idx]) p->child[idx] = new Node;
        p = p->child[idx];
    }
    p->cnt++;
}
void dfs(Node* root, string &prefix, vector<string> &res, int &cnt) {
    if (cnt == 0) return;
    for (int i = 0; i < root->cnt && cnt != 0; i++) {
        res.push_back(prefix);
        cnt--;
    }

    for (int i = 0; i < 26; i++) {
        if (root->child[i]) {
            prefix += (i + 'a');
            dfs(root->child[i], prefix, res, cnt);
            prefix.pop_back();
        }
    }
}
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Node* root = new Node;
        for (auto &s : products) insert(root, s);
        Node* p = root;
        string prefix = "";
        vector<vector<string>> ans;
        for (int i = 0; i < searchWord.size(); i++) {
            int idx = searchWord[i] - 'a';
            if (!p->child[idx]) break;
            p = p->child[idx];
            prefix += searchWord[i];
            int suggest = 3;
            vector<string> res;
            dfs(p, prefix, res, suggest);
            ans.push_back(res);
        }
        while (ans.size() < searchWord.size()) ans.push_back({});
        return ans;
    }
};