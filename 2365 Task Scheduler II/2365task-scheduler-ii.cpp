class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long ans = 0;
        unordered_map<long long, long long> M;
        long long cur = 1;
        for (int i = 0; i < tasks.size(); i++) {
            if (M.count(tasks[i])) cur = max(cur, M[tasks[i]]);
            M[tasks[i]] = cur + space + 1;
            cur++;
        }
        return --cur;
    }
};