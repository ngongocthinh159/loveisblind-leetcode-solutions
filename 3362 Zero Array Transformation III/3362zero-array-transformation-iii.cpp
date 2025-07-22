class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<vector<int>> qidx(n);
        for (int i = 0; i < m; i++) {
            qidx[queries[i][0]].push_back(i);
        }
        int cur = 0;
        vector<int> affect(n + 1);
        auto cmp = [&](int i, int j) {
            return queries[j][1] > queries[i][1];
        };
        priority_queue<int,vector<int>,decltype(cmp)> q(cmp);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cur += affect[i];
            for (auto idx : qidx[i]) {
                q.push(idx);
            }
            while (q.size() && cur < nums[i]) {
                int idx = q.top();
                q.pop();
                if (queries[idx][1] >= i) {
                    ans++;
                    cur++;
                    affect[queries[idx][1] + 1] -= 1;
                }
            }
            if (cur < nums[i]) return -1;
        }
        return m - ans;
    }
};