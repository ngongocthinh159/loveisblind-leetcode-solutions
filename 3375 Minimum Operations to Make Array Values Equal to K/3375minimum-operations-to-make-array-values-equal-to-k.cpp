class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int mn = *min_element(nums.begin(), nums.end());
        if (k > mn) return -1;
        unordered_set<int> S;
        for (auto x : nums) S.insert(x);
        return (int) S.size() - (k == mn);
    }
};