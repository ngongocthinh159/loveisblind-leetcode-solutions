class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 1;
        for (int i = n - 1; i >= 0; i--) {
            unordered_map<double,int> mp;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (points[i][0] == points[j][0]) mp[LONG_MAX]++;
                    else mp[atan(((double)points[i][1] - points[j][1])/((double)points[i][0] - points[j][0]))]++;
                    // mp[atan2(points[i][1] - points[j][1], points[i][0] - points[j][0])]++;
                }
            }
            for (auto &[key,val] : mp) {
                ans = max(ans,val+1);
            }
        } 
        return ans;
    }
};