struct Trie {
private:
    struct Node {
        Node* child[26]{};
        int cnt = 0;
        int mxd = 0;
        Node() {}
    };
    Node *root;
    int k;

    void _updateMax(Node *p) {
        if (p->cnt < k) {
            p->mxd = 0;
            return;
        }
        int mxc = 0;
        for (int i = 0; i < 26; i++) if (p->child[i]) {
            mxc = max(mxc, p->child[i]->mxd);
        }
        p->mxd = 1 + mxc;
    }

    void _insert(int i, string &s, Node *p) {
        if (i == (int) s.size()) {
            p->cnt++;
            _updateMax(p);
            return;
        };
        int idx = s[i] - 'a';
        if (!p->child[idx]) p->child[idx] = new Node;
        p->cnt++;
        _insert(i + 1, s, p->child[idx]);
        
        _updateMax(p);
    }

    bool _erase(int i, string &s, Node *p) {
        if (i == (int) s.size()) {
            p->cnt--;
            _updateMax(p);
            return p->cnt == 0;
        };

        int idx = s[i] - 'a';
        p->cnt--;
        bool shouldRemove = _erase(i + 1, s, p->child[idx]);
        if (shouldRemove) {
            delete p->child[idx];
            p->child[idx] = nullptr;
        }

        _updateMax(p);
        
        return p->cnt == 0;
    }

public:
    Trie(int k) : k(k) {
        root = new Node;
    }

    void insert(string &s) {
        _insert(0, s, root);        
    }

    void erase(string &s) {
        _erase(0, s, root);
    }

    int getMaxPref() {
        return max(0, root->mxd - 1);
    }
};  

class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        Trie trie(k);
        int n = words.size();
        for (int i = 0; i < n; i++) trie.insert(words[i]);
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            trie.erase(words[i]);   
            ans[i] = trie.getMaxPref();
            trie.insert(words[i]);  
        }
        return move(ans);
    }
};