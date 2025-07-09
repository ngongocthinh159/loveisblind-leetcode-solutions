class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        int prev_e = 0;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            sum += endTime[i] - startTime[i];
            if (i >= k) sum -= endTime[i - k] - startTime[i - k];
            if (i >= k - 1) {
                int s = i - k + 1;
                int e = i;
                int S = s - 1 >= 0 ? endTime[s - 1] : 0;
                int E = i + 1 < n ? startTime[i + 1] : eventTime;
                ans = max(ans, E - S - sum);
            }
        }
        return ans;
    }
};