class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> cnt(201, -1);
        vector<vector<int>> res;
        for (auto num : nums) {
            cnt[num]++;
            if (cnt[num] >= res.size()) res.push_back({});
            res[cnt[num]].push_back(num);
        }
        return res;
    }
};