class Solution {
public: 
    bool is_intersect(int l1, int r1, int l2, int r2) {
        return !(r1 + 1 < l2 || r2 + 1 < l1);
    }
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int ans = 0, n = meetings.size();
        int prev_end = 0;
        for (int i = 0; i < n;) {
            int l = meetings[i][0];
            int r = meetings[i][1];
            while (i + 1 < n && is_intersect(l, r, meetings[i + 1][0], meetings[i + 1][1])) {
                r = max(r, meetings[i + 1][1]);
                i++;
            }
            ans += l - prev_end - 1;
            prev_end = r;
            i++;
        }
        ans += days - prev_end;
        return ans;
    }
};