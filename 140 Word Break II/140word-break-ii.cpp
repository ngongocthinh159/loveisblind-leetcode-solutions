struct Trie {
    struct Node {
        vector<Node*> child;
        bool isWord = false;
        Node() {
            child.resize(26, NULL);
        }
    };
    
    Node* root;
    Trie() {
        root = new Node();
    }
    Node* getRoot() {return this->root;}
    void insert(string &s) {
        Node* p = root;
        int idx;
        for (int i = 0; i < s.size(); i++) {
            idx = s[i] - 'a';
            if (p->child[idx] == NULL) p->child[idx] = new Node();
            p = p->child[idx];
        }
        p->isWord = true;
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<vector<string>> dp(s.size() + 1);
        dp[s.size()] = {""};
        Trie trie;
        for (auto &w : wordDict) {
            trie.insert(w);
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            string cur = "";
            vector<string> res;
            Trie::Node* p = trie.getRoot();
            int idx;
            for (int j = i; j < s.size(); j++) {
                cur += s[j];
                idx = s[j] - 'a';
                if (p->child[idx] == NULL) break;
                p = p->child[idx];

                if (p->isWord) {
                    for (auto &_s : dp[j + 1]) {
                        if (_s.size()) res.push_back(cur + " " + _s);
                        else res.push_back(cur);
                    }
                }
            }
            dp[i] = res;
        }
        return dp[0];
    }
};