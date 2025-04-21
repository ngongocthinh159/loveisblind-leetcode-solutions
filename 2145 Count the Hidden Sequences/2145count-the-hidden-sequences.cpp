class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long mn = 0, mx = 0, prev = 0;
        for (int i = 0; i < differences.size(); i++) {
            long long cur = prev + differences[i];
            mn = min(mn, cur);
            mx = max(mx, cur);
            prev = cur;
        }
        mx += (1LL*lower - mn);
        if (mx > upper) return 0;
        return upper - mx + 1;
    }
};