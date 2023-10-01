class Solution {
public:
    static bool customComparator(vector<int>& i1, vector<int>& i2) {
        if (i1[0] < i2[0]) return true;
        return false;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& i1, vector<int>& i2) {
            if (i1[0] < i2[0]) return true;
            return false;
        });
        vector<vector<int>> res;
        int curStart = intervals[0][0];
        int curEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            int startTime = intervals[i][0];
            int endTime = intervals[i][1];
            if (startTime <= curEnd) {
                curEnd = max(curEnd, endTime);
            } else {
                res.push_back({curStart, curEnd});
                curStart = startTime;
                curEnd = endTime;
            }
        }
        res.push_back({curStart, curEnd});
        return res;
    }
};