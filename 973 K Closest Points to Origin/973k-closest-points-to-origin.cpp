class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(points.begin(), points.begin() + k - 1 , points.end(), [](vector<int>& p1, vector<int>& p2) {
            return 1LL * p1[0] * p1[0] + p1[1] * p1[1] < p2[0] * p2[0] + p2[1] * p2[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};