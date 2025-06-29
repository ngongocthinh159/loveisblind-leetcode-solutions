class Solution {
public:
    void gen(int i, int len, vector<vector<int>> &A, vector<int>& nums, int cur, int cnt) {
        if (i == len) {
            A[cnt].push_back(2*cur);
            return;
        }
        gen(i + 1, len, A, nums, cur, cnt);
        gen(i + 1, len, A, nums, cur + nums[i], cnt + 1);
    }
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        int tot = 0;
        for (auto x : nums) tot += x;
        vector<vector<int>> A(n + 1), B(n + 1);
        gen(0, n, A, nums, 0, 0);
        gen(n, 2*n, B, nums, 0, 0);
        for (int cnt = 0; cnt <= n; cnt++) {
            sort(B[cnt].begin(), B[cnt].end());
        }
        int ans = 1e9;
        for (int acnt = 0; acnt <= n; acnt++) {
            auto &list = A[acnt];
            int rcnt = n - acnt;
            auto &listb = B[rcnt];
            for (auto asum : list) {
                int tar = tot - asum;
                auto it1 = lower_bound(listb.begin(), listb.end(), tar);
                auto it2 = upper_bound(listb.begin(), listb.end(), tar);
                if (it1 != listb.end()) {
                    ans = min(ans, (asum + *it1) - tot);
                }
                if (it2 != listb.begin()) {
                    it2--;
                    ans = min(ans, tot - (asum + *it2));
                }
            }
        }
        return ans;
    }
};