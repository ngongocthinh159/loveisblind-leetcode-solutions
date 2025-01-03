#define ll long long
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        ll sum = 0, cur = 0;
        int ans = 0;
        for (auto x : nums) sum += x;
        for (int i = 0; i < nums.size() - 1; i++) {
            cur += nums[i];
            if (cur >= sum - cur) ans++;
        }
        return ans;
    }
};