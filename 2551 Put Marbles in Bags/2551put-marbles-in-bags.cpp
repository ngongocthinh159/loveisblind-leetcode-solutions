#define MAXN 100005
long long d[MAXN];
class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        int n = w.size();
        long long ans = 0;
        for (int i = 0; i < n - 1; i++) d[i] = w[i] + w[i + 1];
        nth_element(d, d + (k - 1) - 1, d + n - 1);
        for (int i = 0; i < k - 1; i++) {
            ans += -d[i];
        }
        nth_element(d, d + (n - 1) - (k - 1), d + n - 1);
        for (int i = n - 2; i > n - 2 - (k - 1); i--) {
            ans += d[i];
        }
        return ans;
    }
};