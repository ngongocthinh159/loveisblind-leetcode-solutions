#define ll long long
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < n) return uniquePaths(n,m);
        ll ans = 1;
        for (int i = 1, j = m; i <= n - 1; i++, j++) {
            ans = ans * j / i;
        }
        return ans;
    }
};