class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        int ans = 0;
        deque<int> mxq;
        long long sum = 0;
        for (int r = 0, l = 0; r < n; r++) {
            sum += runningCosts[r];
            while (mxq.size() && chargeTimes[mxq.front()] <= chargeTimes[r]) mxq.pop_front();
            mxq.push_front(r);
            
            while (mxq.size() && !(l <= mxq.back() && mxq.back() <= r)) mxq.pop_back();
            int cur_max = chargeTimes[mxq.back()];
            while (l <= r && (cur_max + (r - l + 1) * sum > budget)) {
                sum -= runningCosts[l];
                l++;
                if (l <= r) {
                    while (mxq.size() && !(l <= mxq.back() && mxq.back() <= r)) mxq.pop_back();
                    cur_max = chargeTimes[mxq.back()];
                }
            }

            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};