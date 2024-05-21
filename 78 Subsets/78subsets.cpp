class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back({});
        for (int i = 0; i < nums.size(); i++) {
            vector<vector<int>> cur;
            for (auto &v : res) {
                vector<int> tmp = v;
                tmp.push_back(nums[i]);
                cur.push_back(tmp);
            }
            for (auto &v : cur) {
                res.push_back(v);
            }
        }
        return res;
    }
};