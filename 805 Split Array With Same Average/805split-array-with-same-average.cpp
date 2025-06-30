class Solution {
public:
    void gen(int i, int len, unordered_map<int,unordered_set<int>> &A, vector<int> &nums, int curSum, int curCnt) {
        if (i == len) {
            A[curCnt].insert(curSum);
            return;
        } 
        gen(i + 1, len, A, nums, curSum, curCnt);
        gen(i + 1, len, A, nums, curSum + nums[i], curCnt + 1);
    }
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return false;
        int tot = 0;
        for (auto x : nums) tot += x;
        unordered_map<int,unordered_set<int>> A, B;
        int half = (n + 1)/2;
        gen(0, half, A, nums, 0, 0);
        gen(half, n, B, nums, 0, 0);
        for (auto &[cnta, list] : A) {
            for (int cntb = 0; cntb <= n; cntb++) if (0 < (cnta + cntb) && (cnta + cntb) < n) {
                int X = n - (cnta + cntb);
                int Y = cnta + cntb;
                if (1LL * tot * Y % (X + Y) == 0) {
                    for (auto suma : list) {
                        long long sumb = 1LL * tot * Y / (X + Y) - suma;
                        if (B[cntb].count(sumb))
                            return true;
                    }
                }
            }
        }
        return false;
    }

};