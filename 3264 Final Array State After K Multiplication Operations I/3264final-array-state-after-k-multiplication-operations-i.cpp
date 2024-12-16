class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        set<pair<int,int>> S;
        int n = nums.size();
        for (int i = 0; i < n; i++) S.insert({nums[i], i});
        for (int i = 0; i < k; i++) {
            auto p = *S.begin();
            S.erase(S.begin());
            S.insert({p.first*multiplier, p.second});
        }
        vector<int> ans(n);
        for (auto &p : S) ans[p.second] = p.first;
        return ans;
    }
};