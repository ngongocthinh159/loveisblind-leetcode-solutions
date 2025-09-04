class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        sort(points.begin(), points.end(), [](auto &p1, auto &p2) {
            if (p1[0] < p2[0]) return true;
            if (p1[0] == p2[0] && p1[1] > p2[1]) return true;
            return false;
        });
        for (int i = 0; i < n; i++) {
            int top = 0;
            int py = INT_MAX, px = INT_MAX, cnt = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (points[j][0] <= points[i][0] && points[j][1] >= points[i][1]) {
                    if (points[j][0] < px && points[j][1] < py) {
                        cnt++;
                        px = points[j][0];
                        py = points[j][1];
                    }
                }
            }
            ans += cnt;
        }
        return ans;
    }
};