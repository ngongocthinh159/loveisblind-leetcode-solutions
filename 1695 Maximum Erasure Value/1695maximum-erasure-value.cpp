class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> freq;
        bool ok = true;
        int n = nums.size(), sum = 0, ans = 0;
        for (int r = 0, l = 0; r < n; r++) {
            if (++freq[nums[r]] == 2) ok = false;
            sum += nums[r];
            while (l < r && !ok) {
                sum -= nums[l];
                if (--freq[nums[l++]] == 1) ok = true;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};