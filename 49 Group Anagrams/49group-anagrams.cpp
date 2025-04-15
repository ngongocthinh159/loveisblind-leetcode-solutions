#define N 10005
const int base = 1e5 + 5;
const int MOD = 1e9 + 7;
long long basepow[N];
auto init = [] {
    basepow[0] = 1;
    for (int i = 1; i < N; i++) basepow[i] = 1LL * basepow[i - 1] * base % MOD;
    return 0;
}();
class Solution {
public:
    int get_hash(string &s) {
        vector<int> freq(26,0);
        for (auto c : s) freq[c - 'a']++;
        long long res = 0;
        for (int i = 0; i < 26; i++) {
            res = res + (freq[i] + 1) * basepow[i];
            while (res >= MOD) res -= MOD;
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<int,vector<int>> M;
        for (int i = 0; i < strs.size(); i++) {
            M[get_hash(strs[i])].push_back(i);
        }
        vector<vector<string>> res(M.size());
        int j = 0;
        for (auto &[H, list]: M) {
            for (auto i : list) res[j].push_back(strs[i]);
            j++;
        }
        return res;
    }
};