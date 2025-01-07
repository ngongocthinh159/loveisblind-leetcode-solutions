#define ll long long
class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_map<ll,int> freq;
        int base = 31;
        const int MOD = 1e9 + 7;
        for (auto &w : words) {
            for (int i = 0; i < w.size(); i++) {
                ll cur = 0;
                for (int j = i; j < w.size(); j++) {
                    cur = ((w[j] - 'a' + 1) + cur*base%MOD) % MOD;
                    freq[cur]++;
                }
            }
        }
        vector<string> ans;
        for (auto &w : words) {
            ll cur = 0;
            for (int j = 0; j < w.size(); j++) {
                cur = ((w[j] - 'a' + 1) + cur*base%MOD) % MOD;
            }
            if (freq[cur] >= 2) ans.push_back(w);
        }
        return ans;
    }
};