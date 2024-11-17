class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        vector<int> cnt(4,0);
        for (auto c : s) {
            if (c == 'Q') cnt[0]++;
            if (c == 'W') cnt[1]++;
            if (c == 'E') cnt[2]++;
            if (c == 'R') cnt[3]++;
        }
        unordered_map<char,int> M;
        for (int i = 0; i < 4; i++) {
            if (cnt[0] > n/4) M['Q'] = cnt[0] - n/4;
            if (cnt[1] > n/4) M['W'] = cnt[1] - n/4;
            if (cnt[2] > n/4) M['E'] = cnt[2] - n/4;
            if (cnt[3] > n/4) M['R'] = cnt[3] - n/4;
        }
        if (M.size() == 0) return 0;
        int l = 0;
        int ok = 0;
        int ans = 1e8;
        for (int r = 0; r < n; r++) {
            if (M.count(s[r])) {
                M[s[r]]--;
                if (M[s[r]] == 0) ok++;
            }
            while (l <= r && ok == M.size()) {
                ans = min(ans, r - l + 1);
                if (M.count(s[l])) {
                    M[s[l]]++;
                    if (M[s[l]] == 1) ok--;
                }
                l++;
            }
        }
        return ans;
    }
};