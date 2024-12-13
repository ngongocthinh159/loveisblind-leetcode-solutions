class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i += 2) {
            int start = i;
            while (i + 1 < n && nums[i + 1] < nums[i]) i++;
            for (int j = i; j >= start; j -= 2) ans += nums[j];
        }
        return ans;
    }
};