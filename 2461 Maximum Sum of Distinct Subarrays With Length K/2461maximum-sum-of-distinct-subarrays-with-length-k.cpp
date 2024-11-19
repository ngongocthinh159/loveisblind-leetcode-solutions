class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        long long sum = 0;
        for (int r = 0; r < k; r++) {
            sum += nums[r];
            freq[nums[r]]++;
        }
        long long ans = 0;
        if (freq.size() == k) ans = sum;
        int l = 0;
        for (int r = k; r < nums.size(); r++) {
            sum += nums[r];
            freq[nums[r]]++;
            if (--freq[nums[l]] == 0) {
                freq.erase(nums[l]);
            }
            sum -= nums[l];
            l++;
            if (freq.size() == k) ans = max(ans, sum);
        }
        return ans;
    }
};