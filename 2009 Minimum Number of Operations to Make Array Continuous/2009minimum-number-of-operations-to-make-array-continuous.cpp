class Solution {
public:
    int minOperations(vector<int>& nums) {
        if (nums.size() ==  1) return 0;
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        int l = 0, r = 1;   // accept index 0
        int unique = 1;
        while (r < nums.size()) {
            int start = nums[l];
            int mx = start + nums.size() - 1;

            while (r < nums.size() && nums[r] <= mx) {
                if (nums[r] != nums[r - 1]) unique++;
                r++;
            }
            res = min(res, (int) nums.size() - unique);

            while (l < nums.size() && nums[l] == start) l++;
            unique--;
        }
        return res;
    }
};