struct Trie {
    struct Node {
        vector<Node*> child;
        int cnt = 0;
        Node() {child.resize(26);}
    };
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(string &s) {
        Node* p = root;
        int idx;
        for (int i = 0; i < s.size(); i++) {
            idx = s[i] - 'a';
            if (p->child[idx] == NULL) p->child[idx] = new Node();
            p = p->child[idx];
        }
        p->cnt++;
    }
    Node* getRoot() {
        return root;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string s) {
        Trie trie;
        for (auto &w : dictionary) {
            trie.insert(w);
        }
        int i = 0;
        while (i < s.size()) {
            if (s[i] == ' ') i++;
            else break;
        }
        vector<string> words;
        while (i < s.size()) {
            string cur = "";
            while (i < s.size() && s[i] != ' ') {
                cur += s[i];
                i++;
            }
            words.push_back(cur);
            while (i < s.size() && s[i] == ' ') i++;
        }
        string res = "";
        for (auto w : words) {
            Trie::Node* p = trie.getRoot();
            int idx;
            string cur = "";
            bool found = false;

            for (int i = 0; i < w.size(); i++) {
                idx = w[i] - 'a';
                if (p->child[idx] == NULL) break;
                else {
                    p = p->child[idx];
                    cur += w[i];
                }
                
                if (p->cnt > 0) {
                    found = true;
                    break;
                }
            }
            
            if (found) res += cur + " ";
            else res += w + " ";
        }
        res.pop_back();
        return res;
    }
};