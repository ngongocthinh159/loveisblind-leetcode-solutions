#define ll long long
class Solution {
public:
    const ll base = 33;
    const int MOD = 1e9 + 7;
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<int,unordered_set<int>> res;
        unordered_map<ll,int> prefHash, surHash;
        vector<int> emptyIdx, palindIdx;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            string &w = words[i];
            int m = w.size();
            if (m == 0) {
                emptyIdx.push_back(i);
                continue;
            }
            ll cur_pref = 0, cur_sur = 0, mul = 1;
            for (int j = 0; j < m; j++) {
                cur_pref = cur_pref + (w[j] - 'a' + 1) * mul % MOD;
                if (cur_pref >= MOD) cur_pref -= MOD;
                mul = mul * base;
                if (mul >= MOD) mul %= MOD;
            }
            mul = 1;
            for (int j = m - 1; j >= 0; j--) {
                cur_sur = cur_sur + (w[j] - 'a' + 1) * mul % MOD;
                if (cur_sur >= MOD) cur_sur -= MOD;
                mul = mul * base;
                if (mul >= MOD) mul %= MOD;
            }
            prefHash[cur_pref] = i;
            surHash[cur_sur] = i;
        }
        for (int i = 0; i < n; i++) {
            string &w = words[i];
            int m = w.size();
            if (m == 0) continue;
            string t = "#";
            for (auto c : w) {
                t += c;
                t += "#";
            }
            int tsize = t.size();
            vector<int> d(tsize);
            d[0] = 1;
            for (int j = 1, l = 0, r = 0; j < tsize; j++) {
                if (j <= r) d[j] = min(d[r + l - j], r - j + 1);
                while (0 <= j - d[j] && j + d[j] < tsize && t[j - d[j]] == t[j + d[j]]) ++d[j];
                if (r < j + d[j] - 1) l = j - d[j] + 1, r = j + d[j] - 1;
            }
            {
                int cen = m/2;
                if (cen + d[2*cen + (m&1)]/2 >= m) palindIdx.push_back(i);
            }
            ll cur_pref = 0, cur_sur = 0, mul = 1;
            for (int j = 0; j < m; j++) {
                cur_pref = cur_pref + (w[j] - 'a' + 1) * mul % MOD;
                if (cur_pref >= MOD) cur_pref -= MOD;
                mul = mul * base;
                if (mul >= MOD) mul %= MOD;

                int len = m - j - 1;
                bool ok = false;
                if (!len) ok = true;
                else {
                    int cen = len/2 + j + 1;
                    if (cen + d[2*cen + (len&1)]/2 >= m) ok = true;
                }
                if (ok) {
                    if (surHash.count(cur_pref) && surHash[cur_pref] != i) {
                        res[i].insert(surHash[cur_pref]);
                    }
                }
            }
            mul = 1;
            for (int j = m - 1; j >= 0; j--) {
                cur_sur = cur_sur + (w[j] - 'a' + 1) * mul % MOD;
                if (cur_sur >= MOD) cur_sur -= MOD;
                mul = mul * base;
                if (mul >= MOD) mul %= MOD;

                int len = j;
                bool ok = false;
                if (!len) ok = true;
                else {
                    int cen = len/2;
                    if (cen + d[2*cen + (len&1)]/2 >= len) ok = true;
                }
                if (ok) {
                    if (prefHash.count(cur_sur) && prefHash[cur_sur] != i) {
                        res[prefHash[cur_sur]].insert(i);
                    }
                }
            }
        }
        for (auto i : emptyIdx)
            for (auto j : palindIdx) {
                res[i].insert(j);
                res[j].insert(i);
            }
        vector<vector<int>> ans;
        for (auto &[key, val] : res)
            for (auto &x : val) ans.push_back({key, x});
        return ans;
    }
};