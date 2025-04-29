class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        int cnt = 0, n = nums.size();
        long long ans = 0;
        for (int r = 0, l = 0; r < n; r++) {
            if (nums[r] == mx) cnt++;
            while (l <= r && cnt >= k)
                if (nums[l++] == mx) cnt--;
            ans += l;
        }
        return ans;
    }
};