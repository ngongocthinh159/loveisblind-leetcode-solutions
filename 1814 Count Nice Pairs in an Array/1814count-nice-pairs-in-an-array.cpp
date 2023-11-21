class Solution {
public:
    int m = 1e9 + 7;
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, long> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i] - reverse(nums[i])]++;
        }
        int res = 0;
        for (auto [key, val] : mp) {
            int tmp = (val*(val - 1)/2)%m;
            res = (res%m + tmp)%m;
        }
        return res;
    }

    int reverse(int n) {    
        int res = 0;
        while (n) {
            res = 10*res + n%10;
            n /= 10;
        }
        return res;
    }
};