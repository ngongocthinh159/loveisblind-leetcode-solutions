#define N 18
long long _4pow[N];
auto init = []{
    _4pow[0] = 1;
    for (int i = 1; i < N; i++) _4pow[i] = _4pow[i - 1] * 4;
    return 0;
}();
class Solution {
public:
    long long ops, mx, mx2;
    int upperb(long long x) {
        int l = 0, r = 16;
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (_4pow[m] > x)
                r = m;
            else
                l = m;
        }
        return r;
    }
    void get(int l, int r) {
        ops = 0;
        mx = -1;
        int ul = upperb(l);
        int ur = upperb(r);
        while (ul != ur) {
            long long cur = _4pow[ul];
            ops += (cur - l) * ul;
            l = cur;
            ul++;
        }
        ops += 1LL * (r - l + 1) * ur;
    }
    long long minOperations(vector<vector<int>>& queries) {
        int n = queries.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            get(queries[i][0], queries[i][1]);
            long long cur = 0;
            cur += (ops + 1) / 2;

            // if (mx * 2 > ops)
            //     cur += mx;
            // else
            //     cur += (ops + 1) / 2;
            ans += cur;
        }
        return ans;
    }
};