#define ll long long
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mn = INT_MAX;
        int ans = 0;
        for (auto x : nums) mn = min(mn, x);
        for (auto x : nums) ans += x - mn;
        return ans;
    }
};