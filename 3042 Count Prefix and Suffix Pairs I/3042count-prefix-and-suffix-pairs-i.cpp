struct Node {
    vector<Node*> child;
    Node* left;
    Node* right;
    bitset<50> bs;
    Node() {child.resize(26);}
};
class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        Node* pre_root = new Node;
        Node* sur_root = new Node;
        int n = words.size();
        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            Node* p = pre_root;
            int idx;
            bool found = true;
            for (auto c : words[i]) {
                idx = c - 'a';
                if (!p->child[idx]) {
                    found = false;
                    break;
                }
                p = p->child[idx];
            }
            if (found) {
                Node* p2 = sur_root;
                bool found2 = true;
                for (int j = words[i].size() - 1; j >= 0; j--) {
                    idx = words[i][j] - 'a';
                    if (!p2->child[idx]) {
                        found2 = false;
                        break;
                    }
                    p2 = p2->child[idx];
                }
                if (found2) {
                    ans += (p->bs & p2->bs).count();
                }
            }
            p = pre_root;
            for (auto c : words[i]) {
                idx = c - 'a';
                if (!p->child[idx]) p->child[idx] = new Node;
                p = p->child[idx];
                p->bs.set(i);
            }
            p = sur_root;
            for (int j = words[i].size() - 1; j>= 0; j--) {
                idx = words[i][j] - 'a';
                if (!p->child[idx]) p->child[idx] = new Node;
                p = p->child[idx];
                p->bs.set(i);
            }
        }
        return ans;
    }
};