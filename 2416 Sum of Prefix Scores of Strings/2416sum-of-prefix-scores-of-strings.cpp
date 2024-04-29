struct Trie {
    struct Node {
        Node* child[26];
        int passed = 0;
    };
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(string &s) {
        Node* p = root;
        for (auto c :s) {
            if (p->child[c - 'a'] == NULL) p->child[c - 'a'] = new Node();
            p = p->child[c - 'a'];
            p->passed++;
        }
    }
    int sum(string &s) {
        int res = 0;
        Node* p = root;
        for (auto c: s) {
            p = p->child[c - 'a'];
            res += p->passed;
        }
        return res;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for (auto &w : words) {
            trie.insert(w);
        }
        vector<int> ans;
        for (int i = 0; i < words.size(); i++) {
            ans.push_back(trie.sum(words[i]));
        }
        return ans;
    }
};