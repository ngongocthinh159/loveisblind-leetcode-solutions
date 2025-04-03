class Solution {
public:
    const double EPS = 1e-9;
    int cmp(double x, double y) {
        if (x > y + EPS) return 1;
        if (x < y - EPS) return -1;
        return 0;
    }
    double cross(vector<int>& A, vector<int>& B) {
        return 1.00 * A[0] * B[1] - B[0] * A[1];
    }
    int ccw(vector<int>& A, vector<int>& B, vector<int>& C) {
        vector<int> AB = {B[0] - A[0], B[1] - A[1]};
        vector<int> AC = {C[0] - A[0], C[1] - A[1]};
        return cmp(cross(AB, AC), 0);
    }
    void convexHull(vector<vector<int>> &p) {
        sort(p.begin(), p.end());
        vector<vector<int>> up, down;
        int n = p.size();
        for (int i = 0; i < n; i++) {
            while (up.size() >= 2 && ccw(up[up.size() - 2], up[up.size() - 1], p[i]) > 0)
                up.pop_back();
            up.push_back(p[i]);
            while (down.size() >= 2 && ccw(down[down.size() - 2], down[down.size() - 1], p[i]) < 0)
                down.pop_back();
            down.push_back(p[i]);
        }
        if (up.size() == p.size()) {
            p = up;
            return;
        }
        p = down;
        for (int i = up.size() - 2; i > 0; i--) p.push_back(up[i]);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        convexHull(trees);
        return trees;
    }
};