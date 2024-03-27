class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long prod = 1;
        int n = nums.size();
        int l = 0, r = 0;
        int ans = 0;
        while (r < n) {
            prod = prod * nums[r];

            while (l <= r && prod >= k) {
                prod = prod / nums[l++];
            }
            ans += r - l + 1;
 
            r++;
        }
        return ans;
    }
};