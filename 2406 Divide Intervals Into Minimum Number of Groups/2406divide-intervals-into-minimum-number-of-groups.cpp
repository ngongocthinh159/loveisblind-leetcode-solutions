class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> effect(1e6 + 5);
        for (int i = 0; i < n; i++) {
            effect[intervals[i][0]]++;
            effect[intervals[i][1] + 1]--;
        }
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < 1e6 + 5; i++) {
            cur += effect[i];
            ans = max(ans, cur);
        }
        return ans;
    }
};