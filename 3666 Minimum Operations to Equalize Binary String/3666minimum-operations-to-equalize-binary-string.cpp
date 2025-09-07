#define N 100005
#define next __next
int next[N];
class Solution {
public:
    int go(int x) {
        next[x] = next[x] == x ? next[x + 2] : next[next[x]];
        return next[x];
    }
    int minOperations(string s, int k) {
        int n = s.size();
        int o = 0;
        for (int i = 0; i < n; i++) if (s[i] == '1') o++;
        if (o == n) return 0;
        deque<int> q;
        q.push_front(o);
        int level = 0;
        iota(next, next + n + 3, 0);
        while (q.size()) {
            for (int sz = q.size(); sz; sz--) {
                auto u = q.back(); q.pop_back();
                int mxo_pick = min(k, u);
                int mno_pick = k - min(n - u, k);
                if (mno_pick <= mxo_pick) {
                    int mno_reach = u - (2 * mxo_pick - k);
                    int mxo_reach = u - (2 * mno_pick - k);
                    int j = next[mno_reach];
                    while (j <= mxo_reach) {
                        if (next[j] == j) {
                            if (j == n) return level + 1;
                            q.push_front(j);
                        }
                        j = go(j);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};