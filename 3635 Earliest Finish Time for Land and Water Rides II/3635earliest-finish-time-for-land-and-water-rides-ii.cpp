class Solution {
public:
    int cal(vector<int>& atime, vector<int>& aduration, vector<int>& btime, vector<int>& bduration) {
        int n = atime.size(), m = btime.size();
        const int IINF = 1e9 + 5;
        vector<int> mnb(m + 2, IINF), mnpb(m + 1, IINF);
        for (int i = m - 1; i >= 0; i--) {
            mnb[i + 1] = min(mnb[i + 2], btime[i] + bduration[i]);
        }
        for (int i = 0; i < m; i++) {
            mnpb[i + 1] = min(mnpb[i], bduration[i]);
        }
        int res = IINF;
        for (int i = 0; i < n; i++) {
            int e = atime[i] + aduration[i];
            int idx = lower_bound(btime.begin(), btime.end(), e) - btime.begin();
            int cur = IINF;
            if (idx < m) {
                cur = min(cur, mnb[idx + 1]);
            }
            if (idx - 1 >= 0) {
                cur = min(cur, e + mnpb[idx]);
            }
            res = min(res, cur);
        }
        return res;
    }
    void sort_me(vector<int> &atime, vector<int> &aduration) {
        int n = atime.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) {
            return atime[i] < atime[j];
        });
        vector<int> natime(n), naduration(n);
        for (int i = 0; i < n; i++) {
            natime[i] = atime[order[i]];
            naduration[i] = aduration[order[i]];
        }
        swap(atime, natime);
        swap(aduration, naduration);
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        sort_me(landStartTime, landDuration);
        sort_me(waterStartTime, waterDuration);
        return min(cal(landStartTime, landDuration, waterStartTime, waterDuration),
                 cal(waterStartTime, waterDuration, landStartTime, landDuration));
    }
};