class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        mp[0]++;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int tar = sum - goal;
            ans += mp[tar];
            mp[sum]++;
        }
        return ans;
    }
};