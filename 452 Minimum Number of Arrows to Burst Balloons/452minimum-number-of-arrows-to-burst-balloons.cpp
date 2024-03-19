class Solution {
public:
    bool is_overlap(vector<int>&i1, vector<int>&i2) {
        return !(i1[1] < i2[0] || i1[0] > i2[1]);
    }
    void intersect(vector<int> &i1, vector<int> &i2) {
        i1[0] = max(i1[0],i2[0]);
        i1[1] = min(i1[1],i2[1]);
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int i = 0;
        int ans = 0;
        while (i < points.size()) {
            vector<int> cur = points[i++];
            while (i < points.size() && is_overlap(cur, points[i])) {
                intersect(cur,points[i]);
                i++;
            }
            ans++;
        }
        return ans;
    }
};