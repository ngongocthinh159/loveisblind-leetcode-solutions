class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), [&](auto &p1, auto &p2) {
            if (p1[0] < p2[0]) return true;
            if (p1[0] == p2[0] && p1[1] > p2[1]) return true;
            return false;
        });
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int mny = INT_MAX;
            for (int j = i - 1; j >= 0; j--) {
                if (points[j][1] >= points[i][1]) {
                    if (points[j][1] < mny) {
                        ans++;
                        mny = min(mny, points[j][1]);
                    }
                }
            }
        }
        return ans;
    }
};