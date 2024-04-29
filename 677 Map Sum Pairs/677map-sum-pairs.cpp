struct Trie {
    struct Node {
        vector<Node*> child;
        int sum;
        Node() {
            child.assign(26, NULL);
            sum = 0;
        }
    };
    
    Node* root;
    unordered_map<string,int> S;
    Trie() {
        root = new Node();
    }

    void insert(string &s, int val) {
        int originalVal = val;
        if (S.count(s)) val -= S[s];
        S[s] = originalVal;
        Node* p = root;
        for (int i = 0; i < s.size(); i++) {
            if (p->child[s[i] - 'a'] == NULL) p->child[s[i] - 'a'] = new Node();
            p = p->child[s[i] - 'a'];
            p->sum += val;
        }
    }

    int find_sum(string &prefix) {
        Node* p = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (p->child[prefix[i] - 'a'] == NULL) return 0;
            p = p->child[prefix[i] - 'a'];
        }
        return p->sum;
    }
};

class MapSum {
public:
    unordered_map<string, int> M;
    unordered_map<string, int> visited;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        int delta = val;
        if (visited.count(key)) delta -= visited[key];
        visited[key] = val;
        string cur = "";
        for (int i = 0; i < key.size(); i++) {
            cur += key[i];
            M[cur] += delta;
        }
    }
    
    int sum(string prefix) {
        if (M.count(prefix)) return M[prefix];
        return 0;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */