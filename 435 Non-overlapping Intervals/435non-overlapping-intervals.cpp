class Solution {
public:
    // The idea is to sort the interval by starting time
    // Then for each interval, check overlap with the previous interval
    // If overlap => remove the interval have larger end time (greedy)
    // Because the interval have greater end time have more chances be overlapped with the next one
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& i1, const vector<int>& i2) {
            if (i1[0] < i2[0]) return true;
            return false;
        });
        int start = intervals[0][0];
        int end = intervals[0][1];
        int cnt = 0;
        for (int i = 1; i < intervals.size(); i++) {
            int curS = intervals[i][0];
            int curE = intervals[i][1];
            // Overlap
            if (!((curS >= end) || (curE <= start))) {
                cnt++;
                if (curE >= end) { // Compare two end times of two overlapped intervals
                
                // Pick the prev interval as the interval have greater end time to remove
                // curE < end
                // => Update the start and end to the current interval
                } else {
                    start = curS;
                    end = curE;
                }
            
            // Non-overlap
            // => Update the start and end to the current interval
            } else {
                start = curS;
                end = curE;
            }
        }
        return cnt;
    }
};