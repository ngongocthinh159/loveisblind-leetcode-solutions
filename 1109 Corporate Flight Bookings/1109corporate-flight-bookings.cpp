class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> dif(n + 2);
        for (int i = 0; i < bookings.size(); i++) {
            dif[bookings[i][0]] += bookings[i][2];
            dif[bookings[i][1] + 1] -= bookings[i][2];
        }
        for (int i = 1; i <= n; i++) {
            dif[i + 1] += dif[i];
        }
        vector<int> ans(dif.begin() + 1, dif.begin() + 1 + n);
        return ans;
    }
};