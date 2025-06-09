
bool init = false;
class Solution {
public:
    int cnt(int x) {
        int res = 0;
        while (x % 2 == 0) x /= 2, res++;
        return res;
    }
    long long maxGCDScore(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = -1;
        for (int i = 0; i < n; i++) {
            int cur_gcd = nums[i];
            int mn_fact_2 = INT_MAX;
            int cnt_mn_equal = 0;
            for (int j = i; j < n; j++) {
                cur_gcd = __gcd(nums[j], cur_gcd);
                ans = max(ans, 1LL*cur_gcd*(j - i + 1));
                int fact2 = cnt(nums[j]);

                if (fact2 < mn_fact_2) {
                    mn_fact_2 = fact2;
                    cnt_mn_equal = 1;
                } else if (fact2 == mn_fact_2)
                    cnt_mn_equal++;

                if (cnt_mn_equal <= k) {
                    ans = max(ans, 2LL*cur_gcd*(j - i + 1));
                }
            }
        }
        return ans;
    }
};