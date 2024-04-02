class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int closestL = -1;
        int closestR = -1;
        vector<int> l(seats.size());
        vector<int> r(seats.size());
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 1) closestL = i;
            l[i] = closestL != -1 ? closestL : i;
        }
        for (int i = seats.size() - 1; i >= 0; i--) {
            if (seats[i] == 1) closestR = i;
            r[i] = closestR != -1 ? closestR : i;
        }
        int ans = INT_MIN;
        for (int i = 0; i < l.size(); i++) {
            if (seats[i] == 1) continue;
            int left = i - l[i] != 0 ? i - l[i] : INT_MAX;
            int right = r[i] - i != 0 ? r[i] - i : INT_MAX;
            ans = max(ans, min(left, right));
        }
        return ans;
    }
};