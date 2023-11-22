class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int,vector<int>> mp;
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = 0; j < nums[i].size(); j++) {
                mp[i + j].push_back(nums[i][j]);
            }
        }
        vector<int> res;
        int cur = 0;
        while (mp.count(cur)) {
            for (auto& num : mp[cur]) {
                res.push_back(num);
            }
            cur++;
        }
        return res;

    }
};