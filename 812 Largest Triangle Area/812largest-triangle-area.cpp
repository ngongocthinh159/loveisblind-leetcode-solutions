class Solution {
public:
    double find(vector<int> &a, vector<int> &b, vector<int> &c) {
        vector<int> ab = {b[0] - a[0], b[1] - a[1]};
        vector<int> ac = {c[0] - a[0], c[1] - a[1]};
        double cp = ab[0] * ac[1] - ab[1] * ac[0];
        return fabs(cp / 2);
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0;
        for (int i = 0; i < n - 2; i++)
            for (int j = 0; j < n - 1; j++) 
                for (int k = 0; k < n; k++) {
                    ans = max(ans, find(points[i], points[j], points[k]));
                }
        return ans;
    }
};