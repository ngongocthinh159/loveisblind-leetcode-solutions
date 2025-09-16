struct dsu {
    vector<int> parent;
    vector<int> size;
    dsu(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        size.assign(n + 1, 1);
    }
    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb) {
            if (size[pa] < size[pb]) swap(pa, pb);
            size[pa] += size[pb];
            parent[pb] = pa;
        }
    }
};
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        dsu d(n);
        deque<int> q;
        vector<pair<int,int>> interval(n);
        vector<long long> curval(n);
        for (int i = 0; i < n; i++) q.push_front(i), interval[i] = {i, i}, curval[i] = nums[i];
        while (q.size()) {
            auto u = q.back(); q.pop_back();
            int p = d.find(u);
            int st = interval[p].first, end = interval[p].second;
            int S = st, E = end;

            if (st - 1 >= 0) {
                int p1 = d.find(st - 1);
                long long g = __gcd(curval[p], curval[p1]);
                if (p != p1 && g != 1) {
                    d.unite(p, p1);
                    curval[d.find(p)] = curval[p] * curval[p1] / g;
                    S = interval[p1].first;
                }
            }
            p = d.find(p);
            if (end + 1 < n) {
                int p2 = d.find(end + 1);
                long long g = __gcd(curval[p], curval[p2]);
                if (p != p2 && g != 1) {
                    d.unite(p, p2);
                    curval[d.find(p)] = curval[p] * curval[p2] / g;
                    E = interval[p2].second;
                }

                // if (p2 == 7) {
                //     cout << st << ' ' << end << ' ' << E << '\n';
                // }
            }
            if (S != st || E != end) {
                interval[d.find(p)] = {S, E};
                q.push_front(d.find(p));
            }
        }
        vector<int> ans;
        {
            int i = 0;
            while (i < n) {
                // cout << i << '\n';
                int p = d.find(i);
                ans.push_back(curval[p]);
                i = interval[p].second + 1;
                // cout << p << ' ' << interval[p].second << '\n';
            }
        }
        return ans;
    }
};