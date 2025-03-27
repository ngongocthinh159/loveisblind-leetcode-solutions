class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int mx = values[0];
        int ans = -INT_MAX;
        for (int i = 1; i < values.size(); i++) {
            ans = max(ans, values[i] - i + mx);
            mx = max(mx, values[i] + i);
        }
        return ans;
    }
};