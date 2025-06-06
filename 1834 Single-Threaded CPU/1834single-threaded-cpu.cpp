class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        auto compare = [&](int i, int j) {
            if (tasks[j][1] < tasks[i][1]) return true;
            if (tasks[j][1] == tasks[i][1] && j < i) return true;
            return false;
        };
        priority_queue<int, vector<int>, decltype(compare)> q(compare);
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) {
            return tasks[i][0] < tasks[j][0];
        });
        int j = 0;
        long long time = 0;
        vector<int> res;
        while (q.size() || j < n) {
            while (j < n && tasks[order[j]][0] <= time) {
                q.push(order[j]);
                j++;
            }
            if (q.size()) {
                auto idx = q.top();
                q.pop();
                time += tasks[idx][1];
                res.push_back(idx);
            } else {
                if (j < n)
                    time = tasks[order[j]][0];
            }
        }
        return res;
    }
};