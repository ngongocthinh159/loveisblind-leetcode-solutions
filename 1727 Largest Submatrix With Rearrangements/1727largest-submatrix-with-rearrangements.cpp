class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        vector<int> prev(matrix[0].size(), 0);
        vector<int> cur(matrix[0].size(), 0);
        int res = INT_MIN;
        for (int i = 0; i < matrix.size(); i++) {
            map<int, int> mp;
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 1) cur[j] = prev[j] + 1;
                else cur[j] = 0;
                mp[cur[j]]++;
            }

            prev = cur;
            int tmp = 0;
            for (auto& [h, cnt] : mp) {
                res = max(res, h*((int) matrix[0].size() - tmp));
                tmp += cnt;
            }
        }
        return res;
    }
};