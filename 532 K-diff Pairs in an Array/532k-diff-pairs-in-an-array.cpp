class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        unordered_set<int> S;
        for (int i = 0; i < n;) {
            int tar = nums[i] - k;
            if (tar != nums[i]) {
                if (S.count(tar)) ans++;
            } else {
                if (i + 1 < n && nums[i] == nums[i + 1]) ans++;
            }
            int cur = nums[i];
            while (i < n && nums[i] == cur) i++;
            S.insert(cur);
        }
        return ans;
    }
};