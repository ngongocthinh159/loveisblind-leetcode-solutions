struct Trie {
    struct Node {
        Node* child[2];
        int val;
        int mn;
        Node() {
            for (int i = 0; i < 2; i++) child[i] = NULL;
            val = -1;
            mn = INT_MAX;
        }
    };
    Node* root;
    Trie() {
        root = new Node();
    }
    void insert(int x) {
        Node* p = root;
        int idx;
        for (int i = 31; i >= 0; i--) {
            idx = (x >> i) & 1;
            if (p->child[idx] == NULL) p->child[idx] = new Node();
            p = p->child[idx];
            p->mn = min(p->mn, x);
        }
        p->val = x;
    }
    int query(int x, int m) {
        bool ok = false;
        int x_bit, p_bit, m_bit;
        Node* p = root;
        for (int i = 31; i >= 0; i--) {
            x_bit = (x>>i) &1;
            m_bit = (m>>i) &1;
            if (!ok) {
                if (m_bit) {
                    if (x_bit) {
                        if (p->child[0] != NULL) {p_bit = 0; ok = true;}
                        else p_bit = 1;
                    } else { 
                        if (p->child[1] != NULL) p_bit = 1;
                        else {p_bit = 0; ok = true;}
                    }
                } else {
                    p_bit = 0;
                }
            } else {
                if (x_bit) {
                    if (p->child[0] != NULL) p_bit = 0;
                    else p_bit = 1;
                } else { 
                    if (p->child[1] != NULL) p_bit = 1;
                    else p_bit = 0;
                }
            }
            
            p = p->child[p_bit];
        }
        return (x^(p->val));
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie t;
        int mn = INT_MAX;
        for (auto x : nums) {
            mn = min(mn, x);
            t.insert(x);
        }
        int x, m;
        vector<int> ans;
        for (auto &q : queries) {
            x = q[0];
            m = q[1];
            if (m < mn) ans.push_back(-1);
            else ans.push_back(t.query(x, m));
        }
        return ans;
    }
};