class Solution {
public:
    bool check(int x, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        if (workers.size() < x) return false;
        multiset<int> S(workers.begin(), workers.end());
        for (int i = x; i >= 0; i--) {
            if (!S.size()) return false;
            if (*S.rbegin() < tasks[i]) {
                if (!pills) return false;
                if (*S.rbegin() + strength < tasks[i]) return false;
                auto it = S.lower_bound(tasks[i] - strength);
                S.erase(it);
                pills--;
            } else {
                auto it = prev(S.end());
                S.erase(it);
                // auto it = S.lower_bound(tasks[i]);
                // S.erase(it);
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int l = -1, r = tasks.size();
        while (r - l > 1) {
            int m = l + (r - l)/2;
            if (check(m, tasks, workers, pills, strength))
                l = m;
            else
                r = m;
        }
        return l + 1;
    }
};