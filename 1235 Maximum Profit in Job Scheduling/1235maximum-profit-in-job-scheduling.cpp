class Solution {
public:
    struct Job {
        int startTime, endTime, profit;
        Job (int _1, int _2, int _3): startTime(_1), endTime(_2), profit(_3) {}
    };
    struct comparator {
        bool operator() (const Job &a, const Job &b) const {
            if (a.startTime < b.startTime) return true;
            return false;
        }
    };
    vector<int> dp;
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        dp = vector<int>(startTime.size() + 1, -1);
        int n = startTime.size();
        vector<Job> v;
        for (int i = 0; i < n; i++) {
            v.push_back(Job(startTime[i], endTime[i], profit[i]));
        }
        sort(v.begin(), v.end(), comparator());
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = max(dp[i], dp[i + 1]);
            auto idx = lower_bound(v.begin() + i + 1, v.end(), Job(v[i].endTime,-1,-1), comparator());
            if (idx != v.end()) dp[i] = max(dp[i], v[i].profit + dp[idx - v.begin()]);
            else dp[i] = max(dp[i], v[i].profit);
        }
        return dp[0];
    }
};