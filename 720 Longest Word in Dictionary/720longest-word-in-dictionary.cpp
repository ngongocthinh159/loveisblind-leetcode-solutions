struct Trie {
    struct Node {
        Node* child[26];
        bool ok = false;
    };
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(string &s) {
        Node* p = root;
        for (int i = 0; i < s.size(); i++) {
            if (p->child[s[i] - 'a'] == NULL) p->child[s[i] - 'a'] = new Node();
            p = p->child[s[i] - 'a'];
        }
        p->ok = true;
    }
    string res = "";
    string find_longest() {
        string cur = "";
        dfs(root, cur);
        return res;
    }
    void dfs(Node* p, string &path) {
        if (res.size() < path.size()) res = path;
        for (int i = 0; i < 26; i++) {
            if (p->child[i] != NULL && p->child[i]->ok) {
                path += ('a' + i);
                dfs(p->child[i], path);
                path.pop_back();
            }
        }
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for (auto &w : words) {
            trie.insert(w);
        }
        return trie.find_longest();
    }
};