class Solution {
public:
    struct compare {
        bool operator() (pair<double,int> &p1, pair<double,int> &p2) {
            return p2.first > p1.first;
        }
    };
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,int>,vector<pair<double,int>>,compare> q;
        int n = classes.size();
        for (int i = 0; i < n; i++) {
            q.push({1.00*(classes[i][0] + 1)/(classes[i][1] + 1) - 1.00*classes[i][0]/classes[i][1], i});
        }
        for (int i = 0; i < extraStudents; i++) {
            auto p = q.top(); q.pop();
            int idx = p.second;
            classes[idx][0]++;
            classes[idx][1]++;
            q.push({1.00*(classes[idx][0] + 1)/(classes[idx][1] + 1) - 1.00*classes[idx][0]/classes[idx][1], idx});
        }
        double ans = 0;
        for (auto &v : classes) ans += 1.00*v[0]/v[1];
        ans /= n;
        return ans;
    }
};