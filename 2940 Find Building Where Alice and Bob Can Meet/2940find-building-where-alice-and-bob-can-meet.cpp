class Solution {
public:
    struct compare {
        bool operator() (pair<int,int> &p1, pair<int,int> &p2) {
            return p2.first < p1.first;
        }
    };
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int m = queries.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> q;
        vector<vector<int>> qq(n);
        vector<int> ans(m, -1);
        for (int i = 0; i < m; i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            if (a > b) swap(a, b);
            if (a == b || heights[a] < heights[b]) ans[i] = b;
            else qq[b].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            while (q.size() && q.top().first < heights[i]) {
                auto p = q.top(); q.pop();
                ans[p.second] = i;
            }
            
            for (auto idx : qq[i]) {
                q.push({max(heights[queries[idx][0]], heights[queries[idx][1]]), idx});
            }
        }
        return ans;
    }
};