#define ll long long
#define MAXN 8
ll fact[MAXN];
auto init = []{
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i;
    return 0;
}();
class Solution {
public:
    vector<int> path, num;
    ll ans = 0;
    void dfs(int i, int len) {
        if (i == num.size()) {
            if (len != 0) {
                ll cur = fact[len];
                for (auto x : path) cur = cur / fact[x];
                ans += cur;
            }
            return;
        }
        for (int j = 0; j <= num[i]; j++) {
            path.push_back(j);
            dfs(i + 1, len + j);
            path.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        unordered_map<char,int> freq;
        for (auto c : tiles) freq[c]++;
        for (auto [c, cnt] : freq) num.push_back(cnt);
        dfs(0, 0);
        return ans;
    }
};