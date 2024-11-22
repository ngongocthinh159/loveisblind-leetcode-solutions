#define ll long long
#define MAX 305
ll base = 3;
const int mod = 1e9 + 7;
vector<ll> basePow(MAX);
int init = [] {
    basePow[0] = 1;
    for (int i = 1; i < MAX; i++) {
        basePow[i] = basePow[i - 1]*base % mod;
    }
    return 0;
}();
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<ll,int> freq;
        int n = matrix.size(), m = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ll cur = 0;
            bool flip = matrix[i][0] == 1;
            for (int j = 0; j < m; j++) {
                cur = (cur + basePow[j]*((matrix[i][j] + flip)%2 + 1)%mod) % mod;
            }
            ans = max(ans, ++freq[cur]);
        }
        return ans;
    }
};