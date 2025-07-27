class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& ps) {
        for (auto &p : ps) if (p[0] > p[1]) swap(p[0], p[1]);
        vector<vector<int>> rToList(n + 1);
        for (auto &p : ps) rToList[p[1]].push_back(p[0] + 1);
        long long tot = 0;
        vector<long long> bonus(n + 1);
        pair<int,int> l = {1, 0};
        for (int r = 1; r <= n; r++) {
            for (auto &_l : rToList[r]) {
                if (l.first < _l) {
                    l = {_l, l.first};
                } else if (l.second < _l) {
                    l = {l.first, _l};
                }
            }
            tot += (r - l.first + 1);
            if (l.first - 1) {
                bonus[l.first - 1] += l.first - l.second;
            }
        }
        return tot + *max_element(bonus.begin(), bonus.end());
    }
};