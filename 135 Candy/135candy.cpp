class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> deg(n), candy(n);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) deg[i]++;
            if (ratings[i] < ratings[i - 1]) deg[i - 1]++;
        }
        deque<int> q;
        for (int i = 0; i < n; i++) {
            if (!deg[i]) q.push_front(i);
        }
        int level = 1;
        while (q.size()) {
            for (int sz = q.size(); sz; sz--) {
                auto u = q.back();
                q.pop_back();
                candy[u] = level;
                for (int move : {-1,1}) {
                    int v = u + move;
                    if (0 <= v && v < n && ratings[u] < ratings[v]) {
                        if (--deg[v] == 0) q.push_front(v);
                    }
                }
            }
            level++;
        }
        int ans = 0;
        for (auto x : candy) ans += x;
        return ans;
    }
};