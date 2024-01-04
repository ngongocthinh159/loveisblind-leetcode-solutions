class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto num : nums)
            mp[num]++;
        int ans = 0;
        for (auto [key, val] : mp) {
            if (val == 1) return -1;
            else if (val % 3 == 0) ans += val/3;
            else if (val % 3 == 2) ans += val/3 + 1;
            else if (val % 3 == 1) ans += (val/3 - 1) + 2;
        }
        return ans;
    }
};