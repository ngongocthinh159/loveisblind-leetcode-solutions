class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> v;
        for (int i = 0; i < difficulty.size(); i++) v.push_back({difficulty[i], profit[i]});
        sort(worker.begin(), worker.end());
        sort(v.begin(), v.end());
        int j = 0;
        int ans = 0;
        int mx = INT_MIN;
        for (int i = 0; i < worker.size(); i++) {
            while (j < v.size() && worker[i] >= v[j].first) {
                mx = max(mx, v[j++].second);
            }
            if (mx != INT_MIN) ans += mx;
        }
        return ans;
    }
};