class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) {
            return aliceValues[i] + bobValues[i] > aliceValues[j] + bobValues[j];
        });
        long long dif = 0;
        for (int i = 0, sign = 1; i < n; i++, sign *= -1) {
            if (sign == 1)
                dif += sign * aliceValues[order[i]];
            else
                dif += sign * bobValues[order[i]];
        }
        if (dif > 0) return 1;
        else if (dif < 0) return -1;
        return 0;
    }
};