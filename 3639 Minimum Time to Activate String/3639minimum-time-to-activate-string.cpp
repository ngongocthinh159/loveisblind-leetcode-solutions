class Solution {
public:
    bool check(int idx, string &s, vector<int> &order, int k) {
        int n = s.size();
        long long tot = 1LL * n * (n + 1) / 2;
        string t = s;
        for (int i = 0; i <= idx; i++) t[order[i]] = '*';
        int i = 0;
        while (i < n) {
            if (t[i] == '*') {
                i++;
                continue;
            }
            int cnt = 0;
            while (i < n && t[i] != '*') {
                cnt++;
                i++;
            }
            tot -= 1LL * cnt * (cnt + 1) / 2;
        }
        return tot >= k;
    }
    int minTime(string s, vector<int>& order, int k) {
        int n = s.size();
        int l = -1, r = n;
        while (r - l > 1) {
            int m = l + (r - l)/2;
            if (check(m, s, order, k))
                r = m;
            else
                l = m;
        }
        return r == n ? -1 : r;
    }
};