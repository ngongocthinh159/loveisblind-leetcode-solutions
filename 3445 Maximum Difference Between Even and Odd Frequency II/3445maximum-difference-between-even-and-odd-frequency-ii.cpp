class Solution {
public:
    const int IINF = 1e9;
    int solve(int a, int b, string &s, int k) {
        int n = s.size();
        vector<pair<int,pair<int,int>>> info(n);
        int cnta = 0, cntb = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] - '0' == a) cnta++;
            if (s[i] - '0' == b) cntb++;
            info[i] = {cnta - cntb, {cnta&1, cntb&1}};
        }
        cnta = 0, cntb = 0;
        int wa = 0, wb = 0;
        int ans = INT_MIN;
        vector<vector<int>> mnDifParity(2, vector<int>(2, IINF));
        for (int i = 0, l = -1; i < n; i++) {
            if (s[i] - '0' == a) {
                ++cnta;
                ++wa;
            }
            if (s[i] - '0' == b) {
                ++cntb;
                ++wb;
            }
            int pa = cnta & 1;
            int pb = cntb & 1;
            
            while (i - l + 1 > k && wa >= 1 && wb >= 2) {
                int lpa = l == -1 ? 0 : info[l].second.first;
                int lpb = l == -1 ? 0 : info[l].second.second;
                int ldif = l == -1 ? 0 : info[l].first;
                mnDifParity[lpa][lpb] = min(mnDifParity[lpa][lpb], ldif);
                if (l != -1) {
                    if (s[l] - '0' == a) {
                        --wa;
                    }
                    if (s[l] - '0' == b) {
                        --wb;
                    }
                }
                l++;
            }

            if (mnDifParity[pa^1][pb] != IINF) {
                ans = max(ans, cnta - cntb - mnDifParity[pa^1][pb]);
            }
        }
        return ans;
    }
    int maxDifference(string s, int k) {
        int n = s.size();
        int ans = INT_MIN;
        for (int i = 0; i <= 4; i++)
            for (int j = 0; j <= 4; j++) if (i != j) {
                ans = max(ans, solve(i, j, s, k));
            }
        return ans;
    }
};