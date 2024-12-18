#define ll long long
#define IINF ((int) 1e8)

struct Data {
    int mn = IINF;
};
struct Segtree {
    vector<Data> segtree;
    int size;
    int n;
    Segtree(int len) {
        n = len + 1;
        size = 4*n;
        segtree.resize(size);
        build(1, 0, n - 1);
    }
    Data merge(Data &l, Data &r) {
        Data res;
        res.mn = min(l.mn, r.mn);
        return res;
    }
    void build(int idx, int s, int e) {
        if (s == e) {
            segtree[idx] = Data({IINF});
            return;
        }
        int m = (s + e)/2;
        build(2*idx, s, m);
        build(2*idx + 1, m + 1, e);
    }
    void update(int idx, int s, int e, int pos, int val) {
        if (s == e) {
            segtree[idx] = Data({val});
            return;
        }
        int m = (s + e)/2;
        if (pos <= m) update(2*idx, s, m, pos, val);
        else update(2*idx + 1, m + 1, e, pos, val);
        segtree[idx] = merge(segtree[2*idx], segtree[2*idx + 1]);
    }
    Data query(int idx, int s, int e, int l, int r) {
        if (s > r || e < l) return Data({IINF});
        if (l <= s && e <= r) return segtree[idx];
        int m = (s + e)/2;
        Data l_ans = query(2*idx, s, m, l, r);
        Data r_ans = query(2*idx + 1, m + 1, e, l, r);
        return merge(l_ans, r_ans);
    }
    void update(int pos, int val) {
        update(1, 0, n - 1, pos, val);
    }
    int query(int l, int r) {
        return query(1, 0, n - 1, l, r).mn;
    }
};
class Solution {
public:
    int n;
    vector<int> mx_j;
    vector<int> dp;
    vector<int> z_function(const string &s) {
        int n = s.size();
        vector<int> z(n);
        int l = 0, r = 0;
        for(int i = 1; i < n; i++) {
            if(i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if(i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        return z;
    }
    int minValidStrings(vector<string>& words, string target) {
        n = target.size();

        mx_j.assign(n, -1);
        for (auto &word : words) {
            auto z = z_function(word + "#" + target);
            int w_size = word.size() + 1;
            for (int i = 0; i < n; i++) {
                if (z[i + w_size]) mx_j[i] = max(mx_j[i], i + z[i + w_size] - 1);
            }
        }
        
        Segtree tree(n);
        tree.update(n, 0);
        dp.assign(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            if (mx_j[i] != -1) {
                int res = tree.query(i + 1, mx_j[i] + 1);
                if (res != IINF) {
                    dp[i] = res + 1;
                    tree.update(i, dp[i]);
                }
            }
        }

        return dp[0];
    }
};