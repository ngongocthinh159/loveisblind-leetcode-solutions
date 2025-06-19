class Trie {
public:
    struct Node {
        vector<Node*> child;
        int cntEnding;
        Node() {
            child.resize(26);
            cntEnding = false;
        }  
    };

    Node *root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *p = root;
        int idx;
        for (auto c : word) {
            idx = c - 'a';
            if (!p->child[idx]) p->child[idx] = new Node();
            p = p->child[idx];
        }
        p->cntEnding++;
    }
    
    bool search(string word) {
        Node *p = root;
        int idx;
        for (auto c : word) {
            idx = c - 'a';
            if (!p->child[idx]) return false;
            p = p->child[idx];
        }
        return p->cntEnding != 0;
    }
    
    bool startsWith(string prefix) {
        Node *p = root;
        int idx;
        for (auto c : prefix) {
            idx = c - 'a';
            if (!p->child[idx]) return false;
            p = p->child[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */