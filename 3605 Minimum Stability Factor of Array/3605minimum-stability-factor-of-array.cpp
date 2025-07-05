#define MASK(x) (1LL << (x))
#define ll long long
class Solution {
public:
    vector<vector<int>> rmq;
    int query(int l, int r) {
        int bit = 32 - __builtin_clz(r - l + 1) - 1;
        return __gcd(rmq[bit][l], rmq[bit][r - MASK(bit) + 1]);
    }
    bool check(int X, vector<int> &nums, int maxC) {
        int n = nums.size();
        for (int r = X; r < n;) {
            if (query(r - X, r) >= 2) {
                maxC--;
                if (maxC < 0) return false;
                r += X + 1;
            } else {
                r++;
            }
        }
        return true;
    }
    bool canZero(vector<int> &nums, int maxC) {
        int n = nums.size();
        for (int i = 0; i < n; i++) if (nums[i] != 1) maxC--;
        return maxC >= 0;
    }
    int minStable(vector<int>& nums, int maxC) {
        if (canZero(nums, maxC))
            return 0;
        int n = nums.size();
        int msb = 32 - __builtin_clz(n) - 1;
        rmq.resize(msb + 1, vector<int>(n));
        for (int i = 0; i < n; i++) rmq[0][i] = nums[i];
        for (int j = 1; j <= msb; j++)
            for (int i = 0; i + MASK(j) - 1 < n; i++)
                rmq[j][i] = __gcd(rmq[j - 1][i], rmq[j - 1][i + MASK(j - 1)]);
        int l = 0, r = n + 1;
        while (r - l > 1) {
            int mid = l + (r - l)/2;
            if (check(mid, nums, maxC))
                r = mid;
            else
                l = mid;
        }
        return r;
    }
};