struct Trie {
    struct Node {
        Node* child[26];
        unordered_set<int> S;
    };
    Node* root;
    Trie() {root = new Node();}
    void insert(string &s, int i) {
        Node* p = root;
        for (auto c : s) {
            if (p->child[c - 'a'] == NULL) p->child[c - 'a'] = new Node();
            p = p->child[c - 'a'];
            p->S.insert(i);
        }
    }
    bool ok(string &sub) {
        Node* p = root;
        for (auto c : sub) {
            p = p->child[c - 'a'];
        }
        return p->S.size() == 1;
    }
};
class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        Trie trie;
        for (int i = 0; i < arr.size(); i++) {
            for (int len = 1; len <= arr[i].size(); len++) {
                for (int r = len - 1; r < arr[i].size(); r++) {
                    int l = r - len + 1;
                    string sub = arr[i].substr(l, len);
                    trie.insert(sub, i);
                }
            }
        }      
        vector<string> ans;
        for (int i = 0; i < arr.size(); i++) {
            bool ok = false;
            for (int len = 1; len <= arr[i].size(); len++) {
                vector<string> tmp;
                for (int r = len - 1; r < arr[i].size(); r++) {
                    int l = r - len + 1;
                    string sub = arr[i].substr(l, len);
                    if (trie.ok(sub)) tmp.push_back(sub);
                }
                if (tmp.size() > 0) {
                    sort(tmp.begin(), tmp.end());
                    ans.push_back(tmp[0]);
                    ok = true;
                    break;
                }
            }
            if (!ok) ans.push_back("");
        }
        return ans;
    }
};