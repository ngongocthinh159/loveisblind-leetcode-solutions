class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> surf(n + 2);
        vector<int> pref(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            surf[i + 1] = max(surf[i + 2], (i + 1 < n ? startTime[i + 1] : eventTime) - endTime[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int prv = startTime[i] - (i - 1 >= 0 ? endTime[i - 1] : 0);
            int nxt = (i + 1 < n ? startTime[i + 1] : eventTime) - endTime[i];
            if (max(pref[i], surf[i + 2]) >= endTime[i] - startTime[i])
                ans = max(ans, prv + nxt + endTime[i] - startTime[i]);
            else
                ans = max(ans, prv + nxt);
            pref[i + 1] = max(pref[i], startTime[i] - (i - 1 >= 0 ? endTime[i - 1] : 0));
        }
        return ans;
    }
};