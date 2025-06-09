class Solution {
public:
    vector<int> dp;
    int n;
    const int IINF = 1e9;
    vector<vector<vector<int>>> idx;
    int solve(string &s, string &t) {
        int n = s.size();
        vector<int> vis(n);
        for (int i = 0; i < n; i++) {
            idx[s[i] - 'a'][t[i] - 'a'].push_back(i);
            if (s[i] - 'a' == t[i] - 'a') vis[i] = 1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) if (!vis[i]) {
            if (idx[t[i] - 'a'][s[i] - 'a'].size()) {
                vis[idx[t[i] - 'a'][s[i] - 'a'].back()] = 1;
                vis[i] = 1;
                idx[t[i] - 'a'][s[i] - 'a'].pop_back();
                ans++;
            }
        }
        for (int i = 0; i< n; i++) if (!vis[i]) ans++;
        for (int i = 0; i < n; i++)
            idx[s[i] - 'a'][t[i] - 'a'].clear();
        return ans;
    }
    int calc(int l, int r, string& s, string &t) {
        string ss = s.substr(l, r - l + 1);
        string tt = t.substr(l, r - l + 1);
        int ans1 = solve(ss, tt);
        reverse(ss.begin(), ss.end());
        int ans2 = solve(ss, tt) + 1;
        return min(ans1, ans2);
    }
    int minOperations(string word1, string word2) {
        n = word1.size();
        dp.assign(n, IINF);
        idx.assign(26, vector<vector<int>>(26,
            vector<int>()));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i] = min(dp[i], (j - 1 >= 0 ? dp[j - 1] : 0) + calc(j, i, word1, word2));
            }
        }
        return dp[n - 1];
    }
};