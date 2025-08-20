class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int i = 0, n = nums.size();
        long long ans = 0;
        while (i < n) {
            if (nums[i]) {
                i++;
                continue;
            }
            int st = i, end = i;
            while (i < n && !nums[i]) end = i, i++;
            int len = end - st + 1;
            ans += 1LL * len * (len + 1) / 2;
        }
        return ans;
    }
};