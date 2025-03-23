class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size(), ans = 0;
        sort(courses.begin(), courses.end(), [&](vector<int>& v1, vector<int> &v2) {
            return v1[1] < v2[1] ;
        });
        priority_queue<int> q;
        int t = 1;
        for (int i = 0; i < n; i++) {
            if (t + courses[i][0] - 1 <= courses[i][1]) {
                t += courses[i][0];
                q.push(courses[i][0]);
                ans++;
            } else {
                if (q.size() && q.top() > courses[i][0]) {
                    t -= q.top(); q.pop();
                    t += courses[i][0];
                    q.push(courses[i][0]);
                }
            }
        }
        return ans;
    }
};