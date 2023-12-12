class Solution {
public:
    int mod = 1e9 + 7;
    bool check(long long m, int n, int a, int b, long long lcm) {
        return (m / a + m / b - m / lcm >= n); 
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long l = 1, r = 1LL*min(a,b)*n;
        long long ans = -1;
        long long lcm = ((long long) a * b) / __gcd(a, b);
        while (l <= r) {
            long long m = l + (r - l)/2;

            if (check(m, n, a, b, lcm)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans%mod;
    }
};