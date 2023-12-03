class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        vector<int>& prev = points[0];
        for (int i = 1; i < points.size(); i++) {
            vector<int>& cur = points[i];
            int difX = abs(cur[0] - prev[0]);
            int difY = abs(cur[1] - prev[1]);
            res += min(difX, difY);
            res += difX - min(difX, difY);
            res += difY - min(difX, difY);
            prev = cur;
        }
        return res;
    }
};