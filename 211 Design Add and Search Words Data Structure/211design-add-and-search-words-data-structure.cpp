struct Trie {
    struct Node {
        Node* child[26];
        int cnt = 0;
    };
    Node* root;
    Trie() {root = new Node();}
    void insert(string &s) {
        Node* p = root;
        for (auto c : s) {
            if (p->child[c - 'a'] == NULL) p->child[c - 'a'] = new Node();
            p = p->child[c - 'a'];
        }
        p->cnt++;
    }
    bool dfs(int i, string &s, Node* p) {
        if (i == s.size()) return true;
        if (p == NULL) return false;
        // cout << i << "\n";
        bool res = false;
        if (s[i] == '.') {
            for (int j = 0; j < 26; j++) {
                bool tmp = false;
                if (p->child[j] != NULL) {
                    tmp = dfs(i + 1, s, p->child[j]);
                    if (i == s.size() - 1) tmp = tmp && (p->child[j]->cnt > 0);                    
                }
                res = res | tmp;
            }
        } else {
            if (p->child[s[i] - 'a'] == NULL) return false;
            res = dfs(i + 1, s, p->child[s[i] - 'a']);
            if (i == s.size() - 1) res = res & (p->child[s[i] - 'a']->cnt > 0);
        }
        return res;
    }
    bool search(string &s) {
        return dfs(0, s, root);
    }
};
class WordDictionary {
public:
    Trie trie;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        // cout << "add " << word << "\n";
        trie.insert(word);
    }
    
    bool search(string word) {
        // cout << "search " << word << "\n";
        return trie.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */