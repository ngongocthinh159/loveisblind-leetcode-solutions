class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int>S;
        int ans = -1;
        for(auto x : nums) {
            if (S.count(-x)) ans = max(ans, abs(x));
            S.insert(x);
        }
        return ans;
    }
};