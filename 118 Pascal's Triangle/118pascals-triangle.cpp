class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        int n = numRows - 1;
        while (n--) {
            vector<int> cur;
            cur.push_back(1);
            for (int i = 1; i < res.back().size(); i++) {
                cur.push_back(res.back()[i] + res.back()[i - 1]);
            }
            cur.push_back(1);
            res.push_back(cur);
        }
        return res;
    }
};