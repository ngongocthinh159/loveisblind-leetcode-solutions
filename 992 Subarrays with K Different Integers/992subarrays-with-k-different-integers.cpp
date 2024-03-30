class Solution {
public:
    int helper(vector<int> &nums, int k) {
        int l = 0, r = 0;
        int n = nums.size();
        unordered_map<int,int> M;
        int diff = 0;
        int ans = 0;
        while (r < n) { 
            int cnt = ++M[nums[r]];
            if (cnt == 1) diff++;

            while (l <= r && diff > k) {
                int cnt2 = --M[nums[l]];
                if (cnt2 == 0) diff--;
                l++;
            }

            ans += r - l + 1;

            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k) - helper(nums,k-1);
    }
};