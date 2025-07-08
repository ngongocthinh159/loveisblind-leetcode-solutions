class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        int D = 0;
        auto cmp = [&](int i, int j) {
            return events[j][1] < events[i][1];
        };
        priority_queue<int,vector<int>,decltype(cmp)> q(cmp);
        int ans = 0;
        for (int i = 0; i < n || q.size();) {
            if (q.empty()) D = events[i][0];
            while (i < n && events[i][0] == D) q.push(i++);
            D++;
            ans++;
            q.pop();
            while (q.size() && events[q.top()][1] < D) q.pop();
        }
        return ans;
    }
};