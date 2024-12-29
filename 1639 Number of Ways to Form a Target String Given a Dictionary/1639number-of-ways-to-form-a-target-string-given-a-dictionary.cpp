#define ll long long
class Solution {
public:
    const int MOD = 1e9 + 7;
    int numWays(vector<string>& words, string target) {
        int len = words[0].size();
        int n = target.size();
        vector<vector<int>> freq(len, vector<int>(26));
        for (auto &w : words) {
            for (int i = 0; i < w.size(); i++) freq[i][w[i] - 'a']++;
        }
        vector<int> cur(len + 1), prev(len + 1, 1);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = len - 1; j >= 0; j--) {
                cur[j] = 0;
                int cidx = target[i] - 'a';
                if (freq[j][cidx])
                    cur[j] = (cur[j] + 1LL * prev[j + 1] * freq[j][cidx] % MOD) % MOD;
                cur[j] = (cur[j] + cur[j + 1]) % MOD;
            }
            prev = cur;
        }
        return cur[0];
    }
};